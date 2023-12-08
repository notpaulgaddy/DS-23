// polygons.h

// #include <iostream>
// #include <vector>
// #include "utilities.h"

// class Polygon {
// public:
//     Polygon(const std::string &name, const std::vector<Point> &points) : name_(name), points_(points) {}

//     const std::string& getName() const { return name_; }

//     bool HasAllEqualSides() const {
//         double d = DistanceBetween(points_[0], points_[1]);
//         for (unsigned int i = 1; i < points_.size(); i++) {
//             if (!EqualSides(d, DistanceBetween(points_[i], points_[(i + 1) % points_.size()]))) return false;
//         }
//         return true;
//     }

//     bool HasAllEqualAngles() const {
//         double a = Angle(points_[points_.size() - 1], points_[0], points_[1]);
//         for (unsigned int i = 1; i < points_.size(); i++) {
//             if (!EqualAngles(a, Angle(points_[(i - 1) % points_.size()], points_[i], points_[(i + 1) % points_.size()]))) return false;
//         }
//         return true;
//     }

// protected:  
//     std::string name_;
//     std::vector<Point> points_;
// };

// class Triangle : public Polygon { /* ... */ };
// class IsoscelesTriangle : public Triangle { /* ... */ };
// class EquilateralTriangle : public IsoscelesTriangle { /* ... */ };
// class Quadrilateral : public Polygon { /* ... */ };
// class Rectangle : public Quadrilateral { /* ... */ };
// class Square : public Rectangle { /* ... */ };
