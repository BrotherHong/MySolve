#include<iostream>
#include<vector>
#define MAX 10
using namespace std;
typedef pair<int, int> pii;

int R, C, type, ans = 0;
vector<pii> avail;
int g[MAX+5][MAX+5] = {0};
int king[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
				, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

void set_queen(int r, int c) {
	int i, j, mn;
	// left to right
	for (i = 1;i <= C;i++) g[r][i] = -1;
	// up to down
	for (i = 1;i <= R;i++) g[i][c] = -1;
	// left-up to right-down
	mn = min(r, c);
	for (i=r-mn+1, j=c-mn+1;i<=R && j<=C;i++, j++) {
		g[i][j] = -1;
	}
	// right-up to left-down
	mn = min(r, C-c);
	for (i=r-mn, j=c+mn;i<=R && j>=1;i++, j--) {
		g[i][j] = -1;
	}
	g[r][c] = 1;
}

void set_king(int r, int c) {
	set_queen(r, c);
	int i, rr, cc;
	for (i = 0;i < 8;i++) {
		rr = r+king[i][0], cc = c+king[i][1];
		if (1<=rr && rr<=R && 1<=cc && cc<=C) {
			g[rr][cc] = -1;
		}
	}
	g[r][c] = 2;
}

bool check_queen(int r, int c) {
	int i, j, mn;
	// left to right
	for (i = 1;i <= C;i++) if (g[r][i] > 0 && i != c) return false;
	// up to down
	for (i = 1;i <= R;i++) if (g[i][c] > 0 && i != r) return false;
	// left-up to right-down
	mn = min(r, c);
	for (i=r-mn+1, j=c-mn+1;i<=R && j<=C;i++, j++) {
		if (g[i][j] > 0 && i!=r && j!=c) return false;
	}
	// right-up to left-down
	mn = min(r, C-c);
	for (i=r-mn, j=c+mn;i<=R && j>=1;i++, j--) {
		if (g[i][j] > 0 && i!=r && j!=c) return false;
	}
	return true;
}

bool check_king(int r, int c) {
	bool q = check_queen(r, c);
	if (!q) return false;
	int i, rr, cc;
	for (i = 0;i < 8;i++) {
		rr = r+king[i][0], cc = c+king[i][1];
		if (1<=rr && rr<=R && 1<=cc && cc<=C) {
			if (g[rr][cc] > 0) return false;
		}
	}
	return true;
}

void Enum(int idx, int amt) {
	int i, x, y;
	for (i = idx+1;i < avail.size();i++) {
		x = avail[i].first;
		y = avail[i].second;
		if (type == 1) {
			if (check_queen(x, y)) {
				g[x][y] = 3;
				Enum(i, amt+1);
				g[x][y] = 0;
			}
		} else {
			if (check_king(x, y)) {
				g[x][y] = 3;
				Enum(i, amt+1);
				g[x][y] = 0;
			}
		}
	}
	ans = max(ans, amt);
}

int main() {
	int K, x, y, t, i, j;
	scanf("%d%d%d%d", &R, &C, &K, &type);
	for (i = 0;i < K;i++) {
		scanf("%d%d%d", &x, &y, &t);
		if (t == 1) set_queen(x, y);
		else set_king(x, y);
	}
	for (i = 1;i <= R;i++) {
		for (j = 1;j <= C;j++) {
			if (g[i][j] == 0) avail.push_back(pii(i, j));
		}
	}
	Enum(-1, 0);
	printf("%d", ans);
	return 0;
}

