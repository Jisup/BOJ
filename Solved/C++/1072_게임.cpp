#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define fs first
#define se second
#define MAX 0


ll whole, win, lose;
ll result = -1;
void solve() {
	ll per = win * 100 / whole;
	ll high = 0;
	ll left = 0;
	ll right = 1000000000;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll new_per = (win + mid) * 100 / (whole + mid);
		if (new_per > per) {
			result = mid;
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
	cin.tie(0);
	scanf("%lld %lld", &whole, &win);
	lose - whole - win;
	solve();
	cout << result;
}
/*
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define fs first
#define se second
#define MAX 0


double X, Y, Z, K;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//소수점위해선 float=f , double 형 =lf 무조건
	cin >> X >> Y;
	//floor 내림 ceil 올림
	Z = floor((Y * 100) / X);
	if (Z >= (double)99) { cout << "-1"; exit(0); }
	else {
		int result = (int)ceil((Z*X + X - 100 * Y) / (99 - Z));

		cout << result;
	}
}

*/