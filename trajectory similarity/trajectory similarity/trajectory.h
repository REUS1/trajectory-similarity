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
	vector<Point> traj;  //¹ì¼£ÐòÁÐ
	int num;             //¹ì¼£ÖÐµÄµãÊý
	string id;           //¹ì¼£ÐòºÅ
};

#endif