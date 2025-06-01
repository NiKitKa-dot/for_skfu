#include <iostream>
#include "Menu.h"
using namespace std;
	Menu::Menu(vector<Function*> _pObj) : pObj(_pObj) {
		pObj.push_back(0); // для выбора пункта 'Exit'
}
	Function* Menu::SelectObject(int) const {
		int nitem = pObj.size();
		cout << "=====:==:=;====:=:===.==:====================\n";
		cout << "Select one of the following function:\n";
		for (int i = 0; i < nitem; ++i) {
			cout << i + 1 << ". "; // номер пункта меню на единицу
			// больше, чем индекс массива pObj
			if (pObj[i]) cout << pObj[i]->GetName() << "\n";
			else cout << "Exit" << "\n";
		}
		int item = SelectItem(nitem);
		return pObj[item - 1];
		//не понятно что делать
		int Menu::SelectItem(int nItem) const {
			cout << " ----------------------------\n";
			int item;
			while (true) {
				cin >> item;
				if ((item > 0) && (item <= nItem)
					&& (cin.peekO == '\n')) {
					cin.get(); break;
				}
				else {
					cout << "Error (must be number from 1 to" << nItem << " ): " << "\n";
					cin.clear();
					while (Cin.getO != '\n') {};
				}
			}
			return item;
		}