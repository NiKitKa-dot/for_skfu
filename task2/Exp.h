///////////////////////////////////////////////////////////
// Exp.h
#include <math.h>
#include "Function.h"

// ����� ���������������� ������� y = e^x
class Exp : public Function {
public:
    Exp() : name("e^x") {} // �����������
    const std::string& GetName() const { return name; }
    void SetCoeff() {} // ��� ���������� �� ����� ������������
    double GetVal() const { return exp(x); } // ���������� e^x
private:
    std::string name; // �������� �������
};

extern Exp f_exp; // ���������� ������
///////////////////////////////////////////////////////////