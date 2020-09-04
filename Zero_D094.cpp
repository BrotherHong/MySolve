#include<iostream>
#include<cstring>
#define MAX 1000
using namespace std;
int ans[MAX+1];

int main() {
	memset(ans, 111, sizeof(ans));
	ans[0] = 0;
	int C, N, i, j;
	cin >> C >> N;
	int coin;
	for (i = 0;i < N;i++) {
		cin >> coin;
		for (j = coin;j <= C;j++) {
			if (ans[j] > ans[j-coin] + 1) {
				ans[j] = ans[j-coin] + 1;
			}
		}
	}
	cout << ans[C];
	return 0;
}
