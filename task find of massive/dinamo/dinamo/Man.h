#pragma once

const int l_name = 30;
const int l_year = 5;
const int l_pay = 100;
const int l_buf =  l_name + l_pay+ l_year;

//создаём класс
class Man {
public:
	Man(int lName = 30);//конструктор
	~Man();//деструктор
	bool CompareName(const char*) const;
	int GetBirthYear() const { return birth_year; };
	char* GetpName() const { return pName; };
	float GetPay() const { return pay; };
	void SetBirthYear(const char*);
	void SetName(const char*);
	void SetPay (const char*);
	void Print();

private:
	char* pName;
	int birth_year;
	float pay;
};