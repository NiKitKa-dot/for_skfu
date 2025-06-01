#pragma once
#include <vector>
#include "Function.h"
class Menu {
public:
	Menu(std::vector<Function*>);
	Function* SelectObject(int) const;
private:
	int SelectItem(int) const;
	std::vector<Function*> pObj;
};