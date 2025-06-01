#include <iostream>
#include <string>
#include <vector>
#include "triangle.h"
#include "rectangle.h"
#include "factory.h"

int main() {
    std::vector<Triangle*> objects; // Store created objects

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Create Triangle\n";
        std::cout << "2. Create Rectangle\n";
        std::cout << "3. Delete Object\n";
        std::cout << "4. Show Object\n";
        std::cout << "5. Move Rectangle\n";
        std::cout << "6. Compare Rectangles\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline character

        switch (choice) {
        case 1: {
            std::string id;
            double base, height;
            std::cout << "Enter Triangle ID: ";
            std::getline(std::cin, id);
            std::cout << "Enter Base: ";
            std::cin >> base;
            std::cout << "Enter Height: ";
            std::cin >> height;
            std::cin.ignore();

            Triangle* triangle = Factory::CreateTriangle(id, base, height);
            objects.push_back(triangle);
            std::cout << "Triangle created with ID: " << id << std::endl;
            break;
        }
        case 2: {
            std::string id;
            double width, height, x, y;
            std::cout << "Enter Rectangle ID: ";
            std::getline(std::cin, id);
            std::cout << "Enter Width: ";
            std::cin >> width;
            std::cout << "Enter Height: ";
            std::cin >> height;
            std::cout << "Enter X Coordinate: ";
            std::cin >> x;
            std::cout << "Enter Y Coordinate: ";
            std::cin >> y;
            std::cin.ignore();

            Rectangle* rectangle = Factory::CreateRectangle(id, width, height, x, y);
            objects.push_back(rectangle);
            std::cout << "Rectangle created with ID: " << id << std::endl;
            break;
        }
        case 3: {
            if (objects.empty()) {
                std::cout << "No objects to delete.\n";
                break;
            }

            std::cout << "Enter the index of the object to delete (0-" << objects.size() - 1 << "): ";
            int index;
            std::cin >> index;
            std::cin.ignore();

            if (index >= 0 && index < objects.size()) {
                Factory::DeleteObject(objects[index]);
                objects.erase(objects.begin() + index);
                std::cout << "Object deleted.\n";
            }
            else {
                std::cout << "Invalid index.\n";
            }
            break;
        }
        case 4: {
            if (objects.empty()) {
                std::cout << "No objects to show.\n";
                break;
            }

            std::cout << "Enter the index of the object to show (0-" << objects.size() - 1 << "): ";
            int index;
            std::cin >> index;
            std::cin.ignore();

            if (index >= 0 && index < objects.size()) {
                objects[index]->Show();
            }
            else {
                std::cout << "Invalid index.\n";
            }
            break;
        }
        case 5: {
            if (objects.empty()) {
                std::cout << "No objects to move.\n";
                break;
            }

            std::cout << "Enter the index of the Rectangle to move (0-" << objects.size() - 1 << "): ";
            int index;
            std::cin >> index;
            std::cin.ignore();

            if (index >= 0 && index < objects.size()) {
                Rectangle* rect = dynamic_cast<Rectangle*>(objects[index]);
                if (rect) {
                    double dx, dy;
                    std::cout << "Enter dx: ";
                    std::cin >> dx;
                    std::cout << "Enter dy: ";
                    std::cin >> dy;
                    std::cin.ignore();

                    rect->Move(dx, dy);
                }
                else {
                    std::cout << "Object at index " << index << " is not a Rectangle.\n";
                }
            }
            else {
                std::cout << "Invalid index.\n";
            }
            break;
        }
        case 6: {
            if (objects.size() < 2) {
                std::cout << "Need at least two objects to compare.\n";
                break;
            }

            std::cout << "Enter the index of the first rectangle (0-" << objects.size() - 1 << "): ";
            int index1;
            std::cin >> index1;
            std::cout << "Enter the index of the second rectangle (0-" << objects.size() - 1 << "): ";
            int index2;
            std::cin >> index2;
            std::cin.ignore();

            if (index1 >= 0 && index1 < objects.size() && index2 >= 0 && index2 < objects.size()) {
                Rectangle* rect1 = dynamic_cast<Rectangle*>(objects[index1]);
                Triangle* tri2 = dynamic_cast<Triangle*>(objects[index2]); // Use Triangle* to compare with any Triangle (Rectangle is a type of Triangle)

                if (rect1 && tri2) {
                    if (rect1->compair(tri2)) { //compair can take general triangles.
                        std::cout << "The rectangles overlap.\n";
                    }
                    else {
                        std::cout << "The rectangles do not overlap.\n";
                    }
                }
                else {
                    std::cout << "Both objects must be rectangles.\n";
                }
            }
            else {
                std::cout << "Invalid index.\n";
            }
            break;
        }

        case 7: {
            // Clean up memory before exiting
            for (Triangle* obj : objects) {
                Factory::DeleteObject(obj);
            }
            objects.clear();
            std::cout << "Exiting program.\n";
            return 0;
        }
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}