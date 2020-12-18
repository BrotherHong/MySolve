#include<cstdio>
#include<unordered_map>
using namespace std;

unordered_map<int, int> og;
unordered_map<int, int> buy;

int main() {
	int N, M, t, k, i;
	scanf("%d%d", &N, &M);
	for (i = 0;i < N;i++) {
		scanf("%d", &t);
		og[t]++;
	}
	for (i = 0;i < M;i++) {
		scanf("%d%d", &t, &k);
		if (t == 0) { // fly away
			if (buy[k] == 0) {
				if (og[k] != 0) og[k]--, N--;
			} else buy[k]--;
		} else { // buy
			buy[k]++;
		}
	}
	unordered_map<int, int>::iterator it = og.begin();
	printf("%d\n", N);
	for (;it != og.end();it++) {
		int n = it->first;
		int m = it->second;
		for (i = 1;i <= m;i++) {
			printf("%d ", n);
		}
	}
	return 0;
}

