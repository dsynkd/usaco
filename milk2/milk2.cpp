/*
ID: darrens1
LANG: C++11
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream in;
	ofstream out;
	in.open("milk2.in");
	out.open("milk2.out");
	int n;
	in >> n;
	int c = 0;
	vector<int> v1,v2;
	while(c<n) {
		int t1, t2;
		in >> t1;
		in >> t2;
		vector<int>::iterator it1 = v1.begin(), it2 = v2.begin();
		for(; it2 != v2.end(); ++it2, ++it1) {
			if(t2 < *it2)
				break;
		}
		v1.insert(it1, t1);
		v2.insert(it2, t2);
		c++;
	}
	c--;
	int totalMilk = 0, maxMilk = 0, maxIdle = 0, earliest_start = v1[c], latest_finish = v2[c];
	while(c>=0) {
		if(v2[c] < earliest_start) {
			if(earliest_start - v2[c] > maxIdle)
				maxIdle = earliest_start - v2[c];
			latest_finish = v2[c];
			earliest_start = v1[c];
		}
		else if(v1[c] < earliest_start) {
			earliest_start = v1[c];
		}
		if(latest_finish - earliest_start > maxMilk)
			maxMilk = latest_finish - earliest_start;
		c--;
	}
	out << maxMilk << " " << maxIdle << endl;
	out.close();
	in.close();
	return 0;
}