#pragma once
#ifndef POINT_H
#define POINT_H

class Point {
public:
	// �����������
	Point(double _� = 0, double _� = 0) : x(_�), y(_�) {}

	// ������ ������
	void Show() const;

	void operator +=(Point&);

public:
	double x, y;
};

#endif /* POINT_H */

