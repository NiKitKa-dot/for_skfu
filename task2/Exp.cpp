///////////////////////////////////////////////////////////
// Exp.cpp
#include <iostream>
#include <cmath>
#include "Exp.h"

using namespace std;

// ���������� ���������� ����������
void Exp::Calculate() {
    cout << "Calculation for function y = " << name << endl;
    cout << "Enter X = "; cin >> x; // ���� ���������
    cin.get(); // ������� ������ �� '\n'
    cout << "y = " << exp(x) << endl; // ���������� e^x
    cin.get(); // ����� ����� �������
}

// �������� ����������� �������
Exp f_exp;
///////////////////////////////////////////////////////////