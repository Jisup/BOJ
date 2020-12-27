#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0

int ju, fr, Max;
vector <int> mak;
int result=-1;
void solve() {
	int left = 0, right = 2147483647-1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		//예외처리해주기
		if (mid == 0) {
			cout << 0;
			return;
		}
		for (int item : mak) {
			cnt += item / mid;
		}
		if (cnt < fr) {
			right = mid - 1;
		}
		else {
			result = mid;
			left = mid + 1;
		}
	}
	//예외처리해주기
	if (result == -1)
		cout << 0;
	else
		cout << result;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> ju >> fr;
	mak.resize(ju);
	for (int i = 0; i < ju; i++)
		cin >> mak[i];
	solve(); 
}
