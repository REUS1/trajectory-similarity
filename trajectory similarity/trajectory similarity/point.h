#pragma once
#ifndef point_h
#define point_h
#include <iostream>
using namespace std;

class Point {
public:
	Point();
	Point(double lon, double lat, long long time);
	void display(); 
	long long time; //时间
	double lon;     //经度
	double lat;     //纬度
};

#endif