#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 20001

int spot, load;
int point[MAX];
bool check[MAX];
vector<int> v[MAX];
void solve() {
	memset(point, 0, sizeof point);
	for (int i = 1; i <= spot; i++) {
		queue <int> q;
		if (!point[i]) {
			point[i] = 1;
			q.push(i);
			while (!q.empty()) {
				int out = q.front(); q.pop();
				int check = point[out] == 1 ? 2 : 1;
				for (int k = 0; k < v[out].size(); k++) {
					int next = v[out][k];
					if (!point[next]) {
						point[next] = check;
						q.push(next);
					}
				}
			}
		}
	}
	for (int i = 1; i <= spot; i++) {
		for (int k = 0; k < v[i].size(); k++) {
			int next = v[i][k];
			if (point[i] == point[next]) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
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
		memset(point, 0, sizeof point);
		cin >> spot >> load;
		for (int i = 0; i <= spot; i++)
			v[i].clear();

		for (int i = 0; i < load; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			//왜 양방향이냐구~~~
			v[b].push_back(a);
		}
		solve();
	}
}
