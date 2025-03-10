#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
using namespace std;

int main() {
	system("chcp 1251");
	//создаём словарь
	map <char, int> dict;
	string user_input, answer= "";
	getline(cin, user_input);
	set <char> s;
	for (char i : user_input) {
		s.insert(i);
	}
	//инициализируем словарь
	for (char i : s) {
		dict[i] = 0;
	}
	for (char i : user_input) {
		dict[i] += 1;
	}

	for (auto i : dict) cout <<'"' << i.first << '"'<<" встречается " << i.second << " раз(а)\n";
	//замена всех слов «уникальный» на слова «единственный» 
	int i = 0;
	while ( i < user_input.size()-10) {
		if (user_input.substr(i, 10) == "уникальный") {
			answer += "единственный";
			i += 9;
		}
		answer += user_input[i];
		i++;
	}
	cout << answer+ user_input.substr(user_input.size() - 10, 10);
}
