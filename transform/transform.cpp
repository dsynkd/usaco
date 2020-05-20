/*
ID: darrens1
LANG: C++11
TASK: transform
*/

#include <iostream>
#include <fstream>

using namespace std;

bool matrix_compare(char matrixA[][10], char matrixB[][10], int n) {
	for(int x = 0; x < n; x++)
		for(int y = 0; y < n; y++)
			if(matrixA[x][y] != matrixB[x][y])
				return false;
	return true;
}

int main() {
	ifstream in("transform.in");
	ofstream out("transform.out");
	int N;
	in >> N;
	
	char matrix[10][10];
	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			in >> matrix[x][y];
	
	char result[10][10];
	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			in >> result[x][y];

	char trans[10][10];
	
	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			trans[x][y] = matrix[N-y-1][x];
	if(matrix_compare(trans, result, N)) {
		out << 1 << endl;
		return 0;
	}
	
	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			trans[x][y] = matrix[N-x-1][N-y-1];
	if(matrix_compare(trans, result, N)) {
		out << 2 << endl;
		return 0;
	}

	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			trans[x][y] = matrix[y][N-x-1];
	if(matrix_compare(trans, result, N)) {
		out << 3 << endl;
		return 0;
	}

	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			trans[x][y] = matrix[x][N-y-1];
	if(matrix_compare(trans, result, N)) {
		out << 4 << endl;
		return 0;
	}

	char trans2[10][10];

	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			trans2[x][y] = trans[N-y-1][x];
	if(matrix_compare(trans2, result, N)) {
		out << 5 << endl;
		return 0;
	}
	
	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			trans2[x][y] = trans[N-x-1][N-y-1];
	if(matrix_compare(trans2, result, N)) {
		out << 5 << endl;
		return 0;
	}

	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			trans2[x][y] = trans[y][N-x-1];
	if(matrix_compare(trans2, result, N)) {
		out << 5 << endl;
		return 0;
	}

	
	if(matrix_compare(matrix, result, N)) {
		out << 6 << endl;
		return 0;
	}

	out << 7 << endl;
	return 0;
}