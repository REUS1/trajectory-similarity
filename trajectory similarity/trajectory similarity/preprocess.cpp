#include "pch.h"
#include "trajectory.h"
#include "point.h"
#include "config.h"
#include <cstdio>
#include <iostream>
#include <fstream> 
#include <sstream> 
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

long long num = 0;                 //总点数
vector<Trajectory> trajs;          //记录轨迹
vector<string> ids;                //记录序号
map<string, long long> trajindex;  //map索引序号

bool idIndex(string serialnumber) { //对序号进行索引
	vector<string>::iterator iter;
	for (iter = ids.begin(); iter != ids.end(); iter++) {
		if (*iter == serialnumber) return true;
	}
	return false;
}

void readFile(string filename) {
	ifstream f(filename.c_str());
	string line;
	while (getline(f, line)) {
		istringstream s(line);
		vector<string> fields;
		string field;
		while (getline(s, field, ',')) {
			fields.push_back(field);
		}
		string id = fields[0];
		string lon = fields[1];
		string lat = fields[2];
		string time = fields[3];
		if (!idIndex(id)) {
			ids.push_back(id);
			Trajectory tra;
			tra.id = id;
			Point pot;
			pot.lon = atof(lon.c_str());
			pot.lat = atof(lat.c_str());
			pot.time = atoll(time.c_str());
			tra.traj.push_back(pot);
			trajs.push_back(tra);
			trajindex[id] = num++;
		}
		else {
			Point pot;
			pot.lon = atof(lon.c_str());
			pot.lat = atof(lat.c_str());
			pot.time = atoll(time.c_str());
			trajs[trajindex[id]].traj.push_back(pot);
		}
	}
}

bool cmpByTime(const Point &t1, const Point &t2) {
	return t1.time < t2.time;//升序排列
}

void trajPreprocess() { //让轨迹中的点以时间升序排列
	for (int i = 0; i < num; i++) {
		sort(trajs[i].traj.begin(), trajs[i].traj.end(), cmpByTime);
		trajs[i].num = trajs[i].traj.size();
	}
}