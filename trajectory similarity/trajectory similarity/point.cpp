#include "pch.h"
#include "point.h"
Point::Point(){};

void Point::display(){
	cout << "Time: " << time << "  " << "longitude: " << lon << "  " << "latitude: " << lat << endl;
}
Point::Point(double lon, double lat, long long time) {
	this->lon = lon;
	this->lat = lat;
	this->time = time;
}
