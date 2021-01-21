#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define ll long long

int total, local;
vector <int> prime;
map <ll, int> m;
priority_queue <ll, vector<ll>, greater<ll> > q;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> total >> local;
	int a;
	for (int i = 0; i < total; i++) {
		cin >> a;
		prime.push_back(a);
	}
	q.push(1);
	//최대 541의 소수 몇개가 주어지고 N이 최대로주어질때
	//곱의 수에대한 check 1차원 배열선언으로 감당할 수 가없어
	//map을 이용해주어야함
	ll high = 0;
	while (local-- > 0) {
		ll next = q.top(); q.pop();
		for (int it : prime) {
			if (it*next > high && q.size() > local) continue;
			if (!m.count(it*next)) {
				high = max(high, it*next);
				m[it*next]++;
				q.push(it*next);
			}
		}
	}
	cout << q.top();
}