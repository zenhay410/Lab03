#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <array>

class Pentagon : public Figure {
private:
    std::array<std::pair<double, double>, 5> verts;
    void checkVerts() const;
public:
    Pentagon() = default;
    Pentagon(const std::array<std::pair<double, double>, 5>& v);
    double calcArea() const override;
    std::pair<double, double> calcCenter() const override;
    void printVerts(std::ostream& os) const override;
    void readInput(std::istream& is) override;
};

#endif