#pragma once
#ifndef preprocess_h
#define preprocess_h
#include "config.h"
#include <string>

void readFile(string filename); //读取文件

bool idIndex(string serialnumber); //轨迹索引

bool cmpByTime(const Point &t1, const Point &t2); //按时间顺序升序排列

void trajPreprocess();  //其他一些处理

#endif