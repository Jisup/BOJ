

#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define LLM LLONG_MAX
#define fs first
#define se second
#define MAX 100001

int ea;
ll high;
ll res = LLM;
ll num[MAX];
void solve() {
	sort(num, num + ea, less<ll>());

	int left = 0, right = 1;
	while (right < ea) {
		ll result = num[right] - num[left];
		if (result < high) right++;
		else {
			left++;
			res = min(res, result);
		}
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> ea >> high;
	for (int i = 0; i < ea; i++)
		cin >> num[i];
	solve();
	cout << res;
}
