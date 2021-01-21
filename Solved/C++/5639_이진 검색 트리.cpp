
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 1000001

typedef struct data {
	int left;
	int right;
}node;
node tree[MAX];
int input[10001];
void make(int now, int index) {
	if (now < index) {
		if (tree[now].right != 0) {
			make(tree[now].right, index);
		}
		else {
			tree[now].right = index;
		}
	}
	else if (now > index) {
		if (tree[now].left != 0) {
			make(tree[now].left, index);
		}
		else {
			tree[now].left = index;
		}
	}
}
void post_order(int node) {
	if (node == 0) return;
	post_order(tree[node].left);
	post_order(tree[node].right);
	cout << node << endl;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int first;
	cin >> first;
	while (true) {
		int in = -1;
		cin >> in;
		if (in == -1)break;
		make(first, in);
	}
	post_order(first);
}
