#ifndef TRAPEZE_H
#define TRAPEZE_H

#include "Figure.h"
#include <array>

class Trapeze : public Figure {
private:
    std::array<std::pair<double, double>, 4> verts;
    void checkVerts() const;
public:
    Trapeze() = default;
    Trapeze(const std::array<std::pair<double, double>, 4>& v);
    double calcArea() const override;
    std::pair<double, double> calcCenter() const override;
    void printVerts(std::ostream& os) const override;
    void readInput(std::istream& is) override;
};

#endif