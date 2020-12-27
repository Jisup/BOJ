#include <iostream>
#include <algorithm>

#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 201

int parent[MAX];

int find(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = find(parent[node]);
}
void Union(int fs_node, int se_node) {
	int fs = find(parent[fs_node]);
	int se = find(parent[se_node]);
	parent[fs] = se;
}

bool check[MAX];
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int city, travle;
	cin >> city;
	for (int i = 0; i < city; i++)
		parent[i] = i;
	cin >> travle;
	int temp;
	for (int i = 0; i < city; i++) {
		for (int k = 0; k < city; k++) {
			cin >> temp;
			if (temp) {
				//cout << "Before: " <<  find(i) << tap << find(k) << endl;
				Union(i, k);
				//cout << "After: " <<find(i) << tap << find(k) << endl;
			}
		}
	}
	int yet_root;
	for (int i = 0; i < travle; i++) {
		cin >> temp;
		if (!check[temp - 1]) {
			check[temp - 1] = true;
			if (i == 0) yet_root = find(temp - 1);
			if (yet_root != find(temp - 1)) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}
