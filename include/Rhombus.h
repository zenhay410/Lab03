#define RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"
#include <array>

class Rhombus : public Figure {
private:
    std::array<std::pair<double, double>, 4> verts;
    void checkVerts() const;
public:
    Rhombus() = default;
    Rhombus(const std::array<std::pair<double, double>, 4>& v);
    double calcArea() const override;
    std::pair<double, double> calcCenter() const override;
    void printVerts(std::ostream& os) const override;
    void readInput(std::istream& is) override;
};

#endif
