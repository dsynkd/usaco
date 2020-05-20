/*
ID: darrens1
LANG: C++11
TASK: friday
*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
	ifstream in("friday.in");
	ofstream out("friday.out");
	int n;
	in >> n;
	map<int,int> f13;
	for(int x = 0; x < 7; x++) {
		f13[x] = 0;
	}
	int weekday = 2;
	int year = 1900;
	int lastyear = year + n;
	while(year < lastyear) {
		int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		if(year % 100 != 0 && year % 4 == 0 || year % 400 == 0) {
			month_days[1] = 29;
		}
		int month = 0;
		while(month < 12) {
			int day = 1;
			while(day <= month_days[month]) {
				if(day == 13)
					f13[weekday]++;
				day++;
				weekday = (weekday + 1) % 7;
			}
			month++;
		}
		year++;
	}
	for(int x = 0; x < 7; x++) {
		out << f13[x];
		if(x != 6)
			out << " ";
	}
	out << endl;
	out.close();
	in.close();
	return 0;
}