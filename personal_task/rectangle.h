#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "triangle.h"

class Rectangle : public Triangle {
public:
    Rectangle(const std::string& id, double width, double height, double x, double y);
    Rectangle(const Rectangle& other); // Copy constructor
    Rectangle& operator=(const Rectangle& other); // Assignment operator
    ~Rectangle() override;

    double GetWidth() const { return width; }
    void SetWidth(double width);
    void Show() const override;
    void Move(double dx, double dy) override;
    bool compair(const Triangle* other) const;

protected:
    double width;
    double x_coord;
    double y_coord;

    double get_x_coord() const override;
    double get_y_coord() const override;
};

#endif