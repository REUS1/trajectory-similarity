#include "pch.h"
#include <vector>
#include <iostream>
#include "tools.h"
#include "point.h"
#include "config.h"
#include "DTW.h"
using namespace std;

double DTW::dtwDistanceL1(int n, int m) {
	int len1 = trajs[n].traj.size();//轨迹1的长度
	int len2 = trajs[m].traj.size();//轨迹2的长度
	//int ** pmatrix = new int* [len1 + 1];
    //for (int i = 0; i < len1 + 1; i++)
	//	pmatrix[i] = new int[len2 + 1];
	vector<vector<double>> pmatrix(len1+1, vector<double>(len2+1));

	pmatrix[0][0] = 0;
	for (int i = 1; i <= len2; ++i) {
		pmatrix[0][i] = INT_MAX;
	}
	for (int i = 1; i <= len1; ++i) {
		pmatrix[i][0] = INT_MAX;
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			int tmp1, tmp2;
			if (pmatrix[i - 1][j - 1] < pmatrix[i - 1][j]) {
				tmp1 = i - 1; tmp2 = j - 1;
			}
			else {
				tmp1 = i - 1; tmp2 = j;
			}
			if (pmatrix[tmp1][tmp2] > pmatrix[i][j - 1]) {
				tmp1 = i; tmp2 = j - 1;
			}
			pmatrix[i][j] = L1norm(trajs[n].traj[i-1], trajs[m].traj[j-1]) + pmatrix[tmp1][tmp2];
			//cout << L1norm(trajs[n].traj[i - 1], trajs[m].traj[j - 1]) + pmatrix[tmp1][tmp2] << endl;
			//cout << pmatrix[i][j] << endl;
		}
	}
/*
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			cout<< pmatrix[i][j] << " ";
		}
		cout << endl;
	}
*/
	return pmatrix[len1][len2];
}
double DTW::dtwDistanceL1(int n, int m) {
	int len1 = trajs[n].traj.size();
	int len2 = trajs[m].traj.size();
	//int ** pmatrix = new int* [len1 + 1];
	//for (int i = 0; i < len1 + 1; i++)
	//	pmatrix[i] = new int[len2 + 1];
	vector<vector<double>> pmatrix(len1 + 1, vector<double>(len2 + 1));

	pmatrix[0][0] = 0;
	for (int i = 1; i <= len2; ++i) {
		pmatrix[0][i] = INT_MAX;
	}
	for (int i = 1; i <= len1; ++i) {
		pmatrix[i][0] = INT_MAX;
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			int tmp1, tmp2;
			if (pmatrix[i - 1][j - 1] < pmatrix[i - 1][j]) {
				tmp1 = i - 1; tmp2 = j - 1;
			}
			else {
				tmp1 = i - 1; tmp2 = j;
			}
			if (pmatrix[tmp1][tmp2] > pmatrix[i][j - 1]) {
				tmp1 = i; tmp2 = j - 1;
			}
			pmatrix[i][j] = L2norm(trajs[n].traj[i - 1], trajs[m].traj[j - 1]) + pmatrix[tmp1][tmp2];
			//cout << L1norm(trajs[n].traj[i - 1], trajs[m].traj[j - 1]) + pmatrix[tmp1][tmp2] << endl;
			//cout << pmatrix[i][j] << endl;
		}
	}
	/*
		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				cout<< pmatrix[i][j] << " ";
			}
			cout << endl;
		}
	*/
	return pmatrix[len1][len2];
}