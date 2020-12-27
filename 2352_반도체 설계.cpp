#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0

vector<int>ary;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int total, temp;
	cin >> total;
	while (total-- > 0) {
		cin >> temp;
		int index = lower_bound(ary.begin(), ary.end(), temp) - ary.begin();
		if (ary.size() <= index)
			ary.push_back(temp);
		else
			ary[index] = temp;
	}
	cout << ary.size();
}
