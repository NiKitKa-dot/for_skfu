#include "Header.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

//�������
void output() {
fstream f1(path);
string cur = "";
if (f1.is_open()) {
	int stroka = 1;
	while (getline(f1, cur))
	{
		cout << stroka << ") " << cur << "\n";
		stroka++;
	}
}
f1.close();
}

//��������
void input(string s) {
fstream f2(path, ios::app);
f2 << s + '\n';
f2.close();
}

//������� (����� ������)
void delet(int num) {
fstream f3(path);
string cur = "";
vector <string> new_spi;
if (f3.is_open()) {
	int stroka = 1;
	while (getline(f3, cur))
	{
		if (stroka != num) {
			new_spi.push_back(cur);
		}
		stroka++;
	}
}
f3.close();
ofstream f4(path, ios::trunc);
for (auto u : new_spi) {
	f4 << u + '\n';
}
f4.close();
}

//������� ��
void delet_all() {
ofstream f5(path, ios::trunc);
f5 << "";
f5.close();
}

//�������� (����� ������ � �� ���)
void delet(int num, string new_str) {
fstream f6(path);
string cur = "";
vector <string> new_spi;
if (f6.is_open()) {
	int stroka = 1;
	while (getline(f6, cur))
	{
		if (stroka != num) {
			new_spi.push_back(cur);
		}
		else {
			new_spi.push_back(new_str);
		}
		stroka++;
	}
}
f6.close();
ofstream f7(path, ios::trunc);
for (auto u : new_spi) {
	f7 << u + '\n';
}
f7.close();
}

//������ �� �����������
void help() {
cout << " ������ input (��� ����� �������) ��� �������� ����� �������\n ������ del ��� ������� ������ ������\n ������ del_all ��� ������� �������� �������\n ������ esc ��� �������� ���������\n ������� redo ��� ���������� ������";
}


Zpisi::Zpisi(string a = "Ivan Ivanih", string b = "+7888888888888", string c = "0.0.0000") {
	fio = a;
	phone_number = b;
	date = c;
	input(fio + " " + phone_number + " " + date);
}
Zpisi::~Zpisi() { cout << "destroy element"; }

void Zpisi::out() {
	cout << "\n" << fio << " " << phone_number << " " << date;
}

//x = ������ �������� � ������� ������ + 1
void Zpisi::deleit(int x) {
	delet(x);
}

void Zpisi::clear() { delet_all(); }

