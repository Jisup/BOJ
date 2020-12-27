#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

//전체적인 수의 자료형이 int초과 ll안쪽 이었음 ! 곱셈이 존재할때, 확인꼭하기
#define ll long long
#define endl "\n"
#define tap "\t"
int total;

ll gcd(ll y, ll x) {
	ll res = 0;
	while (x != 0) {
		res = y % x;
		y = x;
		x = res;
	}
	return y;
}

ll change(string num) {
	ll res = 0;
	for (int i = 0; i < num.length(); i++) {
		int tmp = num[i] - '0';
		res += tmp * pow(10, num.length() - 1 - i);
	}
	return res;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> total;
	/*
	소수를 출력하는 방식에는 2가지가존재한다.
	1) 유한소수일경우, 분모=소수점길이*10, 분자=숫자
	2) 무한소수일경우, 분모=반복소수길이*9 x 기본소수길이*10, 분자=(전체숫자)-((정수)+(유한소수까지숫자))
	*/
	while (total-- > 0) {
		string temp;
		pair<string, string>prime;
		cin >> temp;
		//cout << temp << endl;
		bool flag = false;
		for (int i = 2; i < temp.length(); i++) {
			if (temp[i] == '(' || temp[i] == ')') { flag = true; continue; }
			if (!flag) prime.first += temp[i];
			else prime.second += temp[i];
		}
		//cout << prime.first << prime.second << endl;

		ll bottom1 = 0, bottom2 = 1;
		for (int i = 0; i < prime.second.length(); i++) {
			bottom1 += 9 * pow(10, i);
		}
		if (bottom1 == 0)bottom1 = 1;
		bottom2 = pow(10, prime.first.length());
		ll bottom = bottom1 * bottom2;
		
		ll top = 0;
		if (flag)
			top = change(prime.first+prime.second) - change(prime.first);
		else
			top = change(prime.first);
		//cout << top << tap << bottom << endl;
		
		ll res = gcd(top, bottom);
		cout << top / res << "/" << bottom / res << endl;
	}
}