#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 1001

int now, more, Max;
int result;
typedef struct data {
	int left;
	int right;
}Data;

vector <int> v;

void solve() {
	/*
	최소~최대 중간값을 구하고, 중간값에대해서
	중간값으로 각 구간거리값이 나눠진다면
	휴계소를 설치할 수 있는 의미이므로 개수를 더해감
	최대 설치수까지 더해가되
	나눈값이 딱떨어진다면 개수1개감소, 아니라면 그대로 덧셈
	더해온값이 개수보다 적다면 right 줄이기,
	크다면 left줄이기인데, 여기선 left가 줄어들 경우가 없음.
	-> 이분탐색으로 풀지 않아도 된다는말.
	*/
	int left = 0, right = Max;
	while (left <= right) {
		int cnt = 0;
		int mid = (left + right) / 2;
		//현재 mid값, 즉 세울수 있는 거리를 기준으로
		//전체구간에 이거리만큼 휴계소를세워서
		//내가원하는 목표치까지 도달할 수 있는지 판단
		//불가능하면 최대범위축소, 가능을넘어서면 최소범위확대
		for (int i = 0; i < v.size() - 1; i++) {
			int dist = v[i + 1] - v[i];
			if (dist / mid > 0) {
				if (dist%mid == 0)
					cnt += (dist - 1) / mid;
				else
					cnt += dist / mid;
			}
		}
		if (cnt <= more) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> now >> more >> Max;

	v.push_back(0);
	for (int i = 0; i < now; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	v.push_back(Max);

	sort(v.begin(), v.end());

	solve();
}