/*
ID: darrens1
LANG: C++11
TASK: milk
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/* THE MAP DOES NOT KEEP DUPLICATES U FUCKING IDIOT */

int main() {
	ifstream in("milk.in");
	ofstream out("milk.out");
	vector<pair<int,int>> shop;
	int n,m;
	in >> n;
	in >> m;
	while(m-->0) {
		int p,a;
		in >> p;
		in >> a;
		shop.push_back(pair<int,int>(p,a));
	}
	sort(shop.begin(), shop.end());
	int milk = 0, price = 0;
	for(pair<int,int> item : shop) {
		cout << item.first << " " << item.second << endl; 
		int milk_bought = min(n-milk, item.second);
		milk += milk_bought;
		price += item.first * milk_bought;
	}
	out << price << endl;
	return 0;
}