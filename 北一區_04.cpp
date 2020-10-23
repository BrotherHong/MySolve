#include<iostream>
#define MAX 500
using namespace std;

int g[MAX][MAX];
int R, C;

bool isValid(int r, int c) {
	int i, j;
	bool valid = true;
	for (i = 0;i < R;i++) {
		if (g[i][c] && i != r) {
			g[i][c] = -1;
			valid = false;
		}
	}
	for (j = 0;j < C;j++) {
		if (g[r][j] && j != c) {
			g[i][c] = -1;
			valid = false;
		}
	}
	i = r-min(r, c);
	j = c-min(r, c);
	for (;i < R && j < C;i++, j++) {
		if (g[i][j] && i != r && j != c) {
			g[i][j] = -1;
			valid = false;
		}
	}
	i = r-min(r, C-c-1);
	j = c+min(r, C-c-1);
	for (;i < R && j >= 0;i++, j--) {
		if (g[i][j] && i != r && j != c) {
			g[i][j] = -1;
			valid = false;
		}
	}
	return valid;
}

int main() {
	int i, j;
	string s;
	cin >> R >> C;
	for (i = 0;i < R;i++) {
		cin >> s;
		for (j = 0;j < C;j++) {
			g[i][j] = (s[j] == 'x');
		}
	}
	for (i = 0;i < R;i++) {
		for (j = 0;j < C;j++) {
			if (g[i][j] == 0) continue;
			if (g[i][j] == -1) {
				cout << "(" << i << "," << j << ")";
			} else {
				if (!isValid(i, j)) {
					cout << "(" << i << "," << j << ")";
				}
			}
		}
	}
	return 0;
}

/*
5 6
xooooo
ooxoox
ooooxo
oxoooo
oooxoo

2 3
oxo
xoo
*/

