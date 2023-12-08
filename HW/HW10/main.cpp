#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

#include "image.h"
#include "priority_queue.h"

// ===================================================================================================

// distance field method functions
double NaiveDistanceFieldMethod(Image<Color> &input,
                                Image<DistancePixel> &distance_image);
double ImprovedDistanceFieldMethod(const Image<Color> &input,
                                   Image<DistancePixel> &distance_image);
double FastMarchingMethod(Image<Color> &input,
                          Image<DistancePixel> &distance_image);

// visualization style helper functions
Color Rainbow(double distance, double max_distance);
Color GreyBands(double distance, double max_distance, int num_bands);
// Calculates distance

double CalculateDistance(int i, int j, int k, int l);

void updateDistance(Image<Color> &input,
                    Image<DistancePixel> &distance_image, std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> &pq, int bx, int by, int nx, int ny, int WIDTH,
                    int HEIGHT);

// ===================================================================================================

int main(int argc, char *argv[])
{
  if (argc != 5)
  {
    std::cerr
        << "Usage: " << argv[0]
        << " input.ppm output.ppm distance_field_method visualization_style"
        << std::endl;
    exit(1);
  }

  // open the input image
  Image<Color> input;
  if (!input.Load(argv[1]))
  {
    std::cerr << "ERROR: Cannot open input file: " << argv[1] << std::endl;
    exit(1);
  }

  // a place to write the distance values
  Image<DistancePixel> distance_image;
  distance_image.Allocate(input.Width(), input.Height());

  // calculate the distance field (each function returns the maximum distance
  // value)
  double max_distance = 0;

  if (std::string(argv[3]) == std::string("naive_method"))
  {
    max_distance = NaiveDistanceFieldMethod(input, distance_image);
  }
  else if (std::string(argv[3]) == std::string("improved_method"))
  {
    max_distance = ImprovedDistanceFieldMethod(input, distance_image);
  }
  else if (std::string(argv[3]) == std::string("pq_with_map"))
  {
    max_distance = FastMarchingMethod(input, distance_image);
  }
  else if (std::string(argv[3]) == std::string("pq_with_hash_table"))
  {
    // EXTRA CREDIT: implement FastMarchingMethod with a hash table
  }
  else
  {
    std::cerr << "ERROR: Unknown distance field method: " << argv[3]
              << std::endl;
    exit(1);
  }

  // convert distance values to a visualization
  Image<Color> output;
  output.Allocate(input.Width(), input.Height());
  for (int i = 0; i < input.Width(); i++)
  {
    for (int j = 0; j < input.Height(); j++)
    {
      double v = distance_image.GetPixel(i, j).getValue();
      if (std::string(argv[4]) == std::string("greyscale"))
      {
        output.SetPixel(i, j, GreyBands(v, max_distance * 1.01, 1));
      }
      else if (std::string(argv[4]) == std::string("grey_bands"))
      {
        output.SetPixel(i, j, GreyBands(v, max_distance, 4));
      }
      else if (std::string(argv[4]) == std::string("rainbow"))
      {
        output.SetPixel(i, j, Rainbow(v, max_distance));
      }
      else
      {
        // EXTRA CREDIT: create other visualizations
        std::cerr << "ERROR: Unknown visualization style" << std::endl;
        exit(0);
      }
    }
  }
  // save output
  if (!output.Save(argv[2]))
  {
    std::cerr << "ERROR: Cannot save to output file: " << argv[2] << std::endl;
    exit(1);
  }

  return 0;
}

// ===================================================================================================

double NaiveDistanceFieldMethod(Image<Color> &input,
                                Image<DistancePixel> &distance_image)
{
  int w = input.Width();
  int h = input.Height();
  // return the maximum distance value
  double answer = 0;
  // loop over the pixels in the input image
  for (int i = 0; i < w; i++)
  {
    for (int j = 0; j < h; j++)
    {
      double closest = -1;
      // loop over all other pixels in the input image
      for (int i2 = 0; i2 < w; i2++)
      {
        for (int j2 = 0; j2 < h; j2++)
        {
          const Color &c = input.GetPixel(i2, j2);
          // skip all pixels that are not black
          if (!c.isBlack())
            continue;
          // calculate the distance between the two pixels
          double distance = sqrt((i - i2) * (i - i2) + (j - j2) * (j - j2));
          // store the closest distance to a black pixel
          if (closest < 0 || distance < closest)
          {
            closest = distance;
          }
        }
      }
      assert(closest >= 0);
      answer = std::max(answer, closest);
      // save the data to the distance image
      DistancePixel &p = distance_image.GetPixel(i, j);
      p.setValue(closest);
    }
  }
  return answer;
}

float distanceToCircle(float cx, float cy, float radius, float px, float py)
{
  float dx = px - cx;
  float dy = py - cy;
  return std::sqrt(dx * dx + dy * dy) - radius;
}

