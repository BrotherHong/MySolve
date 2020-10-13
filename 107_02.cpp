#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define MAX 1000
using namespace std;
void comp();

int maze[MAX+2][MAX+2];
int visited[MAX+2][MAX+2] = {0};
int from[MAX+2][MAX+2];
// ¤W0 ¥ª1 ¤U2 ¥k3
vector<pair<int,int>> road;

int main() {
	int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	queue<pair<int,int> > q;
	memset(maze, 111, sizeof(maze));
	cout << maze[0][0];
	int R, C, N, i, j, Rs, Cs, Rd, Cd, r, c, lv, xx, yy;
	int ans = 2147483647, mx;
	scanf("%d%d", &R, &C);
	scanf("%d%d%d%d", &Rs, &Cs, &Rd, &Cd);
	scanf("%d", &N);
	for (i = 1;i <= N;i++) {
		scanf("%d%d%d", &r, &c, &lv);
		maze[r+1][c+1] = lv;
	}
	q.push({Rs, Cs});
	while (!q.empty()) {
		xx = q.front().first;
		yy = q.front().second;
		for (i = 0;i < 4;i++) {
			if (maze[xx+dir[i][0]][yy+dir[i][i]] != -1) {
				road.push_back({xx+dir[i][0], yy+dir[i][i]});
			}
		}
		comp();
	}
	return 0;
}

void comp() {
	
}
