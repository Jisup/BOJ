#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 0

int tc, house, still;
ll money;
vector <int> vilage;
int solve() {
	int cnt = 0;
	ll result = 0;
	for (int i = 0; i < still; i++) {
		result += vilage[i];
	}
	int left = 0, right = still - 1;

	int len = house == still ? 0 : still - 1;
	for (int i = 0; i < len; i++)
		vilage.push_back(vilage[i]);
	
	while (right < vilage.size()) {
		//cout << left << tap << right << tap<<result<<endl;
		if (result < money)cnt++;
		if (right + 1 >= vilage.size()) break;
		result += vilage[++right];
		result -= vilage[left++];
	}
	return cnt;
}
/*
아래소스코드와 위소스코드의 다른점찾아가면서 기술하기
int solve() {
	int cnt = 0;
	ll result = 0;
	for (int i = 0; i < still; i++) {
		vilage.push_back(vilage[i]);
		result += vilage[i];
	}
	if (result < money)
			cnt++;
	for (int i = still; i <= vilage.size()-1; i++) {
		result = result + vilage[i] - vilage[i - still];
		if (result < money)
			cnt++;
	}
	return cnt;
}
*/
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc-- > 0) {
		vilage = vector<int>();
		cin >> house >> still >> money;
		int temp;
		for (int i = 0; i < house; i++) {
			cin >> temp;
			vilage.push_back(temp);
		}
		cout << solve() << endl;
	}
}
