#include <iostream>
#include <algorithm>
#include <set>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 10001

int parent[MAX];
int want[MAX];

int find(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = find(parent[node]);
}
void Union(int fs_node, int se_node) {
	int fs = find(parent[fs_node]);
	int se = find(parent[se_node]);
	if (fs != se) {
		if (want[fs] < want[se])
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
	int friends, relation, money;
	cin >> friends >> relation >> money;
	int temp;
	for (int i = 0; i < friends; i++) {
		cin >> want[i];
		parent[i] = i;
	}
	for (int i = 0; i < relation; i++) {
		int a, b;
		cin >> a >> b;
		Union(a-1, b-1);
	}
	int cnt = 0;
	set<int>s;
	for (int i = 0; i < friends; i++) {
		int root = find(i);
		if (s.find(root) == s.end()) {
			s.insert(root);
			cnt += want[root];
		}
	}
	if (money >= cnt)
		cout << cnt;
	else
		cout << "Oh no";
}
