#pragma once
#ifndef config_h
#define config_h
#include <map>
#include "trajectory.h"

extern long long num;                     //总点数
extern vector<Trajectory> trajs;          //记录轨迹
extern vector<string> ids;                //记录序号
extern map<string, long long> trajindex;  //map索引序号

#endif