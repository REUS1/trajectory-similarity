#pragma once
#ifndef DTW_h
#define DTW_h
#include "point.h"
using namespace std;

class DTW {
public:
	double dtwDistanceL1(int n, int m);//����dtw���룬n��m�ֱ����켣���
	double dtwDistanceL2(int n, int m);//����dtw���룬n��m�ֱ����켣���
};

#endif