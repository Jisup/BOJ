
#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
int total, lion;
int result = INF;
vector<int>start;
void solve() {
	int left = 0, right = 0;
	int cnt = 1;
	while (left <= right && right<start.size()) {
		if (cnt < lion) {
			right++;
			cnt++;
		}
		else {
			if (cnt == lion) {
				int index = start[right] - start[left] + 1;
				result = result < index ? result : index;
			}
			left++;
			cnt--;
		}
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> total >> lion;
	int temp;
	for (int i = 0; i < total; i++) {
		cin >> temp;
		if (temp == 1)start.push_back(i);
	}
	solve();
	if (result == INF)
		cout << -1;
	else
		cout << result;
}
