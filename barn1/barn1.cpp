/*
ID: darrens1
LANG: C++11
TASK: barn1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream in("barn1.in");
	ofstream out("barn1.out");
	int M, S, C, c = 0;
	vector<int> stalls;
	vector<pair<int,int>> gaps;
	in >> M;
	in >> S;
	in >> C;
	while(c++ < C) {
		int stall;
		in >> stall;
		stalls.push_back(stall);
	}
	sort(stalls.begin(), stalls.end());
	c = 0;
	while(c++ < C) {
		int gap = stalls[c] - stalls[c - 1];
		if(gap > 1)
			gaps.push_back(pair<int,int>(stalls[c-1], gap));
	}
	/* number of boards = number of gaps. marge gaps until we have enough boards. stalls covered = C + gap size per merge. */
	while(gaps.size() + 1 > M) {
		sort(gaps.begin(), gaps.end(), [=](pair<int,int>& a, pair<int,int>& b) {
			return a.second < b.second;
		});
		C += gaps[0].second - 1;
		gaps.erase(gaps.begin(), gaps.begin() + 1);
	}
	out << C << endl;
	return 0;
}
