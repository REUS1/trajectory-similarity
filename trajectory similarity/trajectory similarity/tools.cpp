#include "pch.h"
#include "point.h"
#include <iostream>
#include <cmath>
using namespace std;
int mmin(int a, int b) {
	return a < b ? a : b;
}

int mmin(int a, int b, int c) {
	a = a < c ? a : c;
	return a < b ? a : b;
}

int mmax(int a, int b) {
	return a > b ? a : b;
}
int mmax(int a, int b, int c) {
	a = a > c ? a : c;
	return a > b ? a : b;
}

int mabs(int a) {
	return a > 0 ? a : -a;
}
double mmin(double a, double b) {
	return a < b ? a : b;
}

double mmin(double a, double b, double c) {
	a = a < c ? a : c;
	return a < b ? a : b;
}

double mmax(double a, double b) {
	return a > b ? a : b;
}
double mmax(double a, double b, double c) {
	a = a > c ? a : c;
	return a > b ? a : b;
}

double mabs(double a) {
	return a > 0 ? a : -a;
}

/*
* Distance Functions
*/

double L1norm(Point p1, Point p2) {
	return mabs(p1.lat - p2.lat) + mabs(p1.lon - p2.lon);
}
double L2norm(Point p1, Point p2) {
	return sqrt((p1.lat - p2.lat)*(p1.lat - p2.lat) + (p1.lon - p2.lon)*(p1.lon - p2.lon));
}
double Linfinite(Point p1, Point p2) {
	return mmax(mabs(p1.lat - p2.lat), mabs(p1.lon - p2.lon));
}
