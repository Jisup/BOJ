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
	//�ִ������ ������� ����ū �ɻ�뿡�� �ð����������̴�
	ll left = 0, right = cp[Size - 1] * people;
	//���ذ� ����� �ð���
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll res = 0;
		//�Ǵܰ��� �ɻ��ο��� �ð�
		//�ɻ�ð����־��� ��, �ð����� �� �Ա��ɻ�밡 ����� ����Ҽ� �ִ� �ο�����
		//�ð�/�Ա��ɻ�ð�=�ð��� ó�����ɾ� ����ο��� �ȴ�
		//�� ��üó�������ο���, ����Ա��ɻ�밡 ���ѽð����� ����Ҽ� �ִ� �ο��� ���� ������̰�,
		//�� ������� �Ա��ɻ縦 �޴� ������ ������ ��, ������̳�����
		//�� ������� �� �ּҰ��� �ּҽð��� �ǰԵȴ�.
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
