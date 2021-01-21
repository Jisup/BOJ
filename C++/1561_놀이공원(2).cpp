#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 0
#define INF INT_MAX
ll child;
int game, temp;

vector<int>ary;

ll solve() {
	ll result = -1;
	//최대수치는 child의 30*까지 가능
	ll left = 0, right = child * 30;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = game;
		for (int i = 0; i < game; i++)
			sum += mid / ary[i];
		if (sum >= child) {
			result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return result;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> child >> game;
	for (int i = 0; i < game; i++) {
		cin >> temp;
		ary.push_back(temp);
	}
	if (child <= game) {
		cout << child;
		return 0;
	}
	ll time = solve();
	ll sum = game;
	for (int i = 0; i < game; i++)
		sum += (time - 1) / ary[i];
	for (int i = 0; i < game; i++) {
		if (time%ary[i] == 0)
			sum++;
		if (sum == child) {
			cout << i + 1;
			return 0;
		}
	}
}
