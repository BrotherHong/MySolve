#include<iostream>
#include<cstring>
#define MAX 100
#define LIMIT 100
using namespace std;

int main() {
	int v[MAX];
	int c[MAX];
	int ans[MAX+1];
	int N, i, j, max;
	while (1) {
		memset(ans, 0, sizeof(ans));
		max = 0;
		cin >> N;
		if (cin.fail()) break;
		for (i = 0;i < N;i++) {
			cin >> v[i] >> c[i];
		}
		for (i = 0;i < N;i++) {
			for (j = LIMIT;j >= v[i];j--) {
				if (ans[j] < ans[j-v[i]] + c[i]) {
					ans[j] = ans[j-v[i]] + c[i];
					if (ans[j] > max) max = ans[j];
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}
