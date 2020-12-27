#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 1000001

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string key; int Max;
	cin >> key >> Max;

	int res = 0;
	for (int i = 2; i < Max; i++) {
		res = 0;
		//소수*소수=소수
		//범위를 벗어나는 문자열에 대해 어떤수가 나눠지는지 판별할때
		//(각자리수+이전까지해온 수의 나머지합)%소수 로 값을 일정크기 이상으로 넘어가지않게함
		for (int k = 0; k < key.length(); k++) {
			res = (res * 10 + key[k] - '0') % i;
		}
		if (!res) {
			cout << "BAD " << i;
			return 0;
		}
	}
	cout << "GOOD";
}
