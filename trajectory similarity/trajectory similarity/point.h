#pragma once
#ifndef point_h
#define point_h
#include <iostream>
using namespace std;

class Point {
public:
	Point();
	void display(); 
	long long time; //ʱ�� 
	double lon;     //����
	double lat;     //γ��
};

#endif