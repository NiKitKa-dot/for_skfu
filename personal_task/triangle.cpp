#include "triangle.h"
#include <cmath>
#include <limits>

Triangle::Triangle(const std::string& id, double base, double height) : id(id), base(base), height(height) {}

Triangle::Triangle(const Triangle& other) : id(other.id), base(other.base), height(other.height) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        id = other.id;
        base = other.base;
        height = other.height;
    }
    return *this;
}

Triangle::~Triangle() {}

void Triangle::SetBase(double base) { this->base = base; }
void Triangle::SetHeight(double height) { this->height = height; }

double Triangle::GetArea() const { return 0.5 * base * height; }

void Triangle::Show() const {
    std::cout << "Triangle ID: " << id
        << ", Base: " << base
        << ", Height: " << height
        << ", Area: " << GetArea() << std::endl;
}

void Triangle::Move(double dx, double dy) {
    // For a simple triangle, just print a message indicating that it can't be moved
    std::cout << "Moving a general triangle by (" << dx << ", " << dy << ") isn't well-defined.\n";
}

bool Triangle::compair(const Triangle* other) const {
    //comparing general triangles is hard.
    std::cout << "Comparing general triangles is hard. Can't perform it right now.";
    return false;
}

//helper methods.
double Triangle::get_x_coord() const {
    return 0; //no well defined way to measure these, therefore returning a static value.
}

double Triangle::get_y_coord() const {
    return 0; //no well defined way to measure these, therefore returning a static value.
}