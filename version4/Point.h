#pragma once
#ifndef POINT_H
#define POINT_H

enum ORIENT { LEFT, RIGHT, AHEAD, BEHIND, BETWEEN };
class Triangle;

class Point {
public:
	// �����������
	Point(double _� = 0, double _� = 0) : x(_�), y(_�) {}

	// ������ ������
	void Show() const;
	void operator +=(Point&);
	Point operator +(Point&);
	Point operator -(Point&);

	double Length() const; // ���������� ����� ������� ����� � �������� ������� ���������
	ORIENT Classify(Point, Point) const;// ���������� ��������� ����� ������������ �������, ��������� ����� �������
	bool InTriangle(Triangle&) const; // ����������, ��������� �� ����� ������ ������������

public:
	double x, y;
};

#endif /* POINT_H */

