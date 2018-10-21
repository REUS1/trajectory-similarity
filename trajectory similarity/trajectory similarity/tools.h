#pragma once
#ifndef tool_h
#define tool_h
#include "point.h"
using namespace std;
// min max and abs
int mmin(int a, int b);

int mmin(int a, int b, int c);

int mmax(int a, int b);

int mmax(int a, int b, int c);

int mabs(int a);

double mmin(double a, double b);

double mmin(double a, double b, double c);

double mmax(double a, double b);

double mmax(double a, double b, double c);

double mabs(double a);

//Distance Functions

double L1norm(Point p1, Point p2);  //º∆À„L1-norms

double L2norm(Point p1, Point p2);  //º∆À„L2-norms

double Linfinite(Point p1, Point p2);  //º∆À„Linfinite-norms

#endif 