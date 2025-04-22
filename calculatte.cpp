#include "Header.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "ru");
	help();
	Zpisi* arr = new Zpisi[10];


	while (user_input != "esc") {
		cout << "\n";
		output();
		cout << "\nвведите команду >> ";
		cin >> user_input;
		if (user_input == "help") help();
		else if (user_input == "input")
		{
			cout << "Добавьте заметку >> ";
			getline(cin, user_input);
			input(user_input);
		}
		else if (user_input == "del") {
			cout << "какую строку удалить >> ";
			cin >> n;
			delet(n);
		}
		else if (user_input == "redo") {
			cout << "какую строку заменить >> ";
			cin >> n;
			cout << "на что (в конце введите !)>> ";
			getline(cin, user_input,'!');
			delet(n, user_input);
		}
		else if (user_input == "del_all") {
			delet_all();
		}
	}

}
