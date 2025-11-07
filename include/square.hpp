#pragma once
#include <iostream>

#include "Figure.hpp"

template <Coordinate T>
class Square: public Figure<T> {
public: 
    Square() {
        this->n = 4;
        this->_vertices = std::make_unique<Point<T>[]>(this->n);
    };

    Square(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) {
        this->n = 4;
        this->_vertices = std::make_unique<Point<T>[]>(this->n);
        this->_vertices[0] = p1;
        this->_vertices[1] = p2;
        this->_vertices[2] = p3;
        this->_vertices[3] = p4;

        if (!this->Validate()) throw std::invalid_argument("Wrong Square!"); 
    }

    Square(const Square& other) {
        this->n = other.n;
        this->_vertices = std::make_unique<Point<T>[]>(this->n);

        for(size_t i = 0; i < this->n; ++i) {
            this->_vertices[i] = other._vertices[i];
        }
    }

    Square(Square&& other) noexcept {
        this->n = other.n;
        this->_vertices = std::move(other._vertices);;

        other.n = 0;
        other._vertices = nullptr;
    };

    Square<T>& operator=(const Square& other) {
        if (this != &other) {
            Square tmp(other);
            std::swap(this->n, tmp.n);
            std::swap(this->_vertices, tmp._vertices);
        }
        return *this;
    };

    Square<T>& operator=(Square&& other) noexcept {
        if (this != &other) {
            this->n = other.n;
            this->_vertices = std::move(other._vertices);
            other.n = 0;
            other._vertices = nullptr;
        }
        return *this;
    };

    bool operator==(const Square<T>& other) const {
        if (this->n != other.n) return false;
        for(size_t i = 0; i < this->n; ++i) {
            if (this->_vertices[i] != other._vertices[i]) return false;
        }
        return true;
    };

    ~Square() = default;
};
