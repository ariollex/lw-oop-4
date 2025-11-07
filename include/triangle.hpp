#pragma once
#include <iostream>

#include "Figure.hpp"

template <Coordinate T>
class Triangle: public Figure<T> {
public: 
    Triangle() {
        this->n = 3;
        this->_vertices = std::make_unique<Point<T>[]>(this->n);
    };

    Triangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) {
        this->n = 3;
        this->_vertices = std::make_unique<Point<T>[]>(this->n);
        this->_vertices[0] = p1;
        this->_vertices[1] = p2;
        this->_vertices[2] = p3;

        if (!this->Validate()) throw std::invalid_argument("Wrong Triangle!"); 
    }

    Triangle(const Triangle& other) {
        this->n = other.n;
        this->_vertices = std::make_unique<Point<T>[]>(this->n);

        for(size_t i = 0; i < this->n; ++i) {
            this->_vertices[i] = other._vertices[i];
        }
    }

    Triangle(Triangle&& other) noexcept {
        this->n = other.n;
        this->_vertices = std::move(other._vertices);;

        other.n = 0;
        other._vertices = nullptr;
    };

    Triangle<T>& operator=(const Triangle& other) {
        if (this != &other) {
            Triangle tmp(other);
            std::swap(this->n, tmp.n);
            std::swap(this->_vertices, tmp._vertices);
        }
        return *this;
    };

    Triangle<T>& operator=(Triangle&& other) noexcept {
        if (this != &other) {
            this->n = other.n;
            this->_vertices = std::move(other._vertices);
            other.n = 0;
            other._vertices = nullptr;
        }
        return *this;
    };

    bool operator==(const Triangle<T>& other) const {
        if (this->n != other.n) return false;
        for(size_t i = 0; i < this->n; ++i) {
            if (this->_vertices[i] != other._vertices[i]) return false;
        }
        return true;
    };

    ~Triangle() = default;
};
