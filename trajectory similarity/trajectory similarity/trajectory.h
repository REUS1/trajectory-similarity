#pragma once
#ifndef trajectory_h
#define trajectory_h
#include "point.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Trajectory{
public:
	Trajectory();
	void display();
	vector<Point> traj;  //�켣����
	int num;             //�켣�еĵ���
	string id;           //�켣���
};

#endif