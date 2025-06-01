///////////////////////////////////////////////////////////
// ShowDec.h
#include "Action.h"

// �������� ����������� ����������� �������� (��� HEX)
class ShowDec : public Action {
public:
    ShowDec() : name("Show decimal value") {}
    void Operate(AString*) override;
    const std::string& GetName() const override { return name; }

private:
    std::string name;
};

extern ShowDec show_dec; // ���������� ������
///////////////////////////////////////////////////////////