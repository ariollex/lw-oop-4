#pragma once
#include <iostream>

#include "Figure.hpp"

template <Coordinate T>
class Octagon: public Figure<T> {
public: 
    Octagon() {
        this->n = 8;
        this->_vertices = std::make_unique<Point<T>[]>(this->n);
    };

    Octagon(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4, const Point<T>& p5, const Point<T>& p6, const Point<T>& p7, const Point<T>& p8) {
        this->n = 8;
        this->_vertices = std::make_unique<Point<T>[]>(this->n);
        this->_vertices[0] = p1;
        this->_vertices[1] = p2;
        this->_vertices[2] = p3;
        this->_vertices[3] = p4;
        this->_vertices[4] = p5;
        this->_vertices[5] = p6;
        this->_vertices[6] = p7;
        this->_vertices[7] = p8;

        if (!this->Validate()) throw std::invalid_argument("Wrong Octagon!"); 
    }

    Octagon(const Octagon& other) {
        this->n = other.n;
        this->_vertices = std::make_unique<Point<T>[]>(this->n);

        for(size_t i = 0; i < this->n; ++i) {
            this->_vertices[i] = other._vertices[i];
        }
    }

    Octagon(Octagon&& other) noexcept {
        this->n = other.n;
        this->_vertices = std::move(other._vertices);;

        other.n = 0;
        other._vertices = nullptr;
    };

    Octagon<T>& operator=(const Octagon& other) {
        if (this != &other) {
            Octagon tmp(other);
            std::swap(this->n, tmp.n);
            std::swap(this->_vertices, tmp._vertices);
        }
        return *this;
    };

    Octagon<T>& operator=(Octagon&& other) noexcept {
        if (this != &other) {
            this->n = other.n;
            this->_vertices = std::move(other._vertices);
            other.n = 0;
            other._vertices = nullptr;
        }
        return *this;
    };

    bool operator==(const Octagon<T>& other) const {
        if (this->n != other.n) return false;
        for(size_t i = 0; i < this->n; ++i) {
            if (this->_vertices[i] != other._vertices[i]) return false;
        }
        return true;
    };

    ~Octagon() = default;
};
