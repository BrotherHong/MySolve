#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 500000
using namespace std;

int used[MAX+5] = {0};
vector<int> rsl;
vector<vector<int> > ans;

void solve(int rt, vector<int> &p) {
	int n = p[rt];
	while (n != rt) {
		rsl.push_back(n);
		used[n] = 1;
		n = p[n];
	}
	rsl.push_back(n);
	used[n] = 1;
	reverse(rsl.begin(), rsl.end());
}

int main() {
	int N, i, j;
	scanf("%d", &N);
	vector<int> pos(N+1);
	for (i = 1;i <= N;i++) {
		scanf("%d", &pos[i]);
	}
	for (i = 1;i <= N;i++) {
		if (!used[i]) {
			rsl.clear();
			solve(i, pos);
			if (rsl.size() > 1) ans.push_back(rsl);
		}
	}
	printf("%d\n", ans.size());
	for (i = 0;i < ans.size();i++) {
		printf("%d ", ans[i].size());
		for (j = 0;j < ans[i].size();j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}

