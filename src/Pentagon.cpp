#include "Pentagon.h"
#include <cmath>
#include <stdexcept>

Pentagon::Pentagon(const std::array<std::pair<double, double>, 5>& v) : verts(v) {
    checkVerts();
}

void Pentagon::checkVerts() const {
    if (verts.size() != 5) {
        throw std::invalid_argument("need 5 verts");
    }
}

double Pentagon::calcArea() const {
    double res = 0.0;
    int n = verts.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        res += verts[i].first * verts[j].second;
        res -= verts[j].first * verts[i].second;
    }
    return std::abs(res) / 2.0;
}

std::pair<double, double> Pentagon::calcCenter() const {
    double x = 0.0, y = 0.0;
    for (const auto& v : verts) {
        x += v.first;
        y += v.second;
    }
    return {x / 5.0, y / 5.0};
}

void Pentagon::printVerts(std::ostream& os) const {
    for (size_t i = 0; i < verts.size(); ++i) {
        os << "(" << verts[i].first << ", " << verts[i].second << ")";
        if (i < verts.size() - 1) os << " ";
    }
}

void Pentagon::readInput(std::istream& is) {
    for (auto& v : verts) {
        is >> v.first >> v.second;
    }
    checkVerts();
}