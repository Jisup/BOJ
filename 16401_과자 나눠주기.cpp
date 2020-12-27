#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 1000001

int child, s;
int snak[MAX];
int res;
int give(int mid) {
	int result = 0;
	for (int i = 0; i < s; i++)
		result += snak[i] / mid;
	return result < child;
}

void solve() {
	int left = 1, right = snak[s - 1];
	while (left <= right) {
		int mid = (left + right) / 2;
		if (give(mid)) { // 작거나 같다면
			right = mid - 1;
		}
		else {
			res = res > mid ? res : mid;
			left = mid + 1; 
		}
	}
	cout << res;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> child >> s;
	for (int i = 0; i < s; i++)
		cin >> snak[i];
	sort(snak, snak + s);
	solve();
}
