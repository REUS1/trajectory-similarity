#pragma once
#ifndef preprocess_h
#define preprocess_h
#include "config.h"
#include <string>

void readFile(string filename); //��ȡ�ļ�

bool idIndex(string serialnumber); //�켣����

bool cmpByTime(const Point &t1, const Point &t2); //��ʱ��˳����������

void trajPreprocess();  //����һЩ����

#endif