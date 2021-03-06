// trajectory similarity.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include "trajectory.h"
#include "point.h"
#include "config.h"
#include "preprocess.h"
#include "tools.h"
#include "DTW.h"
#include <vector>
using namespace std;

int main() {
	string fileName1 = "C:\\Users\\Flamewaker\\Desktop\\论文学习\\wh_u_main.csv";
	readFile(fileName1);
	// cout << num << endl;
	trajPreprocess();
	DTW *dtw = new DTW();
	int M = num;
	vector<vector<double>> dtw_distanceL1(M, vector<double>(M));
/*
	for (int i = 0; i < num; i++) {
		cout << trajs[i].id << endl;
		for (int j = 0; j < trajs[i].num; j++) {
			cout << trajs[i].traj[j].lon << "\t" << trajs[i].traj[j].lat << "\t" << trajs[i].traj[j].time << endl;
		}
		cout << trajs[i].num << endl;
		cout << endl;
	}
*/
	/*
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			dtw_distanceL1[i][j] = dtwDistanceL2(i, j);
		}
	}
	*/
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			dtw_distanceL1[i][j] = dtw->FastDTW(trajs[i].traj, trajs[j].traj, 2);
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout<< dtw_distanceL1[i][j] << "\t" ;
		}
		cout << endl;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
