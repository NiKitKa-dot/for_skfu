#ifndef FACTORY_H
#define FACTORY_H

#include "triangle.h"
#include "rectangle.h"
#include <string>
#include <vector>

class Factory {
public:
    static Triangle* CreateTriangle(const std::string& id, double base, double height);
    static Rectangle* CreateRectangle(const std::string& id, double width, double height, double x, double y);
    static void DeleteObject(Triangle* obj);

private:
    // Prevent instantiation of the Factory class
    Factory() {}
};

#endif