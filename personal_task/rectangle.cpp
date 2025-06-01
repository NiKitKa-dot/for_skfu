#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(const std::string& id, double width, double height, double x, double y)
    : Triangle(id, width, height), width(width), x_coord(x), y_coord(y) {}

Rectangle::Rectangle(const Rectangle& other)
    : Triangle(other), width(other.width), x_coord(other.x_coord), y_coord(other.y_coord) {}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        Triangle::operator=(other); // Call base class assignment
        width = other.width;
        x_coord = other.x_coord;
        y_coord = other.y_coord;
    }
    return *this;
}

Rectangle::~Rectangle() { }

void Rectangle::SetWidth(double width) { this->width = width; }

void Rectangle::Show() const  {
    std::cout << "Rectangle ID: " << id
        << ", Width: " << width
        << ", Height: " << height
        << ", Area: " << GetArea()
        << ", X Coordinate: " << x_coord
        << ", Y Coordinate: " << y_coord << std::endl;
}

void Rectangle::Move(double dx, double dy) {
    x_coord += dx;
    y_coord += dy;
    std::cout << "Rectangle " << id << " moved to (" << x_coord << ", " << y_coord << ")\n";
}

//AABB overlap testing
bool Rectangle::compair(const Triangle* other) const {
    const Rectangle* r = dynamic_cast<const Rectangle*>(other);
    if (r) {
        if (get_x_coord() < r->get_x_coord() + r->GetWidth() &&
            get_x_coord() + GetWidth() > r->get_x_coord() &&
            get_y_coord() < r->get_y_coord() + r->GetHeight() &&
            get_y_coord() + GetHeight() > r->get_y_coord()) {
            return true;
        }
        return false;
    }
    else
    {
        std::cout << "Can't do triangle intersection yet! Comparing general triangles is hard. Can't perform it right now.";
        return false;
    }

}

//helper methods.
double Rectangle::get_x_coord() const {
    return x_coord;
}

double Rectangle::get_y_coord() const {
    return y_coord;
}