#include<iostream>
#include<cstring>
#define MAX 1000
using namespace std;
void dfs(int,int,int);

int maze[MAX+2][MAX+2];
int visited[MAX+2][MAX+2] = {0};
int from[MAX+2][MAX+2];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int Rd, Cd;

int main() {
	memset(maze, -1, sizeof(maze));
	int R, C, N, i, j, Rs, Cs, r, c, lv, xx, yy, x, y;
	scanf("%d%d", &R, &C);
	scanf("%d%d%d%d", &Rs, &Cs, &Rd, &Cd);
	scanf("%d", &N);
	for (i = 1;i <= N;i++) {
		scanf("%d%d%d", &r, &c, &lv);
		maze[r+1][c+1] = lv;
	}
	maze[Rs+1][Cs+1] = 0;
	maze[Rd+1][Cd+1] = 2147483647;
	dfs(Rs+1, Cs+1, 0);
	cout << maze[Rd+1][Cd+1];
	return 0;
}

void dfs(int r, int c, int mxlv) {
	if (r == Rd+1 && c == Cd+1) {
		maze[r][c] = min(maze[r][c], mxlv);
		return;
	}
	if (maze[r][c] == -1 || visited[r][c]) return;
	if (mxlv >= maze[Rd+1][Cd+1]) return;
	mxlv = max(mxlv, maze[r][c]);
	visited[r][c] = 1;
	for (int i = 0;i < 4;i++) {
		dfs(r+dir[i][0], c+dir[i][1], mxlv);
	}
	visited[r][c] = 0;
}
