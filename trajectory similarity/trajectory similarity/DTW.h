#pragma once
#ifndef DTW_h
#define DTW_h
#include "point.h"
using namespace std;

class DTW {
public:
	double dtwDistanceL1(int n, int m);//计算dtw距离，n，m分别代表轨迹序号
	double dtwDistanceL2(int n, int m);//计算dtw距离，n，m分别代表轨迹序号
};

#endif