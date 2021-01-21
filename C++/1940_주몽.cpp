#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define LLM LLONG_MAX
#define fs first
#define se second
#define MAX 15001

int ea, make;
int armor[MAX];
int res;
void solve() {
	int left = 0, right = ea-1;
	while (left < right) {
		int result = armor[left] + armor[right];
		if (result >= make) {
			right--;
			if (result == make) res++;
		}
		else
			left++;
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> ea;
	cin >> make;
	for (int i = 0; i < ea; i++)
		cin >> armor[i];
	sort(armor, armor + ea, less<int>());
	solve();
	cout << res;
}
