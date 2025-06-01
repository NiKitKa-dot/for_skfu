// Line.h
#include "Function.h"
// ����� ��� ������������� ������� � = � * � + b
class Line : public Function {
public:
	Line() : name("a ^ x + b") {}
	const std::string& GetName() const { return name; }
	void Calculate();
protected:
	std::string name; // ���. ����������� �������
	double a;
	double b;
};
extern Line f_line;