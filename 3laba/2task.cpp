#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "ru");
	string user_input, answer_output, s;
	char cur_elem;
	int count = 0;
	getline(cin, user_input);
	answer_output += user_input[0];
	for (int i = 1; i < size(user_input); i++) {
		cur_elem = user_input[i];
		if (cur_elem == ',' and user_input[i + 1] != ' ') {
			answer_output += ", ";
		}
		else { answer_output += cur_elem; }
		//проверка на допустимость совпадения и поиск в нём слова информатика или Информатика 
		if ((cur_elem == 'И' or cur_elem == 'и') and size(user_input) - i > 11 and user_input.substr(i+1, 10) == "нформатика") {
			count++;}
	
	}
	cout <<"\n\n" << answer_output << "\n" << "количество слов информатика " << count<<"\n\n";
}
