#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100000
using namespace std;

int dfs(int,int);

int *s[MAX];
vector<int> cnt[MAX];

int start, dest, dtc;
bool flag;

int main() {
	int n, m, i, j, a, b;
	for (i = 0;i < MAX;i++) s[i] = new int[MAX];
	cin >> n >> m;
	for (i = 0;i < n;i++){
		for (j = 0;j < n;j++) {
			s[i][j] = 0;
			s[j][i] = 0;
		}
	}
	for (i = 0;i < n-1;i++) {
		cin >> a >> b;
		cnt[a].push_back(b);
		cnt[b].push_back(a);
		s[a][b] = 1;
		s[b][a] = 1;
	}
	for (i = 0;i < m;i++) {
		cin >> start >> dest;
		dtc = 0;
		flag = false;
		cout << dfs(start, -1) << '\n';
	}
	return 0;
}

int dfs(int now, int prev) {
	if (s[now][dest] != 0) {
		flag = true;
		return s[now][dest];
	}
	int i, h = 0, curr;
	for (i = 0;i < cnt[now].size();i++) {
		curr = cnt[now][i];
		if (curr != prev) {
			h = dfs(curr, now);
			if (flag) {
				s[now][dest] = h+1;
			}
		}
	}
	return h+1;
}
