#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string path = "C:/Users/ygv08/OneDrive/������� ����/txtt.txt";
string user_input = "";
int n = 0;

//�������
void output();
//��������
void input(string s);

//������� (����� ������)
void delet(int num);

//������� ��
void delet_all();

//�������� (����� ������ � �� ���)
void delet(int num, string new_str);

//������ �� �����������
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

	//x = ������ �������� � ������� ������ + 1
	void deleit(int x);

	void clear();
};
