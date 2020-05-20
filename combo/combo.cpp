/*
ID: darrens1
LANG: C++11
TASK: combo
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ifstream in("combo.in");
	ofstream out("combo.out");
	int N, a, b, c, count = 0;
	vector<vector<int>> lock;
	in >> N;
	in >> a;
	in >> b;
	in >> c;
	vector<int> farmers_lock = {a, b, c};
	lock.push_back(farmers_lock);
	in >> a;
	in >> b;
	in >> c;
	vector<int> masters_lock = {a, b, c};
	lock.push_back(masters_lock);
	vector<vector<int>> tuples;
	for(int l = 0; l < 2; l++)
		for(int x = -2; x <= 2; x++)
			for(int y = -2; y <= 2; y++)
				for(int z = -2; z <= 2; z++) {
					vector<int> new_tuple;
					new_tuple.push_back(lock[l][0] + x);
					new_tuple.push_back(lock[l][1] + y);
					new_tuple.push_back(lock[l][2] + z);
					for(int i = 0; i < new_tuple.size(); i++)
						if(new_tuple[i] < 1)
							new_tuple[i] = new_tuple[i] + N;
						else if(new_tuple[i] > N)
							new_tuple[i] = new_tuple[i] % N;
					if(new_tuple[0] <= N && new_tuple[0] > 0 && new_tuple[1] <= N && new_tuple[1] > 0 && new_tuple[2] <= N && new_tuple[2] > 0) {
						bool dup = false;
						for(int i = 0; i < tuples.size(); i++) {
							vector<int> tuple = tuples[i];
							if(tuple[0] == new_tuple[0] && tuple[1] == new_tuple[1] && tuple[2] == new_tuple[2])
								dup = true;
						}
						if(!dup) {
							tuples.push_back(new_tuple);
							count++;
						}
					}
				}
	out << count << endl;
	return 0;
}
