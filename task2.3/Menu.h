///////////////////////////////////////////////////////////
// Menu.h
#include <vector>
#include "AString.h"
#include "Action.h"
#include "Factory.h"

// ������ ������ ���������
enum JobMode { AddObj, DelObj, WorkWithObj, Exit };

// ����� ��� ���������� ����
class Menu {
public:
    Menu(std::vector<Action*>);
    JobMode SelectJob() const;            // ����� ������
    AString* SelectObject(const Factory&) const; // ����� ������
    Action* SelectAction(const AString*) const;  // ����� ��������
    static int SelectItem(int);           // ������� ������ ������

private:
    std::vector<Action*> pAct; // ��������� ��������
};
///////////////////////////////////////////////////////////