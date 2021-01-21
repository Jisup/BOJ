#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 1001

int tc, weight, student;

int Class[4][MAX];

vector <int> fs;
vector <int> se;

int result;

void solve() {
	for (int item : fs) {
		int res = weight - item;
		int high = upper_bound(se.begin(), se.end(), res) - se.begin();
		int low = 0;
		if (high == 0)
			low = high;
		else {
			if (high == se.size())high--;
			low = high-1;
		}
		/*low와 high에 대해서 값비교*/
		high = se[high];	low = se[low];

		//cout << low << tap << high << tap << item << tap << weight << endl;
		int temp1 = high + item;
		int temp2 = low + item;
		int compare = 0;
		if (abs(weight - temp1) < abs(weight - temp2))
			compare = temp1;
		else
			compare = temp2;

		if (abs(weight - result) > abs(weight - compare))
			result = compare;
		else if (abs(weight - result) == abs(weight - compare))
			result = result < compare ? result : compare;
	}
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> tc;
	while (tc-- > 0) {
		result = 2147483647;
		fs = vector<int>();
		se = vector<int>();
		memset(Class, 0, sizeof Class);
		cin >> weight >> student;
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < student; k++) {
				cin >> Class[i][k];
			}
		}
		for (int i = 0; i < student; i++)
			for (int j = 0; j < student; j++)
				fs.push_back(Class[0][i] + Class[1][j]);
		for (int i = 0; i < student; i++)
			for (int j = 0; j < student; j++)
				se.push_back(Class[2][i] + Class[3][j]);
		sort(fs.begin(), fs.end());
		sort(se.begin(), se.end());
		solve();
		cout << result << endl;
	}
	
}
