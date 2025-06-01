///////////////////////////////////////////////////////////
// HexString.h
#include <string>
#include "AString.h"

const std::string alph = "0123456789ABCDEF"; // ���������� �������

// �������� �� ���������� HEX-������
bool IsHexStrVal(std::string _str);

// ����� ��� ����������������� �����
class HexString : public AString {
public:
    HexString(std::string _name) : name(_name) {}
    HexString(std::string _name, std::string _val);

    const std::string& GetName() const override { return name; }
    const std::string& GetVal() const override { return val; }
    int GetSize() const override { return val.size(); }

private:
    std::string name; // �������� ������
    std::string val;  // HEX-��������
};
///////////////////////////////////////////////////////////