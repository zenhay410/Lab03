#include <iostream>
#include <vector>
#include <memory>
#include "Figure.h"
#include "Trapeze.h"
#include "Rhombus.h"
#include "Pentagon.h"

void showDemo() {
    std::array<std::pair<double, double>, 4> trapVerts = {
        std::make_pair(0.0, 0.0),
        std::make_pair(6.0, 0.0),
        std::make_pair(4.0, 3.0),
        std::make_pair(2.0, 3.0)
    };
    
    std::array<std::pair<double, double>, 4> rhombVerts = {
        std::make_pair(0.0, 3.0),
        std::make_pair(2.0, 0.0),
        std::make_pair(0.0, -3.0),
        std::make_pair(-2.0, 0.0)
    };
    
    std::array<std::pair<double, double>, 5> pentVerts = {
        std::make_pair(0.0, 2.0),
        std::make_pair(1.9, 0.6),
        std::make_pair(1.2, -1.6),
        std::make_pair(-1.2, -1.6),
        std::make_pair(-1.9, 0.6)
    };
    
    try {
        Trapeze t(trapVerts);
        Rhombus r(rhombVerts);
        Pentagon p(pentVerts);
        
        std::cout << "Demo Trapeze: " << t << " | Area: " << t.calcArea() << "\n";
        std::cout << "Demo Rhombus: " << r << " | Area: " << r.calcArea() << "\n";
        std::cout << "Demo Pentagon: " << p << " | Area: " << p.calcArea() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Demo error: " << e.what() << "\n";
    }
}

int main() {
    std::vector<FigurePtr> figs;
    int ch;
    
    std::cout << "Show demo data? (1-yes, 0-no): ";
    std::cin >> ch;
    if (ch == 1) {
        showDemo();
    }
    
    std::cout << "Add figures (1-Trapeze, 2-Rhombus, 3-Pentagon, 0-Done):\n";
    
    while (true) {
        std::cout << "Choice: ";
        std::cin >> ch;
        
        if (ch == 0) break;
        
        FigurePtr f;
        try {
            if (ch == 1) {
                f = std::make_shared<Trapeze>();
                std::cout << "Enter 4 points (x y): ";
            } else if (ch == 2) {
                f = std::make_shared<Rhombus>();
                std::cout << "Enter 4 points (x y): ";
            } else if (ch == 3) {
                f = std::make_shared<Pentagon>();
                std::cout << "Enter 5 points (x y): ";
            } else {
                std::cout << "Bad choice\n";
                continue;
            }
            
            std::cin >> *f;
            figs.push_back(f);
            std::cout << "Added\n";
            
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    
    std::cout << "\n--- Results ---\n";
    double total = 0.0;
    for (size_t i = 0; i < figs.size(); ++i) {
        std::cout << "Fig " << i + 1 << ": ";
        std::cout << *figs[i] << " | ";
        
        auto c = figs[i]->calcCenter();
        std::cout << "Center(" << c.first << "," << c.second << ") | ";
        
        double a = static_cast<double>(*figs[i]);
        std::cout << "Area:" << a << "\n";
        total += a;
    }
    
    if (!figs.empty()) {
        std::cout << "Total area: " << total << "\n";
    } else {
        std::cout << "No figures\n";
    }
    
    return 0;
}