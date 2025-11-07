#include <iostream>
#include "Array.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "octagon.hpp"

int main() {
    Array<Figure<double>*> arr(3);

    arr[0] = new Triangle<double>();
    std::cin >> *arr[0];

    arr[1] = new Square<double>();
    std::cin >> *arr[1];

    arr[2] = new Octagon<double>();
    std::cin >> *arr[2];

    std::cout << "Area and center:\n";
    for (int i = 0; i < arr.size(); ++i) {
        if (!arr[i]) continue;
        std::cout << "=================\n";
        std::cout << *arr[i] << '\n';
        std::cout << arr[i]->getArea() << '\n';
        std::cout << arr[i]->getCenter() << '\n';
        std::cout << "=================\n";
    }

    while (arr.size() > 0) {
        arr.Remove(0);
    }

    return 0;
}

// 0 0  1 0  0.5 0.8660254038 , площадь 0.4330127019, центр {0.5 0.288675134}
//0 1  1 0  0 -1  -1 0, площадь 2, центр {0, 0}
// 1 0  0.7071067812 0.7071067812  0 1  -0.7071067812 0.7071067812 -1 0  -0.7071067812 -0.7071067812  0 -1  0.7071067812 -0.7071067812, площадь 2.8284271247, центр {0 0}
