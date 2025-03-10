#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
	//создаём словарь
	map <char, int> dict;
	string user_input;
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

	for (auto i : dict) cout << i.first << "  " << i.second<<"\n";
}
