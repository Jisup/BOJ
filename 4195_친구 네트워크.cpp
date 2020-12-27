#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 200001

int parent[MAX];
int SetSize[MAX];

int find(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = find(parent[node]);
}
void Union(int fs_node, int se_node) {
	int fs = find(fs_node);
	int se = find(se_node);
	if (fs != se) {
		//큰 집합으로 작은집합이 합쳐짐
		if (SetSize[fs] < SetSize[se])
			swap(fs, se);
		parent[se] = fs;
		SetSize[fs] += SetSize[se];
		SetSize[se] = 0;
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while (tc-- > 0) {
		int friends;
		cin >> friends;

		//초기화 : RootNode는 자기자신으로 돌아오도록한다.
		//전체 각 Node는 자기자신 (1)을 크기로 한다.
		for (int i = 0; i < MAX; i++) {
			parent[i] = i;
			SetSize[i] = 1;
		}
		
		map <string, int> m;
		//모든 Root의 Index는 1부터시작하도록 서설정
		int index = 1;
		for (int i = 0; i < friends; i++) {
			string temp1, temp2;
			cin >> temp1 >> temp2;
			if (!m[temp1])
				m[temp1] = index++;
			if (!m[temp2])
				m[temp2] = index++;

			int t1_root = find(m[temp1]);
			int t2_root = find(m[temp2]);
			
			if (t1_root == t2_root)
				cout << max(SetSize[t1_root], SetSize[t2_root]) << endl;
			else {
				Union(t1_root, t2_root);
				cout << max(SetSize[t1_root], SetSize[t2_root]) << endl;
			}
		}
	}
}
