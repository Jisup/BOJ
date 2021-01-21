#include <iostream>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 0

/*
void solve(ll input) {
	ll index = sqrt(input * 2);
	while (true) {
		ll result = index * (index + 1)/2;
		if (result > input) index--;
		else {
			cout << index;
			return;
		}
	}
}
*/

void solve(ll input) {
	ll idx = 0;
	ll result = 0;
	while (true) {
		result += ++idx;
		if (result >= input) {
			if (result > input)
				idx--;
			cout << idx;
			return;
		}
	}
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll res;
	cin >> res;
	solve(res);
}
