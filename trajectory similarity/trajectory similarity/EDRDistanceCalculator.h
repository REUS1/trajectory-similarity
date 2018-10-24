#pragma once
#include"point.h"
#include"tools.h"
#include"config.h"
#include<vector>
#include<algorithm>
using namespace std;

struct result
{
	//��ѯ�����numΪ��ţ�distΪ����
	int num;
	double dist;
};

class EDRDistanceCalculator
{
public:
	EDRDistanceCalculator();
	EDRDistanceCalculator(double Threshold) { this->Threshold = Threshold; };
	vector<result> RetrievalByEDR(vector<Point> s, int k); //����������켣�����Ƶ�k���켣,�������
	double getEDRDistance(vector<Point>r0, vector<Point>s0);
	~EDRDistanceCalculator();
private:
	double Threshold;
	int subcost(Point p1, Point p2);
};

