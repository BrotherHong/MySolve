#include<iostream>
#include<vector>
#include<cmath>
#define MAX 100000
using namespace std;
void f(int);
vector<int> child[MAX+1];
int h[MAX+1] = {0};
int parent[MAX+1] = {0};

// APCS 樹狀圖分析 
int main() {
	int n, i, j, amt, c, start;
	long long int total = 0;
	cin >> n;
	for (i = 1;i <= n;i++) {
		cin >> amt;
		for (j = 1;j <= amt;j++) {
			cin >> c;
			parent[c] = i;
			child[i].push_back(c);
		}
	}
	for (i = 1;i <= n;i++) if (parent[i] == 0) start = i;
	f(start);
	for (i = 1;i <= n;i++) total += h[i];
	cout << start << endl;
	cout << total;
	return 0;
}

void f(int p) {
	if (child[p].empty()) return;
	int i;
	for (i = 0;i < child[p].size();i++) {
		f(child[p][i]);
		h[p] = max(h[p], h[child[p][i]]+1);
	}
}
