// Line.cpp
#include <iostream>
#include "Line.h"
using namespace std;
	void Line::Calculate() {
		cout << "Calculation for function � = " << name << "\n";
		cout << "Enter a = "; cin >> a;
		cout << "Enter b = "; cin >> b;
		cout << "Enter X = "; cin >> x;
		cin.get();
		cout << "y = " <<(a * x + b) <<"\n";
		cin.get();
}
// ���������� ������
	Line f_line;