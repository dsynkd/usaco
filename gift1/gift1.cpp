/*
ID: darrens1
LANG: C++11
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	ifstream in("gift1.in");
    ofstream out("gift1.out");
	int t;
	in >> t;
	map<string, int> wallet;
	vector<string> dudez;
	int c = 0;
	string dude;
	while(c++ < t) {
		in >> dude;
		wallet.insert(wallet.begin(), pair<string, int>(dude, 0));
		dudez.push_back(dude);
	}
	c = 0;
	while(c++ < t) {
		int gift, given;
		in >> dude;
		in >> gift;
		wallet[dude] -= gift;
		in >> given;
		if(given != 0)
			wallet[dude] += (gift%given);
		int z = 0;
		while(z++ < given) {
			in >> dude;
			wallet[dude] += (gift/given);
		}
	}
	for(string dude : dudez) {
		out << dude << " " << wallet[dude] << endl;
	}
    out.close();
    in.close();
	return 0;
}