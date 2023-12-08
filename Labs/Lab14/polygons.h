// #ifndef _POLYGONS_H_
// #define _POLYGONS_H_

// #include <vector>
// #include "utilities.h"

// class Polygon {
// public:
//     Polygon(const std::string &n, const std::vector<Point> &pts) : name(n), points(pts) {}
//     virtual ~Polygon() {}
//     const std::string& getName() const { return name; }
//     bool HasAllEqualSides() const;

// protected:
//     std::string name;
//     std::vector<Point> points;
// };

// class Triangle : public Polygon {
// public:
//     Triangle(const std::string &n, const std::vector<Point> &pts);
// };

// class IsoscelesTriangle : public Triangle {
// public:
//     IsoscelesTriangle(const std::string &n, const std::vector<Point> &pts);
// };

// class EquilateralTriangle : public IsoscelesTriangle {
// public:
//     EquilateralTriangle(const std::string &n, const std::vector<Point> &pts);
// };

// class Quadrilateral : public Polygon {
// public:
//     Quadrilateral(const std::string &n, const std::vector<Point> &pts);
// };

// class Rectangle : public Quadrilateral {
// public:
//     Rectangle(const std::string &n, const std::vector<Point> &pts);
// };

// class Square : public Rectangle {
// public:
//     Square(const std::string &n, const std::vector<Point> &pts);
// };

// #endif // _POLYGONS_H_

#ifndef _POLYGONS_H_
#define _POLYGONS_H_

#include "utilities.h"
#include <vector>
#include <string>

class Polygon {
public:
  Polygon(const std::string& name, const std::vector<Point>& points);
  virtual ~Polygon();

  const std::string& getName() const;
  bool HasAllEqualSides() const;

protected:
  std::string name_;
  std::vector<Point> points_;
};

class Quadrilateral : public Polygon {
public:
  Quadrilateral(const std::string& name, const std::vector<Point>& points);
};

class Rectangle : public Quadrilateral {
public:
  Rectangle(const std::string& name, const std::vector<Point>& points);
};

class Square : public Rectangle {
public:
  Square(const std::string& name, const std::vector<Point>& points);
};

class Triangle : public Polygon {
public:
  Triangle(const std::string& name, const std::vector<Point>& points);
};

class IsoscelesTriangle : public Triangle {
public:
  IsoscelesTriangle(const std::string& name, const std::vector<Point>& points);
};

class EquilateralTriangle : public IsoscelesTriangle {
public:
  EquilateralTriangle(const std::string& name, const std::vector<Point>& points);
};

#endif // _POLYGONS_H_
