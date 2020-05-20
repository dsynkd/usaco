/*
ID: darrens1
LANG: C++11
TASK: dualpal
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string to_base(int num, int base)
{
	string digits("0123456789ABCDEFGHIJ");
	string result;
	for (; num; num /= base)
		result.insert(result.begin(), digits[abs(num % base)]);
	return result;
}

bool is_palindromic(string str) {
	int l = str.size();
	for(int x = 0; x < l; x++)
		if(str[x] != str[l-x-1])
			return false;
	return true;
}

int main() {
	ifstream in("dualpal.in");
	ofstream out("dualpal.out");
	int N, S;
	in >> N;
	in >> S;
	S++;
	while(N>0) {
		int pals = 0;
		for(int x = 2; x < 11 && pals < 2; x++) {
			if(is_palindromic(to_base(S,x)))
				pals++;
			if(pals >= 2) {
				out << S << endl;
				N--;
			}
		}
		S++;
	}
	return 0;
}