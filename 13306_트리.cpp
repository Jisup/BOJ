/*
#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 200001

int parent[MAX];
vector <int> v[MAX];
bool check[MAX];

int find(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = find(parent[node]);
}

void update(int node) {
	parent[node] = node;
	queue <int> q;
	q.push(node);
	while (!q.empty()) {
		int out = q.front(); q.pop();
		for (int i = 0; i < v[out].size(); i++) {
			if (!check[v[out][i]]) {
				parent[out] = node;
				q.push(v[out][i]);
			}
		}
	}
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int spot, quest;
	cin >> spot >> quest;

	parent[1] = 1;
	for (int i = 2; i <= spot; i++) {
		cin >> parent[i];
		v[parent[i]].push_back(i);
	}
	int temp;
	while (cin >> temp) {
		int a, b;
		if (temp) {
			cin >> a >> b;
			find(a) == find(b) ? cout << "YES\n" : cout << "NO\n";
		}
		else {
			cin >> a;
			check[a] = true;
			update(a);
		}
	}
}
*/