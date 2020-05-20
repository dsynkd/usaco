/*
ID: darrens1
LANG: C++11
TASK: palsquare
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
	ifstream in("palsquare.in");
	ofstream out("palsquare.out");
	int B;
	in >> B;
	for(int x = 1; x < 300; x++) {
		string sqr = to_base(x*x, B);
		if(is_palindromic(sqr))
			out << to_base(x, B) << " " << sqr << endl;
	}
	return 0;
}