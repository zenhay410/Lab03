#define FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <memory>

class Figure {
public:
    virtual ~Figure() = default;
    virtual double calcArea() const = 0;
    virtual std::pair<double, double> calcCenter() const = 0;
    virtual void printVerts(std::ostream& os) const = 0;
    virtual void readInput(std::istream& is) = 0;
    virtual operator double() const { return calcArea(); }
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
};

using FigurePtr = std::shared_ptr<Figure>;

#endif
