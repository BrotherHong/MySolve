#include<iostream>
#define MAX_LEN 1000
using namespace std;

int tree[MAX_LEN];
int arr[] = {1, 3, 5, 7, 9, 11};
int size = 6;

void build_tree(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	int left_node = 2*node + 1;
	int right_node = 2*node + 2;
	build_tree(left_node, start, mid);
	build_tree(right_node, mid+1, end);
}

void update(int node, int idx, int val, int start, int end) {
	if (start == end) {
		arr[idx] = val;
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	int left_node = 2*node + 1;
	int right_node = 2*node + 2;
	if (idx >= start && idx <= mid) { // left side
		update(left_node, idx, val, start, mid);
	} else { // right side
		update(right_node, idx, val, mid+1, end);
	}
	tree[node] = tree[left_node] + tree[right_node];
}

int sumRange(int node, int start, int end, int L, int R) {
	if (R < start || L > end) {
		return 0;
	} else if (L <= start && R >= end) {
		return tree[node];
	} else if (start == end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	int left_node = 2*node + 1;
	int right_node = 2*node + 2;
	int sum_left = sumRange(left_node, start, mid, L, R);
	int sum_right = sumRange(right_node, mid+1, end, L, R);
	return sum_left + sum_right;
}

int main() {
	build_tree(0, 0, size-1);
	cout << sumRange(4, 5);
	return 0;
}
