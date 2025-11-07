#pragma once
#include <iostream>
#include <concepts>
#include <memory>
#include <assert.h>

template <class T>
concept Arrayable = std::is_default_constructible<T>::value;

template <Arrayable T>
class Array {
public:
    Array() : _size(0), _array{nullptr} {};

    explicit Array(size_t n) : _size(n), _array(std::shared_ptr<T[]>(new T[n]())) {}

    Array(const std::initializer_list<T> &t)
    {
        _array = std::shared_ptr<T[]>(new T[t.size()]);
        size_t i{0};
        for (auto &c : t)
            _array[i++] = c;
        _size = t.size();
    }

    Array(const Array &other)
    {
        _size = other._size;
        _array = std::shared_ptr<T[]>(new T[_size]);

        for (size_t i{0}; i < _size; ++i)
            _array[i] = other._array[i];
    }

    Array(Array &&other) noexcept
    {
        _size = other._size;
        _array = other._array;

        other._size = 0;
        other._array = nullptr;
    }

    T& operator[](size_t index){
        assert(index<_size);
        return _array[index];
    }

    size_t size() const {
        return _size;
    }

    double GlobalArea() const {
        double amount = 0;
        for(int i = 0; i < _size; ++i) if (_array[i]) amount += _array[i]->getArea();
        return amount;
    }

    void Remove(size_t index) {
        if (index + 1 > _size) throw std::out_of_range("Index out of range!");
        delete _array[index];
        for (int i = index + 1; i < _size; ++i) {
            _array[i - 1] = _array[i];
        }
        _array[_size-- - 1] = nullptr;
    }

    ~Array() noexcept {};

private:
    size_t _size;
    std::shared_ptr<T[]> _array;
};
