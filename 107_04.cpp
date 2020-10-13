#include<iostream>
#define MAX 1000
using namespace std;

int g[MAX+1][MAX+1];
int dp[MAX+2][MAX+2] = {0};

int main() {
	int m, n, i, j, mx = -2147483647;
	scanf("%d%d", &m, &n);
	for (i = 1;i <= m;i++) {
		for (j = 1;j <= n;j++) {
			scanf("%d", &g[i][j]);
		}
	}
	for (i = m;i >= 1;i--) {
		for (j = n;j >= 1;j--) {
			dp[i][j] = max(dp[i+1][j], dp[i][j+1]) + g[i][j];
			if (dp[i][j] > mx) mx = dp[i][j];
		}
	}
	printf("%d", mx);
	return 0;
}
