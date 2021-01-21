#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int cow, room, w, h;
	cin >> cow >> w >> h >> room;
	int result = (w / room) * (h / room);
	cow > result ? cout << result : cout << cow;
}