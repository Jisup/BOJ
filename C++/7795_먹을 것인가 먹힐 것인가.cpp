#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0

int tc;
vector<int> a;
vector<int> b;
vector<int> res;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc-- > 0) {
		int ea = 0;
		a = vector<int>();
		b = vector<int>();
		int alen, blen;
		cin >> alen >> blen;
		int temp;
		for (int i = 0; i < alen; i++) {
			cin >> temp;
			a.push_back(temp);
		}
		for (int i = 0; i < blen; i++) {
			cin >> temp;
			b.push_back(temp);
		}
		sort(a.begin(), a.end(), [](int a, int b) {return a > b; });
		sort(b.begin(), b.end(), [](int a, int b) {return a < b; });
		for (int item : a) {
			//lower로 구해야함, upper은 자기자신도 포함하기 때문에 패스
			int result = lower_bound(b.begin(), b.end(), item) - b.begin();
			ea += result;
		}
		cout << ea << endl;
	}
}
