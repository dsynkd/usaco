/*
ID: darrens1
LANG: C++11
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream in("ride.in");
	ofstream out("ride.out");
	string line;
	int comet_num = 1;
	in >> line;
	for(char c : line) {
		comet_num *= (c - 64);
	}
	int group_num = 1;
	in >> line;
	for(char c : line) {
		group_num *= (c - 64);
	}
	if(comet_num % 47 == group_num % 47)
		out << "GO" << endl;
	else
		out << "STAY" << endl;
	in.close();
	out.close();
	return 0;
}