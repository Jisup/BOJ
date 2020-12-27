#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 100001
#define INF LLONG_MAX
int day, use;
int money[MAX];
//최대수치 잘못기록해서 틀렸었음
ll result = INF;
//전체 합산수 기록안해서 틀림
ll total;
bool usemoney(ll mid) {
	int point = 1;
	//자료형 변수 ll으로 전부 안맞춰줘서 틀림
	//전체 범위 1,000,000,000, int=2,147,483,647
	ll bank = mid;
	for (int i = 0; i < day; i++) {
		if (money[i] > mid) return false;
		if (bank >= money[i]) {
			bank -= money[i];
		}
		else {
			bank = mid;
			bank -= money[i];
			point++;
		}
	}
	return use >= point;
}
void solve() {
	//right의 최대범위가 10만개 배열에 각 1만원이 들어갔을경우가 최대
	ll left = 0, right = MAX*10000;
	while (left <= right) {
		//자료형안맞춰줌
		ll mid = (left + right) / 2;
		if (mid > total) {
			right = mid - 1; continue;
		}
		bool res = usemoney(mid);
		if (res) {
			result = result < mid ? result : mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> day >> use;
	for (int i = 0; i < day; i++) {
		cin >> money[i];
		total += money[i];
	}
	solve();
	cout << result;
}
