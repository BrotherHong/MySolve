#include<iostream>
#include<cmath>
#define MAX 1500000
using namespace std;
int ans[MAX+1] = {0};

int main() {
	int N, M, i, j;
	int w, v;
	int limit, max = 0;
	cin >> N >> M;
	limit = (int) pow(2, M);
	for (i = 0;i < N;i++) {
		cin >> w >> v;
		w = (int) pow(2, w);
		for (j = limit;j >= w;j--) {
			if (ans[j] < ans[j-w] + v) {
				ans[j] = ans[j-w] + v;
				if (ans[j] > max) max = ans[j];
			}
		}
	}
	cout << max;
	return 0;
}
