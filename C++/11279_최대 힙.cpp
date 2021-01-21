#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"

priority_queue<int, vector<int>, less<int> > q;

int total;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> total;
	for (int i = 0; i < total; i++) {
		int input;
		cin >> input;
		if (!input) {
			if (!q.empty()) {
				cout << q.top() << endl;
				q.pop();
			}
			else
				cout << "0" << endl;
		}
		else
			q.push(input);
	}
}