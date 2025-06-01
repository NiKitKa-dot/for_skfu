#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <string>
#include <vector>

class Triangle {
public:
    Triangle(const std::string& id, double base, double height);
    Triangle(const Triangle& other); // Copy constructor
    Triangle& operator=(const Triangle& other); // Assignment operator
    virtual ~Triangle();

    std::string GetId() const { return id; }
    double GetBase() const { return base; }
    double GetHeight() const { return height; }
    void SetBase(double base);
    void SetHeight(double height);

    double GetArea() const;
    virtual void Show() const; // Display object information
    virtual void Move(double dx, double dy); // Move the object (translation)

    bool compair(const Triangle* other) const; // Compare and return true if there is an intersection

protected:
    std::string id;
    double base;
    double height;

    //helper methods.
    virtual double get_x_coord() const;
    virtual double get_y_coord() const;
};
#endif