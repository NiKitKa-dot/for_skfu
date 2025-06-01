#include "factory.h"

Triangle* Factory::CreateTriangle(const std::string& id, double base, double height) {
    return new Triangle(id, base, height);
}

Rectangle* Factory::CreateRectangle(const std::string& id, double width, double height, double x, double y) {
    return new Rectangle(id, width, height, x, y);
}

void Factory::DeleteObject(Triangle* obj) {
    delete obj;
}