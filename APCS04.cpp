#include <iostream>
#define MAX_N 100000
using namespace std;

struct node {
	int data;
	int l, r;
	int lidx, ridx;
};

node ST[2*MAX_N];
int l[MAX_N+1], r[MAX_N+1];
int stptr = 0;

void build(int l, int r, int index) {
	ST[index].l = l, ST[index].r = r;
	if (l == r-1) {
		ST[index].data = 0;
	} else {
		int mid = (l+r) / 2;
		int lid = ST[index].lidx = ++stptr;
		int rid = ST[index].ridx = ++stptr;
		build(l, mid, lid);
		build(mid, r, rid);
		ST[index].data = ST[lid].data + ST[rid].data;
	}
}

void update(int x, int val, int index) {
	if (ST[index].l == ST[index].r-1) {
		ST[index].data = val;
	} else {
		int mid = (ST[index].l + ST[index].r) / 2;
		int lid = ST[index].lidx;
		int rid = ST[index].ridx;
		if (x < mid) update(x, val, lid);
		else update(x, val, rid);
		ST[index].data = ST[lid].data + ST[rid].data;
	}
}

long long sum(int l, int r, int index) {
	if (ST[index].l == l && ST[index].r == r) {
		return ST[index].data;
	} else {
		int mid = (ST[index].l + ST[index].r) / 2;
		int lid = ST[index].lidx;
		int rid = ST[index].ridx;
		if (l >= mid) return sum(l, r, rid);
		else if (r <= mid) return sum(l, r, lid);
		else return sum(l, mid, lid) + sum(mid, r, rid);
	}
}

int main() {
	int N, i, t;
	long long ans = 0;
	cin >> N;
	build(0, 2*N, 0);
	for (i = 0;i < 2*N;i++) {
		cin >> t;
		if (l[t] == 0) l[t] = i;
		else r[t] = i;
	}
	for (i = 1;i <= N;i++) {
		ans += sum(l[i], r[i]+1, 0);
		update(l[i], 1, 0);
		update(r[i], 1, 0);
	}
	cout << ans;
	return 0;
}
