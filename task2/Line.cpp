///////////////////////////////////////////////////////////
// Line.cpp
#include <iostream>
#include "Line.h"

using namespace std;

void Line::Calculate() {
    cout << "Calculation for function y = " << name << endl;
    cout << "Enter a = "; cin >> a;
    cout << "Enter b = "; cin >> b;
    cout << "Enter X = "; cin >> x;
    cin.get(); // ������� ������
    cout << "y = " << (a * x + b) << endl; // ����������
    cin.get(); // �����
}

Line f_line; // �������� �������
///////////////////////////////////////////////////////////