#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 10001


int total, tc;
int start, finish;

ll weight = -1;
bool check[MAX];

vector <pair<int, ll> > v[MAX];

bool search(ll cost){
	queue <int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int out = q.front(); q.pop();
		if (out == finish) return true;
		for (int i = 0; i < v[out].size(); i++) {
			int ni = v[out][i].first;
			ll nw = v[out][i].second;
			//������ �ڽ�Ʈ�� ������������ �� �� �ִ��� �Ǻ��ϴ� ��������
			if (!check[ni] && cost <= nw) {
				check[ni] = true;
				q.push(ni);
			}
		}
	}
	return false;
}
void solve() {
	ll result = -1;
	ll left = 0, right = weight;
	//�� ������ �ּ� �ִ븦 �������� �̺�Ž���� ã�Ƴ��°��� �̹����� �ٽ�
	//��ó���� ���ͽ�Ʈ��� Ǯ������, �ٸ������� �迭 10000x10000 �������� �޸��ʰ�
	while (left <= right) {
		memset(check, 0, sizeof check);
		ll mid = (left + right) / 2;
		if (search(mid)) {
			result = result > mid ? result : mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << result;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> total >> tc;
	while (tc-- > 0) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
		weight = weight > c ? weight : c;
	}
	cin >> start >> finish;
	solve();
}
