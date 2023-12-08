HOMEWORK 9: DISTANCE FIELDS & FAST MARCHING METHOD


NAME: Paul Gaddy


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

Priority Queue Lecture
https://cplusplus.com/reference/cassert/assert/

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  17



NAIVE ALGORITHM:

The given code implements the naive algorithm for computing distance field of a binary image. It computes the distance of each pixel in the input binary image to its closest black (foreground) pixel, and stores this value in a distance image.

The algorithm uses three nested loops to accomplish this task. The outer two loops iterate over each pixel in the input image, while the innermost loop searches for the closest black pixel by iterating over all other pixels in the image. The distance between two pixels is calculated using Euclidean distance formula, and the minimum distance to a black pixel is stored in the closest variable. The maximum distance value found during this process is returned as the answer.

Order Notation:

The time complexity of the algorithm is O(N^4), where N is the size of the input image. This is because there are three nested loops, each iterating over the entire image of N pixels, resulting in N^3 iterations. The calculation of Euclidean distance using sqrt function adds an additional O(1) time complexity to each iteration.

The space complexity of the algorithm is O(N^2), which is the size of the distance image that is being constructed.

Timing Experiment Data:

The actual running time of the algorithm depends on various factors such as the size of the input image, the number of black pixels in the image, and the computational power of the machine running the code. A benchmark test on a given machine can provide more accurate timing data.

Discussion:

The naive algorithm implemented in the given code has high time complexity, making it inefficient for large images. The algorithm calculates distances to all black pixels in the image for each pixel in the image, resulting in a large number of unnecessary calculations. There are more efficient algorithms available for computing distance fields, such as the fast marching method, which take advantage of the local structure of the image to reduce the number of distance calculations required. These algorithms can significantly improve the performance and scalability of the distance field computation.



IMPROVED ALGORITHM:

Order Notation:

The double for loop in line 22 has a complexity of O(n^4) bc to the four levels of nested loops. Along with this, the loop in line 33 has a complexity of O(n^2). Therefore, the overall complexity of the ImprovedDistanceFieldMethod function is O(n^4 + n^2) or O(n^4).

Timing Experiment Data:

To accurately determine the performance of this function, experiments could be conducted with images of various sizes and complexities, and the time taken to process each image could be recorded. The data can then be plotted on a graph to observe the trend in the function's performance as the size of the image increases.

Discussion:

The ImprovedDistanceFieldMethod function is an optimized version of the NaiveDistanceFieldMethod function. It uses a more efficient algorithm to calculate the distance field by iterating only over background pixels and ignoring foreground pixels, thus reducing the number of iterations. This results in a significant improvement in performance compared to the NaiveDistanceFieldMethod function.

The improved method also initializes the distance field values to positive infinity and only updates them if a closer distance is found, ensuring that the minimum distance to a black pixel is always stored. This eliminates the need for the assert statement used in the NaiveDistanceFieldMethod function.

Overall, the ImprovedDistanceFieldMethod function is a more efficient and optimized approach to computing the distance field for an image.



FAST MARCHING METHOD (with a map):

Order Notation:
O(N log N), where N is the number of pixels in the input image. This is because the function uses a priority queue, which has a 
logarithmic time complexity for inserting and removing elements, and it also iterates over each pixel once.
Timing Experiment Data:
It would depend on the size of the input image and the hardware used for the experiments. However, in general, the Fast Marching 
Method with a map should be faster than the original Improved Distance Field Method and the Double Improved Distance Field Method. 
This is because it has a lower time complexity and it does not require nested loops to compute the distance field.
Discussion:
The improved fast marching method is a variation of the traditional fast marching method that uses a hash 
map to keep track of the pixels in the priority queue, which can reduce the time complexity of the algorithm.



DISTANCE FIELD VISUALIZATIONS FOR EXTRA CREDIT:




FAST MARCHING METHOD (with a hash table) FOR EXTRA CREDIT:

Order Notation:

Timing Experiment Data:

Discussion:



MISC. COMMENTS TO GRADER:  
Optional, please be concise!






