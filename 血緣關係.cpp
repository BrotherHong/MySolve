#include <iostream>
#include <vector>
#define MAX 100000
using namespace std;

void dfs(int,int);

int arr[MAX];
vector<int> cnt[MAX];

int main() {
	int n, i, a, b, index, mx;
	while (1) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin >> n;
		if (cin.fail()) break;
		// init
		for (i = 0;i < n;i++) {
			cnt[i].clear();
			arr[i] = 0;
		}
		for (i = 0;i < n-1;i++) {
			cin >> a >> b;
			cnt[a].push_back(b);
			cnt[b].push_back(a);
		}
		dfs(0, -1);
		index = 0, mx = 0;
		for (i = 0;i < n;i++) {
			if (arr[i] > mx) {
				mx = arr[i];
				index = i;
			}
		}
		//reset
		for (i = 0;i < n;i++) {
			arr[i] = 0;
		}
		dfs(index, -1);
		mx = 0;
		for (i = 0;i < n;i++) {
			if (arr[i] > mx) {
				mx = arr[i];
			}
		}
		cout << mx << "\n";
	}
	return 0;
}

void dfs(int now, int prev) {
	int i;
	int size = cnt[now].size();
	for (i = 0;i < size;i++) {
		if (cnt[now][i] != prev) {
			arr[cnt[now][i]] = arr[now] + 1;
			dfs(cnt[now][i], now);
		}
	}
} 
