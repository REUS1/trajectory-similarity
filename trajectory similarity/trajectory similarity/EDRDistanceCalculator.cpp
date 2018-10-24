#include "pch.h"
#include "EDRDistanceCalculator.h"


EDRDistanceCalculator::EDRDistanceCalculator()
{
}


EDRDistanceCalculator::~EDRDistanceCalculator()
{
}

int EDRDistanceCalculator::subcost(Point p1, Point p2)
{
	if (mabs(p1.lat - p2.lat) <= Threshold&&mabs(p1.lon - p2.lon) <= Threshold)
		return 0;
	return 1;
}

bool cmpByDist(const result &result1, const result &result2) {
	return result1.dist < result2.dist;//升序排列
}

vector<result> EDRDistanceCalculator::RetrievalByEDR(vector<Point> s, int k)
{
	//不采用剪枝，直接遍历
	vector<result> results(k);
	//初始化结果集
	for (int i = 0; i < k; i++) {
		results[i].num = i;
		results[i].dist = getEDRDistance(s, trajs[i].traj);
	}
	sort(results.begin(), results.end(), cmpByDist);
	double bestSoFar = results.back().dist;
	for (int i = k; i < trajs.size(); i++) {
		if (getEDRDistance(s, trajs[i].traj) < bestSoFar) {
			results.back().num = i;
			results.back().dist = getEDRDistance(s, trajs[i].traj);
			sort(results.begin(), results.end(), cmpByDist);
			bestSoFar = results.back().dist;
		}
	}

	return results;
}

double EDRDistanceCalculator::getEDRDistance(vector<Point> r0, vector<Point> s0)
{
	double ** edrMetric = new double *[r0.size() + 1];
	for (int i = 0; i < r0.size() + 1; i++)
		edrMetric[i] = new double[s0.size() + 1];
	for (int i = 0; i <= r0.size(); i++)
		edrMetric[i][0] = i;
	for (int i = 0; i <= s0.size(); i++)
		edrMetric[0][i] = i;
	edrMetric[0][0] = 0;
	for (int i = 1; i <= r0.size(); i++) {
		for (int j = 1; j <= s0.size(); j++) {
			edrMetric[i][j] = mmin(edrMetric[i - 1][j - 1] + subcost(r0[i - 1], s0[j - 1]), edrMetric[i][j - 1] + 1, edrMetric[i - 1][j] + 1);
		}
	}

	double edrDistance = edrMetric[r0.size()][s0.size()];
	for (int i = 0; i < r0.size() + 1; i++)
		delete[] edrMetric[i];
	delete[] edrMetric;
	return edrDistance;
}
