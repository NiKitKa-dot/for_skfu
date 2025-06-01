// Exp.cpp
#include <iostream>
#include <math.h> 
#include "Exp.h"
using namespace std;
void Exp::Calculate() {
	cout << "Calculation for function у = " << name << "\n";
	cout << "Enter X = "; 
	cin >> x;
	cin.get();
	cout << "y = " << exp(x) << "\n";
	cin.get();
}
// Глобальный объект
Exp f_exp;