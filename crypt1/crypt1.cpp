/*
ID: darrens1
LANG: C++11
TASK: crypt1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream in("crypt1.in");
	ofstream out("crypt1.out");
	int N;
	vector<char> digits;
	in >> N;
	for(int x = 0; x < N; x++) {
		char digit;
		in >> digit;
		digits.push_back(digit);
	}
	int count = 0;
	/* construct possible digit combinations for A and B. calculate p1, p2 and answer. check for digits of each being contained in `digits` vector. incr count if true. */
	for(int a = 0; a < N; a++)
		for(int b = 0; b < N; b++)
			for(int c = 0; c < N; c++)
				for(int d = 0; d < N; d++)
					for(int e = 0; e < N; e++) {
						string A = { digits[a], digits[b], digits[c] };
						string B = { digits[d], digits[e] };
						int p1 = stoi(A) * (B[1] - '0');
						int p2 = stoi(A) * (B[0] - '0');
						int p = p1 + (p2 * 10);
						string p1_str = to_string(p1);
						string p2_str = to_string(p2);
						string p_str = to_string(p);
						bool valid = true;
						if(p1_str.length() != 3 || p2_str.length() != 3)
							valid = false;
						for(int x = 0; x < p1_str.length(); x++)
							if(find(digits.begin(), digits.end(), p1_str[x]) == digits.end())
								valid = false;
						for(int x = 0; x < p2_str.length(); x++)
							if(find(digits.begin(), digits.end(), p2_str[x]) == digits.end())
								valid = false;
						for(int x = 0; x < p_str.length(); x++)
							if(find(digits.begin(), digits.end(), p_str[x]) == digits.end())
								valid = false;
						if(valid)
							count++;
					}
	out << count << endl;
	return 0;
}