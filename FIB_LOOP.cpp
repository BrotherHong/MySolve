#include<stdio.h>

int f(int);

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
}

int f(int n) {
	if (n == 0 || n == 1) return n;
	int num[n+1], i;
	num[0] = 0;
	num[1] = 1;
	for (i = 2;i <= n;i++) {
		num[i] = num[i-1] + num[i-2];
	}
	return num[n];
}
