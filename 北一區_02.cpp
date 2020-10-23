#include <iostream>
#define MAX_N 100
using namespace std;

int g[MAX_N+1][MAX_N+1];
int dp[MAX_N+1][MAX_N+1];
char from[MAX_N+1][MAX_N+1];

int main() {
	int n, i, j;
	string path = "";
	cin >> n;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= i;j++) {
			cin >> g[i][j];
		}
	}
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= i;j++) {
			if (dp[i-1][j] == dp[i][j-1]) {
				dp[i][j] = dp[i][j-1] + g[i][j];
				from[i][j] = 'S';
			} else if (dp[i-1][j] > dp[i][j-1]) {
				dp[i][j] = dp[i-1][j] + g[i][j];
				from[i][j] = 'S';
			} else {
				dp[i][j] = dp[i][j-1] + g[i][j];
				from[i][j] = 'E';
			}
		}
	}
	i = j = n;
	from[1][1] = 'E';
	while (i != 1 || j != 0) {
		//cout << "i: " << i << " j: " << j << endl;
		path = from[i][j] + path;
		switch (from[i][j]) {
			case 'S':
				i--;
				break;
			case 'E':
				j--;
				break;
		}
	}
	path += 'E';
	cout << path << endl;
	cout << dp[n][n];
	return 0;
}

/*
5
5
4 8
3 2 1
8 3 4 5
2 2 6 3 5

ans: ESSSEESEEE 41

3
3
2 1
1 2 4

ans: ESESEE 12
*/
