#pragma once
#include <iostream>
#include <algorithm>
#include "Point.hpp"

template <Coordinate T>
class Figure {
public:
    Figure(): n(0), _vertices(nullptr) {};

    virtual Point<T> getCenter() const {
        double ax = 0, ay = 0;
        for(int i = 0; i < n; ++i) {
            ax += _vertices[i].x;
            ay += _vertices[i].y;
        }
        return Point<T>(ax / n, ay / n);
    };

    virtual double getArea() const {
        double amount = 0;
        for (size_t i = 0, j = n - 1; i < n; j = i++) {
            amount += _vertices[j].x * _vertices[i].y - _vertices[j].y * _vertices[i].x;
        }
        return 0.5 * std::abs(amount);
    };

    explicit virtual operator double() const {
        return getArea();
    };

    template <Coordinate U>
    friend std::istream& operator>>(std::istream& inputStream, Figure<U>& figure);
    template <Coordinate U>
    friend std::ostream& operator<<(std::ostream& outputStream, const Figure<U>& figure);

    bool Validate() {
        this->SortVertices();
        if (n < 3) return false;
        double random_side = _vertices[0].LenghtToPoint(_vertices[1]);
        if (std::abs(random_side) < EPS) return false;
        for(int i = 0; i < n; ++i) {
            if (std::abs(_vertices[i].LenghtToPoint(_vertices[(i + 1) % n]) - random_side) > EPS) return false; 
        }
        if (_vertices[0].LenghtToPoint(_vertices[2]) < EPS || _vertices[1].LenghtToPoint(_vertices[3]) < EPS) return false;
        return true;
    }

    void SortVertices() {
        Point<T> c = getCenter();
        auto comp = [c](const Point<T>& A, const Point<T>& B) {
            double aA = std::atan2(A.y - c.y, A.x - c.x);
            double aB = std::atan2(B.y - c.y, B.x - c.x);
            if(std::abs(aA-aB) > EPS) return aA < aB; //при равенстве углов сортируем по радиусу
            double rA = (A.x - c.x)*(A.x - c.x) + (A.y - c.y)*(A.y - c.y);
            double rB = (B.x - c.x)*(B.x - c.x) + (B.y - c.y)*(B.y - c.y);
            return rA < rB;
        };
        std::sort(_vertices.get(), _vertices.get() + n, comp);
    }

    virtual ~Figure() {
        _vertices = nullptr;
    }

protected:
    size_t n;
    std::unique_ptr<Point<T>[]> _vertices;
};

template <Coordinate T>
std::istream& operator>>(std::istream& inputStream, Figure<T>& figure) {
    if (figure.n == 0 || !figure._vertices) return inputStream;
    for (size_t i = 0; i < figure.n; ++i) {
        inputStream >> figure._vertices[i];
    }
    if (!figure.Validate()) throw std::invalid_argument("Wrong points!");
    return inputStream;
}

template <Coordinate T>
std::ostream& operator<<(std::ostream& outputStream, const Figure<T>& figure) {
    if (figure.n == 0 || !figure._vertices) return outputStream;
    for (size_t i = 0; i < figure.n; ++i) {
        outputStream << figure._vertices[i];
    }
    return outputStream;
}
