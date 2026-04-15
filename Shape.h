#pragma once
#include <iostream>

// Base abstract class
class Shape {
public:
    virtual double getArea() const = 0;

    virtual void display() const {
        std::cout << "Generic Shape" << std::endl;
    }

    virtual ~Shape() = default;
};

// Rectangle class
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);

    double getArea() const override;

    void display() const override;
};

// Circle class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);

    double getArea() const override;

    void display() const override;
};
