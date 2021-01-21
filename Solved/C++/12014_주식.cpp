#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0

int week, day;
vector<int>stoke;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc, temp;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> week >> day;
		stoke = vector<int>();
		for (int k = 0; k < week; k++) {
			cin >> temp;
			int index = lower_bound(stoke.begin(), stoke.end(), temp) - stoke.begin();
			if (stoke.size() <= index)
				stoke.push_back(temp);
			else
				stoke[index] = temp;
		}
		bool flag = false;
		if (stoke.size() >= day)
			flag = true;
		cout << "Case #" << i << endl;
		cout << flag << endl;

	}
}
