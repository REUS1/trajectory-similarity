#include "pch.h"
#include "trajectory.h"
Trajectory::Trajectory() {};

void Trajectory::display() {
	cout << "trajectory id: " << id << "  " << "num: " << num << endl;
	for (int i = 0; i < traj.size(); i++) {
		cout << "longitude: " << traj[i].lon << "  " << " latitude: " << traj[i].lat << " " << " time: " << traj[i].time << endl;
	}
	cout << endl;
}
