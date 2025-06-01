///////////////////////////////////////////////////////////
// ShowStr.h
#include "Action.h"

// �������� ����������� ������
class ShowStr : public Action {
public:
    ShowStr() : name("Show string value") {}
    void Operate(AString*) override;
    const std::string& GetName() const override { return name; }

private:
    std::string name;
};

extern ShowStr show_str; // ���������� ������
///////////////////////////////////////////////////////////