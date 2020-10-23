#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

int N, M;

bool isValid(string s) {
	int len = s.length();
	int star = 0;
	if (len != N) return false;
	for (int i = 0;i < len;i++) {
		if (s[i] == '*') star++;
		if (s[i] != '0' && s[i] != '*') {
			return false;
		}
	}
	if (star > M) return false;
	return true;
}

typedef struct Person {
	string name;
	int vote;
} P;

P p[MAX_N];

bool comp(P p1, P p2) {
	string s1, s2;
	s1 = p1.name;
	s2 = p2.name;
	for (int i = 0;i < s1.length();i++) {
		for (int j = 0;j < s2.length();j++) {
			if (s1[i] != s2[j]) return s1[i] < s2[j];
		}
	}
}

int main() {
	int i, j, V;
	string s;
	cin >> N >> M;
	for (i = 0;i < N;i++) {
		cin >> p[i].name;
		p[i].vote = 0;
	}
	cin >> V;
	for (i = 0;i < V;i++) {
		cin >> s;
		if (isValid(s)) {
			for (j = 0;j < N;j++) {
				if (s[j] == '*') p[j].vote++;
			}
		}
	}
	sort(p, p+N, comp);
	for (i = 0;i < N;i++) {
		cout << p[i].name << " " << p[i].vote << endl;
	}
	return 0;
}

/*
2 1
Panda
Cat
5
0*
1*
*0
0*
#0

ans:
Cat 2
Panda 1

3 2
Sam
Tony
Tom
5
*00
**1
***
0*0
00*

ans:
Sam 1
Tom 1
Tony 1
*/
