#pragma once
#include"point.h"
#include"tools.h"
#include"config.h"
#include<vector>
#include<algorithm>
using namespace std;

struct result
{
	//查询结果，num为序号，dist为距离
	int num;
	double dist;
};

class EDRDistanceCalculator
{
public:
	EDRDistanceCalculator();
	EDRDistanceCalculator(double Threshold) { this->Threshold = Threshold; };
	vector<result> RetrievalByEDR(vector<Point> s, int k); //检索与给定轨迹最相似的k个轨迹,返回序号
	double getEDRDistance(vector<Point>r0, vector<Point>s0);
	~EDRDistanceCalculator();
private:
	double Threshold;
	int subcost(Point p1, Point p2);
};

