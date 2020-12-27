#include <iostream>
#include <map>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0

map <int, int> m;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int card, find, temp;
	cin >> card;
	for (int i = 0; i < card; i++) {
		cin >> temp;
		m[temp]++;
	}
	cin >> find;
	for (int i = 0; i < find; i++) {
		cin >> temp;
		cout << m[temp] << " ";
	}
}
