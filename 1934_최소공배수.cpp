#include <iostream>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0

int gcd(int a, int b) {
	int res = 0;
	while (b != 0) {
		res = a % b;
		a = b;
		b = res;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc, a, b;
	cin >> tc;
	while (tc-- > 0) {
		cin >> a >> b;
		cout << lcm(a, b) << endl;
	}
}
