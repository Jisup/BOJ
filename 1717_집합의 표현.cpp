#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 1000001

int Size, tc;

int parent[MAX];

int find(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = find(parent[node]);
}
void Union(int fs_node, int se_node) {
	int fs = find(fs_node);
	int se = find(se_node);
	if (fs != se) {
		if (parent[fs] < parent[se])
			swap(fs, se);
		parent[fs] = se;
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> Size >> tc;
	for (int i = 0; i <= Size; i++) {
		parent[i] = i;
	}
	while (tc-- > 0) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!a) {
			Union(b, c);
		}
		else {
			int b_root = find(b);
			int c_root = find(c);
			b_root == c_root ? cout << "YES\n" : cout << "NO\n";
		}
	}
}
