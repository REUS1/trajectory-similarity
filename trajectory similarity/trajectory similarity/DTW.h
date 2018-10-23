#pragma once
#ifndef DTW_h
#define DTW_h
#include "point.h"
using namespace std;

class DTW {
public:
	vector<pair<int, int>> path;
	double dtwDistanceL1(int n, int m);//计算dtw距离，n，m分别代表轨迹序号
	double dtwDistanceL2(int n, int m);//计算dtw距离，n，m分别代表轨迹序号
	double dtwDistanceL2(vector<Point> a, vector<Point> b);
	vector<Point> __reduce_by_half(vector<Point> x);
	vector<pair<int, int>> __expand_window(vector<pair<int, int>> path, int len_x, int len_y, int radius);
	double dtwDistanceL2_2(vector<Point> a, vector<Point> b, vector<pair<int, int>> window);
	double FastDTW(vector<Point> a, vector<Point> b, int radius); //FastDTW算法，优化矩阵计算，减少时间复杂度

};

#endif