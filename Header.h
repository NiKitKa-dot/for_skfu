#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string path = "C:/Users/ygv08/OneDrive/Рабочий стол/txtt.txt";
string user_input = "";
int n = 0;

//вывести
void output();
//добавить
void input(string s);

//удалить (номер строки)
void delet(int num);

//удалить всё
void delet_all();

//изменить (номер строки и на что)
void delet(int num, string new_str);

//помощь по функционалу
void help();



class Zpisi {
private:
	string fio;
	string phone_number;
	string date;
public:
	Zpisi(string a, string b, string c);
	~Zpisi();
	void out();

	//x = индекс элемента в массиве класса + 1
	void deleit(int x);

	void clear();
};
