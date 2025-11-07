#pragma once
#include <iostream>
#include <cmath>
#define EPS 1e-6

template <class T>
concept Coordinate = std::is_scalar<T>::value;

template <Coordinate T>
class Point {
public:
    Point(): x(0), y(0) {};
    Point(T cx, T cy): x(cx), y(cy) {};

    bool operator==(const Point& other) const {
        return std::abs(x - other.x) < EPS && std::abs(y - other.y) < EPS;
    };

    bool operator!=(const Point& other) const {
        return !(*this == other);
    };

    double LenghtToPoint(const Point& other) const {
        return std::hypot(x - other.x, y - other.y);
    };

    T x, y;
};

template <Coordinate T>
std::istream& operator>>(std::istream& inputStream, Point<T>& p) {
    inputStream >> p.x >> p.y;
    return inputStream;
}

template <Coordinate T>
std::ostream& operator<<(std::ostream& outputStream, const Point<T>& p) {
    outputStream << "{" << p.x << " " << p.y << "}";
    return outputStream;
}
