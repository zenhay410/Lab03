#include "Rhombus.h"
#include <cmath>
#include <stdexcept>

Rhombus::Rhombus(const std::array<std::pair<double, double>, 4>& v) : verts(v) {
    checkVerts();
}

void Rhombus::checkVerts() const {
    if (verts.size() != 4) {
        throw std::invalid_argument("need 4 verts");
    }
}

double Rhombus::calcArea() const {
    double res = 0.0;
    int n = verts.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        res += verts[i].first * verts[j].second;
        res -= verts[j].first * verts[i].second;
    }
    return std::abs(res) / 2.0;
}

std::pair<double, double> Rhombus::calcCenter() const {
    double x = 0.0, y = 0.0;
    for (const auto& v : verts) {
        x += v.first;
        y += v.second;
    }
    return {x / 4.0, y / 4.0};
}

void Rhombus::printVerts(std::ostream& os) const {
    for (size_t i = 0; i < verts.size(); ++i) {
        os << "(" << verts[i].first << ", " << verts[i].second << ")";
        if (i < verts.size() - 1) os << " ";
    }
}

void Rhombus::readInput(std::istream& is) {
    for (auto& v : verts) {
        is >> v.first >> v.second;
    }
    checkVerts();
}