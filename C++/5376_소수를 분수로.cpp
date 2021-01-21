#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

//��ü���� ���� �ڷ����� int�ʰ� ll���� �̾��� ! ������ �����Ҷ�, Ȯ�β��ϱ�
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
	�Ҽ��� ����ϴ� ��Ŀ��� 2�����������Ѵ�.
	1) ���ѼҼ��ϰ��, �и�=�Ҽ�������*10, ����=����
	2) ���ѼҼ��ϰ��, �и�=�ݺ��Ҽ�����*9 x �⺻�Ҽ�����*10, ����=(��ü����)-((����)+(���ѼҼ���������))
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