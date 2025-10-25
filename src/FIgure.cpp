#include "Figure.h"

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.printVerts(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.readInput(is);
    return is;
}