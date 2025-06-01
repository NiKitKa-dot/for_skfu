///////////////////////////////////////////////////////////
// Parabola.h
#include "Function.h"

// ����� ��� �������� y = a*x^2 + b*x + c
class Parabola : public Function {
public:
    Parabola() : name("a*x^2 + b*x + c") {}
    const std::string& GetName() const { return name; }
    void Calculate();
protected:
    std::string name;
    double a, b, c; // ������������ ��������
};

extern Parabola f_parabola;
///////////////////////////////////////////////////////////