///////////////////////////////////////////////////////////
// Exp.h
#include "Function.h"

// ����� ��� ������� y = e^x (����������)
class Exp : public Function {
public:
    Exp() : name("e^x") {} // �����������, �������������� ��������
    const std::string& GetName() const { return name; } // ���������� ��������
    void Calculate(); // ���������� ����������
protected:
    std::string name; // �������� �������
};

extern Exp f_exp; // ���������� ������ ����������
///////////////////////////////////////////////////////////