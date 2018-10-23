#pragma once
#ifndef DTW_h
#define DTW_h
#include "point.h"
using namespace std;

class DTW {
public:
	vector<pair<int, int>> path;
	double dtwDistanceL1(int n, int m);//����dtw���룬n��m�ֱ����켣���
	double dtwDistanceL2(int n, int m);//����dtw���룬n��m�ֱ����켣���
	double dtwDistanceL2(vector<Point> a, vector<Point> b);
	vector<Point> __reduce_by_half(vector<Point> x);
	vector<pair<int, int>> __expand_window(vector<pair<int, int>> path, int len_x, int len_y, int radius);
	double dtwDistanceL2_2(vector<Point> a, vector<Point> b, vector<pair<int, int>> window);
	double FastDTW(vector<Point> a, vector<Point> b, int radius); //FastDTW�㷨���Ż�������㣬����ʱ�临�Ӷ�

};

#endif