// Function to compute the distance field using the improved method
// Input: Image<Color> input - input image
//        Image<double>& distance_image - output distance field image
// Output: double - maximum distance value
double ImprovedDistanceFieldMethod(const Image<Color> &input,
                                   Image<DistancePixel> &distance_image)
{

  int width = input.Width();
  int height = input.Height();

  // Allocate memory for distance field image
  distance_image.Allocate(width, height);

  // Initialize distance field values to positive infinity
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      distance_image.GetPixel(i, j).setValue(
          std::numeric_limits<double>::infinity());
    }
  }

  // Compute distance field using improved method
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      if (input.GetPixel(i, j).r == 0)
      {
        // Distance to object is 0 for foreground pixels
        distance_image.GetPixel(i, j).setValue(0.0);
      }
      else
      {
        // Compute distance to object for background pixels
        double minDistance = -1;
        for (int k = 0; k <= width - 1; k++)
        {
          for (int l = 0; l <= height - 1; l++)
          {
            // Ignore current pixel and color pixals
            if (k != i && l != j && input.GetPixel(k, l).isBlack())
            {
              double distance = CalculateDistance(i, j, k, l);

              if (minDistance < 0 || distance < minDistance)
              {
                minDistance = distance;
              }
            }
          }
        }
        distance_image.GetPixel(i, j).setValue(minDistance);
      }
    }
  }

  // Find maximum distance value
  double max_distance = 0.0;
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      double distance = distance_image.GetPixel(i, j).getValue();
      if (distance > max_distance)
      {
        max_distance = distance;
      }
    }
  }

  return max_distance;
}
double FastMarchingMethod(Image<Color> &input,
                          Image<DistancePixel> &distance_image)
{
  const int WIDTH = input.Width();
  const int HEIGHT = input.Height();
  const double inf = std::numeric_limits<double>::infinity();

  // Create a priority queue of pixels ordered by distance
  DistancePixel_PriorityQueue
      pq;

  // Initialize the output distance array with large distance values
  for (int i = 0; i < WIDTH; ++i)
  {
    for (int j = 0; j < HEIGHT; ++j)
    {
      distance_image.GetPixel(i, j).setX(i);
      distance_image.GetPixel(i, j).setY(j);
      if (input.GetPixel(i, j).isBlack())
      {
        distance_image.GetPixel(i, j).setValue(0);
        pq.push(&distance_image.GetPixel(i, j));
      }
      else
      {
        distance_image.GetPixel(i, j).setValue(inf);
      }
    }
  }

  // Process pixels in the priority queue
  while (!pq.empty())
  {
    // Pop the pixel with the smallest distance value
    const DistancePixel *pixel = pq.top();
    pq.pop();

    double distance = pixel->getValue();
    // Update the distance values of neighboring pixels
    for (int dx = -1; dx <= 1; ++dx)
    {
      for (int dy = -1; dy <= 1; ++dy)
      {
        if (dx == 0 && dy == 0)
        {
          continue;
        }
        int x = pixel->getX() + dx;
        int y = pixel->getY() + dy;

        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || input.GetPixel(x, y).isBlack())
        {
          continue;
        }
        double new_distance = distance + std::sqrt(dx * dx + dy * dy);
        if (new_distance < distance_image.GetPixel(x, y).getValue())
        {
          distance_image.GetPixel(x, y).setValue(new_distance);
          pq.push(&distance_image.GetPixel(x, y));
        }
      }
    }
  }

  // Find the maximum distance value computed
  double max_distance = 0;
  for (int i = 0; i < WIDTH; ++i)
  {
    for (int j = 0; j < HEIGHT; ++j)
    {
      max_distance = std::max(max_distance, distance_image.GetPixel(i, j).getValue());
    }
  }
  return max_distance;
}
double CalculateDistance(int i, int j, int k, int l)
{
  return sqrt((i - k) * (i - k) + (j - l) * (j - l));
}

Color Rainbow(double distance, double max_distance)
{
  Color answer;
  if (distance < 0.001)
  {
    // black
    answer.r = 0;
    answer.g = 0;
    answer.b = 0;
  }
  else if (distance < 0.2 * max_distance)
  {
    // blue -> cyan
    double tmp = distance * 5.0 / max_distance;
    answer.r = 0;
    answer.g = tmp * 255;
    answer.b = 255;
  }
  else if (distance < 0.4 * max_distance)
  {
    // cyan -> green
    double tmp = (distance - 0.2 * max_distance) * 5.0 / max_distance;
    answer.r = 0;
    answer.g = 255;
    answer.b = (1 - tmp * tmp) * 255;
  }
  else if (distance < 0.6 * max_distance)
  {
    // green -> yellow
    double tmp = (distance - 0.4 * max_distance) * 5.0 / max_distance;
    answer.r = sqrt(tmp) * 255;
    answer.g = 255;
    answer.b = 0;
  }
  else if (distance < 0.8 * max_distance)
  {
    // yellow -> red
    double tmp = (distance - 0.6 * max_distance) * 5.0 / max_distance;
    answer.r = 255;
    answer.g = (1 - tmp * tmp) * 255;
    answer.b = 0;
  }
  else if (distance < max_distance)
  {
    // red -> white
    double tmp = (distance - 0.8 * max_distance) * 5.0 / max_distance;
    answer.r = 255;
    answer.g = tmp * 255;
    answer.b = tmp * 255;
  }
  else
  {
    // white
    answer.r = answer.g = answer.b = 255;
  }
  return answer;
}

Color GreyBands(double distance, double max_value, int num_bands)
{
  Color answer;
  if (distance < 0.001)
  {
    // red
    answer.r = 255;
    answer.g = 0;
    answer.b = 0;
  }
  else
  {
    // shades of grey
    answer.r = answer.g = answer.b =
        int(num_bands * 256 * distance / double(max_value)) % 256;
  }
  return answer;
}

// ===================================================================================================
