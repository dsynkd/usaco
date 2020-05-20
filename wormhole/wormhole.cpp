/*
ID: darrens1
LANG: C++11
TASK: wormhole
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ifstream in("wormhole.in");
	ofstream out("wormhole.out");
	int n, temp1, temp2, c = 0;
	vector<int> x;
	in >> n;
	for(int i = 0; i < n; i++) {
		in >> temp1;
		in >> temp2;
		int s = x.size();
		bool f = false;
		for(int j = 0; j < s; j++) {
			if(x[j] == temp1) {
				c++;
				f = true;
			}
		}
		if(!f)
			x.push_back(temp1);
	}
	out << c << endl;
	return 0;
}
