#include<iostream>
#include<cstdio>
#define MAX 1000
using namespace std;

int main() {
	int a, N, x, y, i, j, mx = 0, mxcost;
	int dp[MAX+1] = {0};
	scanf("%d%d", &a, &N);
	for (i = 0;i < N;i++) {
		scanf("%d%d", &x, &y);
		for (j = a;j >= y;j--) {
			dp[j] = max(dp[j], dp[j-y]+x);
			if (dp[j] >= mx) {
				mx = dp[j];
				mxcost = j;
			}
		}
	}
	printf("%d %d\n", mx, mxcost);
	return 0;
}
