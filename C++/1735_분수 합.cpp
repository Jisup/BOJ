#include <iostream>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;

int a, b, c, d;
int gcd(int y, int x) {
	int res = 0;
	while (x != 0) {
		res = y % x;
		y = x;
		x = res;
	}
	return y;
}
int lcm(int y, int x) { return y * x / gcd(y, x); }
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> c >> d;
	//�Էµȼ������� �̸�����ϱ�
	/*
	int fs = gcd(a, b);
	a /= fs; b /= fs;
	int se = gcd(c, d);
	c /= se; d /= se;
	*/
	//b,d ��Ŭ����ȣ����=x -> x/b*a+x/d*c (fisrt) x (secodn)
	int x = lcm(b, d);
	int y = x / b * a + x / d * c;
	//�̸������������ ����ľ��
	int res = gcd(y, x);
	cout << y / res << " " << x / res;
}