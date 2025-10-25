#include <gtest/gtest.h>
#include "Trapeze.h"
#include "Rhombus.h"
#include "Pentagon.h"

TEST(TrapezeTest, Area) {
    std::array<std::pair<double, double>, 4> v = {
        std::make_pair(0.0, 0.0),
        std::make_pair(6.0, 0.0),
        std::make_pair(4.0, 3.0),
        std::make_pair(2.0, 3.0)
    };
    Trapeze t(v);
    double a = t.calcArea();
    EXPECT_NEAR(a, 12.0, 1e-6);
}

TEST(RhombusTest, Area) {
    std::array<std::pair<double, double>, 4> v = {
        std::make_pair(0.0, 3.0),
        std::make_pair(2.0, 0.0),
        std::make_pair(0.0, -3.0),
        std::make_pair(-2.0, 0.0)
    };
    Rhombus r(v);
    double a = r.calcArea();
    EXPECT_NEAR(a, 12.0, 1e-6);
}

TEST(PentagonTest, Area) {
    std::array<std::pair<double, double>, 5> v = {
        std::make_pair(0.0, 2.0),
        std::make_pair(1.9, 0.6),
        std::make_pair(1.2, -1.6),
        std::make_pair(-1.2, -1.6),
        std::make_pair(-1.9, 0.6)
    };
    Pentagon p(v);
    double a = p.calcArea();
    EXPECT_GT(a, 0.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}