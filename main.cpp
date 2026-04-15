/*
AI Usage Disclosure:
I used ChatGPT to help generate and understand parts of this assignment.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>

// TEMP workaround (per instructions)
#include "Shape.cpp"

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "Area: "
                  << std::fixed << std::setprecision(4)
                  << shape->getArea() << std::endl << std::endl;
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

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "rectangle") {
            double w, h;
            if (ss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            } else {
                std::cerr << "Error on line " << lineNumber
                          << ": Invalid rectangle data" << std::endl;
            }
        }
        else if (type == "circle") {
            double r;
            if (ss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            } else {
                std::cerr << "Error on line " << lineNumber
                          << ": Invalid circle data" << std::endl;
            }
        }
        else {
            std::cerr << "Error on line " << lineNumber
                      << ": Unknown shape type" << std::endl;
        }
    }

    printAllAreas(shapes);

    return 0;
}
