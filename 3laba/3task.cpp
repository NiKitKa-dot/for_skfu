#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector <char> answer;
	string userinput;
	char k = ' ';
	getline(cin, userinput);
	for (char i : userinput.substr(0, 7)) {
		answer.push_back(i);
	}
	//сортировка пузырьком
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < i; j++) {
			if (answer[i] < answer[j]) {
				k = answer[i];
				answer[i] = answer[j];
				answer[j] = k;
			}
		}
	}
	for (char i : answer) { cout << i; }
	for (int i = 7; i < size(userinput); i++) cout << userinput[i];
}
