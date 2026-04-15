/*
 * AI Usage Disclosure:
 * Level: Assisted (The AI provided the structural implementation of the 
 * smart pointer vector and file parsing logic based on assignment specs.)
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>

// Temporary workaround for building without CMake:
#include "Shape.h"
#include "Shape.cpp"

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "\nArea: " << std::fixed << std::setprecision(4) 
                  << shape->getArea() << "\n" << std::endl;
    }
}

int main() {
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Error: Could not open shapes.txt" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        try {
            if (type == "rectangle") {
                double w, h;
                if (ss >> w >> h) {
                    shapes.push_back(std::make_unique<Rectangle>(w, h));
                } else {
                    throw std::runtime_error("Invalid rectangle dimensions");
                }
            } 
            else if (type == "circle") {
                double r;
                if (ss >> r) {
                    shapes.push_back(std::make_unique<Circle>(r));
                } else {
                    throw std::runtime_error("Invalid circle radius");
                }
            } 
            else {
                throw std::runtime_error("Unknown shape type: " + type);
            }
        } 
        catch (const std::exception& e) {
            std::cerr << "Error on line " << lineNumber << ": " << e.what() << std::endl;
        }
    }

    file.close();

    std::cout << "\n--- Processing Complete ---\n" << std::endl;
    printAllAreas(shapes);

    return 0;
}
