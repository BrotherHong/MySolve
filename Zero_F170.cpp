#include <iostream>
#include <queue>
#include <cmath>
#define MAX_N 1000
using namespace std;

typedef pair<int, int> pii;
int g[MAX_N+2][MAX_N+2];
bool visited[MAX_N+2][MAX_N+2];
int ans = 0;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	queue<pii> q;
	int N, sr, sc, i, j, x, y, xx, yy;
	cin >> N;
	cin >> sr >> sc;
	for (i = 1;i <= N;i++) {
		for (j = 1;j <= N;j++) {
			cin >> g[i][j];
		}
	}
	q.push(pii(sr+1, sc+1));
	visited[sr+1][sc+1] = true;
	while (!q.empty()) {
		ans++;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (i = 0;i < 4;i++) {
			xx = x + dir[i][0];
			yy = y + dir[i][1];
			if ((xx > 0 && yy > 0 && xx <= N && yy <= N) && !visited[xx][yy] && (abs(g[x][y] - g[xx][yy]) <= 2)) {
				q.push(pii(xx, yy));
				visited[xx][yy] = true;
			}
		}
	}
	cout << ans;
}
