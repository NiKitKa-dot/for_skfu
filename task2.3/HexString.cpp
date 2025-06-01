///////////////////////////////////////////////////////////
// HexString.cpp
#include <iostream>
#include "HexString.h"

using namespace std;

// ��������, ��� ������ �������� ������ HEX-�������
bool IsHexStrVal(string _str) {
    for (int i = 0; i < _str.size(); ++i) {
        if (string::npos == alph.find_first_of(toupper(_str[i])))
            return false;
    }
    return true;
}

// ����������� � ��������� ����������
HexString::HexString(string _name, string _val) : name(_name) {
    if (IsHexStrVal(_val))
        val = _val;
    else
        throw invalid_argument("Invalid HEX string");
}
///////////////////////////////////////////////////////////