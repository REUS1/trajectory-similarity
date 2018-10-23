#include "pch.h"
#include <vector>
#include <iostream>
#include "tools.h"
#include "point.h"
#include "config.h"
#include "DTW.h"
using namespace std;

double DTW::dtwDistanceL1(int n, int m) {
	int len1 = trajs[n].traj.size();//轨迹1的点迹个数
	int len2 = trajs[m].traj.size();//轨迹2的点迹个数
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

double DTW::dtwDistanceL2(int n, int m) {
	int len1 = trajs[n].traj.size();
	int len2 = trajs[m].traj.size();
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
double DTW::dtwDistanceL2(vector<Point> a, vector<Point> b) {
	int len1 = a.size();
	int len2 = b.size();
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
			pmatrix[i][j] = L2norm(a[i - 1], b[j - 1]) + pmatrix[tmp1][tmp2];
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

double DTW::FastDTW(vector<Point> a, vector<Point> b, int radius) {
	int min_size = radius + 2;
	if (a.size() < min_size || b.size() < min_size) {
		return dtwDistanceL2(a, b);
	}
	vector<Point> x_shrinked = __reduce_by_half(a);
	vector<Point> y_shrinked = __reduce_by_half(b);
	FastDTW(x_shrinked, y_shrinked, radius);
	vector<pair<int, int>> window = __expand_window(path, a.size(), b.size(), radius);
	if (window.size() == 0) {
		return dtwDistanceL2(a, b);
	}
	return dtwDistanceL2_2(a, b, window);
}

double DTW::dtwDistanceL2_2(vector<Point> a, vector<Point> b, vector<pair<int, int>> window) {
	int len1 = a.size();
	int len2 = b.size();
	vector<vector<double>> pmatrix(len1 + 1, vector<double>(len2 + 1));
	pmatrix[0][0] = 0;
	for (int i = 1; i <= len2; ++i) {
			pmatrix[0][i] = INT_MAX;
		}
	for (int i = 1; i <= len1; ++i) {
		pmatrix[i][0] = INT_MAX;
	}
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; j++) {
			pmatrix[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < window.size(); i++) {
		int aP = window[i].first;
		int bP = window[i].second;
		double dt = L2norm(a[aP], b[bP]);
		int tmp1, tmp2;
		if (pmatrix[aP - 1][bP - 1] = pmatrix[aP - 1][bP]) {
			tmp1 = aP - 1; tmp2 = bP - 1;
		}
		else {
			tmp1 = aP - 1; tmp2 = bP;
		}
		if (pmatrix[tmp1][tmp2] > pmatrix[aP][bP - 1]) {
			tmp1 = aP; tmp2 = bP - 1;
		}
		pmatrix[aP][bP] =dt + pmatrix[tmp1][tmp2];
	}
	return pmatrix[len1][len2];
}
vector<pair<int, int>> DTW::__expand_window(vector<pair<int, int>> path, int len1, int len2, int radius) {
	vector<pair<int, int>> path_;
	int i, j, a, b;
	for (i = 0; i < path.size(); i++) {
		for (a = -radius; a <= radius; a++) {
			for (b = -radius; b <= radius; b++) {
				path_.push_back(make_pair(path[i].first + a, path[i].second + b));
			}
		}
	}
	vector<pair<int, int>> window_;
	for (i = 0; i < path_.size(); i++) {
		int a = path_[i].first;
		int b = path_[i].second;
		window_.push_back(make_pair(a * 2, b * 2));
		window_.push_back(make_pair(a * 2, b * 2 + 1));
		window_.push_back(make_pair(a * 2 + 1, b * 2));
		window_.push_back(make_pair(a * 2 + 1, b * 2 + 1));
	}
	vector<pair<int, int>> window;
	int start_j = 0;
	for (i = 0; i < len1; i++) {
		int new_start_j = -1;
		for (j = start_j; j < len2; j++) {
			vector<pair<int, int>>::iterator it;
			pair<int, int> value = make_pair(i, j);
			it = find(window_.begin(), window_.end(), value);
			if (it != window_.end()) {
				window.push_back(make_pair(i, j));
				if (new_start_j == -1)
					new_start_j = j;
			}
			else if (new_start_j != -1) {
				break;
			}
		}
		start_j = new_start_j;
	}
	return window;
}
vector<Point> DTW::__reduce_by_half(vector<Point> x) {
	vector<Point> result;
	for (int i = 0; i < x.size() - x.size() % 2; i += 2) {
		result.push_back(Point((x[i].lon + x[i + 1].lon) / 2, (x[i].lat + x[i + 1].lat) / 2, (x[i].time + x[i + 1].time) / 2));
	}
	return result;
}
