#include "Shape.h"
#include <iostream>
#include <cmath>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void Shape::display() const {
    std::cout << "Generic Shape";
}

// Rectangle Implementation
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}
double Rectangle::getArea() const { return width * height; }
void Rectangle::display() const {
    std::cout << "Rectangle (" << width << " x " << height << ")";
}

// Circle Implementation
Circle::Circle(double r) : radius(r) {}
double Circle::getArea() const { return M_PI * radius * radius; }
void Circle::display() const {
    std::cout << "Circle (radius: " << radius << ")";
}
