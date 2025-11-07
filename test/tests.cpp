#include <gtest/gtest.h>
#include "../include/Figure.hpp"
#include "../include/square.hpp"
#include "../include/triangle.hpp"
#include "../include/octagon.hpp"
#include <cmath>

using Num = double;
using P =Point<Num>;

TEST(test_01, Triangle_Equilateral)
{
    Triangle<Num> t(P(0,0), P(1,0), P(0.5, 0.8660254037844386));
    EXPECT_NEAR(t.getArea(), std::sqrt(3.0)/4.0, EPS);
    P c = t.getCenter();
    EXPECT_NEAR(c.x, 0.5, EPS);
    EXPECT_NEAR(c.y, 0.2886751345948129, EPS);
    EXPECT_NEAR(static_cast<double>(t), std::sqrt(3.0)/4.0, EPS);
}

TEST(test_02, Triangle_Equilateral_Unsorted)
{
    Triangle<Num> t(P(0.5, 0.8660254037844386), P(0,0), P(1,0));
    EXPECT_NEAR(t.getArea(), std::sqrt(3.0)/4.0, EPS);
    P c = t.getCenter();
    EXPECT_NEAR(c.x, 0.5, EPS);
    EXPECT_NEAR(c.y, 0.2886751345948129, EPS);
    EXPECT_NEAR(static_cast<double>(t), std::sqrt(3.0)/4.0, EPS);
}

TEST(test_03, Wrong_Triangle)
{
    EXPECT_THROW({ Triangle<Num> t(P(0,0), P(1,1), P(2,2)); }, std::invalid_argument);
}

TEST(test_04, Square_Regular)
{
    Square<Num> s(P(-1,-1), P(1,-1), P(1,1), P(-1,1));
    EXPECT_NEAR(s.getArea(), 4.0, EPS);
    P c = s.getCenter();
    EXPECT_NEAR(c.x, 0.0, EPS);
    EXPECT_NEAR(c.y, 0.0, EPS);
    EXPECT_NEAR(static_cast<double>(s), 4.0, EPS);
}

TEST(test_05, Square_Unsorted)
{
    Square<Num> s(P(1,1), P(-1,-1), P(-1,1), P(1,-1));
    EXPECT_NEAR(s.getArea(), 4.0, EPS);
    P c = s.getCenter();
    EXPECT_NEAR(c.x, 0.0, EPS);
    EXPECT_NEAR(c.y, 0.0, EPS);
    EXPECT_NEAR(static_cast<double>(s), 4.0, EPS);
}

TEST(test_06, Wrong_Square)
{
    EXPECT_THROW({
        Square<Num> s(P(0,0), P(2,0), P(2,0), P(0,1));
    }, std::invalid_argument);
}

TEST(test_07, Octagon_Regular)
{
    Octagon<Num> o(
        P( 1, 0),
        P( 0.7071067811865476,  0.7071067811865476),
        P( 0, 1),
        P(-0.7071067811865476,  0.7071067811865476),
        P(-1, 0),
        P(-0.7071067811865476, -0.7071067811865476),
        P( 0,-1),
        P( 0.7071067811865476, -0.7071067811865476)
    );
    EXPECT_NEAR(o.getArea(), 2.8284271247461903, EPS);
    P c = o.getCenter();
    EXPECT_NEAR(c.x, 0.0, EPS);
    EXPECT_NEAR(c.y, 0.0, EPS);
    EXPECT_NEAR(static_cast<double>(o), 2.8284271247461903, EPS);
}

TEST(test_08, Octagon_Regular_Unsorted)
{
    Octagon<Num> o(
        P( 0.7071067811865476,  0.7071067811865476),
        P( 0,-1),
        P(-1, 0),
        P( 1, 0),
        P(-0.7071067811865476,  0.7071067811865476),
        P( 0.7071067811865476, -0.7071067811865476),
        P( 0, 1),
        P(-0.7071067811865476, -0.7071067811865476)
    );
    EXPECT_NEAR(o.getArea(), 2.8284271247461903, EPS);
    P c = o.getCenter();
    EXPECT_NEAR(c.x, 0.0, EPS);
    EXPECT_NEAR(c.y, 0.0, EPS);
    EXPECT_NEAR(static_cast<double>(o), 2.8284271247461903, EPS);
}

TEST(test_09, Wrong_Octagon)
{
    EXPECT_THROW({
        Octagon<Num> o(
            P(0,0), P(1,0), P(1,1), P(0,1),
            P(0,1), P(1,1), P(1,0), P(0,0)
        );
    }, std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
