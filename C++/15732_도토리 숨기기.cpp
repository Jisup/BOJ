#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 1000001
#define INF 2147483647

int Max = -INF, Min = INF;
int total, box, pinut;
ll b[MAX];
int result = 0;

typedef struct data {
	int L;
	int R;
	int W;
}Data;
vector <Data> v;

void solve() {
	int left = Min, right = Max;
	while (left <= right) {
		int mid = (left + right) / 2;
		ll sum = 0;
		for (Data it : v) {
			if (sum >= pinut)break;
			if (it.L > mid)continue;
			if (it.R > mid)
				sum += (mid - it.L) / it.W + 1;
			else
				sum += (it.R - it.L) / it.W + 1;
		}
		if (sum >= pinut) {
			result = mid;
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

	cin >> total >> box >> pinut;
	for (int i = 0; i < box; i++) {
		int l, r, w;
		cin >> l >> r >> w;
		Min = Min < l ? Min : l;
		Max = Max > r ? Max : r;
		v.push_back(Data{ l, r, w });
	}
	solve();
}
 