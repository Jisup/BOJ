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

int checkpoint, people;

vector <ll> cp;
ll result=LLONG_MAX;
void solve() {
	int Size = cp.size();
	//최대범위는 모든사람이 제일큰 심사대에서 시간을보낼때이다
	ll left = 0, right = cp[Size - 1] * people;
	//기준과 결과는 시간값
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll res = 0;
		//판단값은 심사인원과 시간
		//심사시간이주어질 때, 시간내에 각 입국심사대가 사람을 허용할수 있는 인원수는
		//시간/입국심사시간=시간내 처리가능안 허용인원이 된다
		//즉 전체처리가능인원은, 모든입국심사대가 제한시간내에 허용할수 있는 인원의 합이 결과값이고,
		//그 결과값이 입국심사를 받는 사람들과 동일할 때, 결과값이나오고
		//그 결과값들 중 최소값이 최소시간이 되게된다.
		for (int i = 0; i < Size; i++) {
			res += mid / cp[i];
		}
		//cout << left << tap << right << tap << mid << tap << res << endl;
		if (res >= people) {
			result = result < mid ? result : mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << result;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> checkpoint >> people;
	for (int i = 0; i < checkpoint; i++) {
		ll temp;
		cin >> temp;
		cp.push_back(temp);
	}
	sort(cp.begin(), cp.end());
	solve();
}
