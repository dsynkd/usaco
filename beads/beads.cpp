/*
ID: darrens1
LANG: C++11
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream in("beads.in");
	ofstream out("beads.out");
	int n, index = 0, maxBeads = 0, beadsCount = 0;
	char curBead;
	string beads;
	bool zzz = false, counting = true, over = false;
	in >> n;
	in >> beads;
	while(counting) {
		if(!curBead || curBead == 'w') {
			curBead = beads[index++];
			beadsCount++;
			continue;
		}
		if(index >= n && !over) {
			index = 0;
			over = true;
		}
		if(beadsCount >= n) {
			maxBeads = n;
			break;
		}
		char tempBead = beads[index++];
		if(tempBead == 'w' || tempBead == curBead) {
			beadsCount++;
		}
		else if(!zzz) {
			zzz = true;
			curBead = tempBead;
			beadsCount++;
		}
		else {
			zzz = false;
			if(beadsCount > maxBeads)
				maxBeads = beadsCount;
			beadsCount = 0;
			if(over) {
				counting = false;
			}
		}
	}
	out << maxBeads << endl;
	return 0;
}
