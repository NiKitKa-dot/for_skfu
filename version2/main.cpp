﻿#include <iostream>
#include "Triangle.h"
using namespace std;

int Menu();
int GetNumber(int, int);
void ExitBack();
void Show(Triangle* [], int);
void Move(Triangle* [], int);
void FindMax(Triangle* [], int);
void IsIncluded(Triangle* [], int);
double GetDouble();

// Инициализация глобальных переменных
int Triangle::count = 0;

// главная функция
int main(){

	setlocale(LC_ALL, "Russian");
	// Определения точек
	Point p1(0, 0); Point p2(0.5, 1);
	Point p3(1, 0); Point p4(0, 4.5);
	Point p5(2, 1); Point p6(2, 0);
	Point p7(2, 2); Point p8(3, 0);	
	
	// Определения треугольников
	Triangle triaA(p1, p2, p3, "triaA");
	Triangle triaB(p1, p4, p8, "triaB");
	Triangle triaC(p1, p5, p6, "triaC");
	Triangle triaD(p1, p7, p8, "triaD");

	// Определение массива указателей на треугольники
	Triangle* pTria[] = { &triaA, &triaB, &triaC, &triaD };
	int n = sizeof(pTria) / sizeof(pTria[0]);

	// Главный цикл
	bool done = false;
	while (!done) {
		switch (Menu()) {
			case 1: Show(pTria, n); break;
			case 2: Move(pTria, n); break;
			case 3: FindMax(pTria, n); break;
			case 4: IsIncluded(pTria, n); break;
			case 5: cout << "Конец работы." << endl; done = true; break;
		}
	}	
	return 0;
}
// вывод меню

int Menu() {
	cout << "\n=================== Главное меню ===================\n" << endl;
	cout << "1 - вывести все oбъeкты\t 3 - найти максимальный" << endl;
	cout << "2 - nepeместить\t\t 4 - определить отношение включения" << endl;
	cout << "\t\t 5 - выход" << endl;

	return GetNumber(1, 5);
}

// ввод целого числа в заданном диапазоне
int GetNumber(int min, int max) {
	int number = min - 1;
	while (true) {
		std::cin >> number;
		if ((number >= min) && (number <= max) && (std::cin.peek() == '\n'))
		{
			break;
		}
		else
		{
			cout << "Повторите ввод (ожидается число от " << min
				<< " до " << max << " ) : " << endl;
			std::cin.clear();
			while (std::cin.get() != '\n') {};
		}
	}
	return number;
}

// возврат в функцию с основным меню
void ExitBack(){
	cout << "Нажмите Enter." << endl;
	cin.get(); cin.get();
}

// вывод всех треугольников
void Show(Triangle *p_tria[], int k) {
	cout << "======= Перечень треугольников ========" << endl;
	for (int i = 0; i < k; ++i) p_tria[i]->Show();	
	ExitBack();
}

// перемещение
void Move(Triangle* p_tria[], int k) {
	cout << "============= Перемещение =============" << endl;
	cout << "Введите номер треугольника (от 1 до " << k << " ) : ";
	int i = GetNumber(1, k) - 1;
	p_tria[i]->Show();

	Point dp;
	cout << "Введите смещение по х: ";
	dp.x = GetDouble();
	cout << "Введите смещение по у: ";
	dp.y = GetDouble();

	p_tria[i]->Move(dp);
	cout << "Новое положение треугольника:" << endl;
	p_tria[i]->Show();

	ExitBack();
}

// поиск максимального треугольника
void FindMax(Triangle* p_tria[], int k) {
	cout << "=== Поиск максимального треугольника ==" << endl;
	// здесь будет код функции...
	ExitBack();
}
// определение отношения включения
void IsIncluded(Triangle* p_tria[], int k) {
	cout << "======== Отношение включения ==========" << endl;
	// здесь будет код функции...
	ExitBack();
}

double GetDouble() {
	double value;
	while (true) {
		cin >> value;
		if (cin.peek() == '\n') break;
		else {
			cout << "Повторите ввод (ожидается вещественное число):" << endl;
			cin.clear();
			while (cin.get() != '\n') {};
		}
	}
	return value;
}