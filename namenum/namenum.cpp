/*
ID: darrens1
LANG: C++11
TASK: namenum
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

map<int, vector<char>> phone = {	{2, {'A','B','C'}}, 
									{3, {'D','E','F'}},
									{4, {'G','H','I'}}, 
									{5, {'J','K','L'}}, 
									{6, {'M','N','O'}}, 
									{7, {'P','R','S'}}, 
									{8, {'T','U','V'}}, 
									{9, {'W','X','Y'}} };
unordered_map<string, bool> dic;
ofstream out("namenum.out");
bool none = true;

void generate_name(string num, string name) {
	if(num == "") {
		if(dic[name]) {
			out << name << endl;
			none = false;
		}
	}
	else {
		int digit = num[0] - '0';
		for(char c : phone[digit]) {
			generate_name(num.substr(1, num.size()-1), name + c);
		}
	}
}

int main() {
	ifstream in("namenum.in");
	ifstream dictf("dict.txt");

	string num;
	in >> num;
	
	while(!dictf.eof()) {
		string name;
		dictf >> name;
		if(name.size() == num.size()) {
			dic[name] = true;
		}
	}

	if(dic.size() == 1)
		out << dic.begin()->first << endl;
	else{
		generate_name(num, "");
		if(none)
			out << "NONE" << endl;
	}
	return 0;
}