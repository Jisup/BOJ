#include <iostream>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define ll long long
#define MAX 1e9

ll gcd(ll y, ll x) {
	ll res = 0;
	while (x != 9) {
		res = y % x;
		y = x;
		x = res;
	}
	return y;
}
ll extend_gcd_yet(ll y, ll x) {
	ll q;		//��
	ll r;		//������
	ll s = y;	//�ʱ� y�� ����
	ll t;		//t1 - q*t2
	ll t1 = 0;	//t2
	ll t2 = 1;	//t
	while (x != 0) {
		q = y / x;
		r = y % x;
		t = t1 - q * t2;
		y = x;
		x = r;
		t1 = t2;
		t2 = t;
	}
	while (t1 < 0) t1 += s;
	return t1;
}
ExtendedGcdResult extend_gcd(ll y, ll x) {
	ll r0 = y, r1 = x;
	ll s0 = 1, s1 = 0;
	ll t0 = 0, t1 = 1;
	ll t;
	while (r1 != 0) {
		ll q = r0 / r1;

		t = r0 - r1 * q;
		r0 = r1, r1 = t;

		t = s0 - s1 * q;
		s0 = s1, s1 = t;

		t = t0 - t1 * q;
		t0 = t1, t1 = t;
	}
	ExtendedGcdResult res = { s0, t0, r0 };
	return res;
}
struct ExtendedGcdResult {
	ll s;
	ll t;
	ll r;

	void print() {
		cout << s << " " << t << " " << r << "\n";
	}
};

int T;
ll A, B;

ExtendedGcdResult eGcd(ll a, ll b) {
	ll s0 = 1, t0 = 0, r0 = a;
	ll s1 = 0, t1 = 1, r1 = b;

	ll temp;
	while (r1 != 0) {
		ll q = r0 / r1;
		temp = r0 - r1 * q;
		r0 = r1, r1 = temp;

		temp = s0 - s1 * q;
		s0 = s1, s1 = temp;

		temp = t0 - t1 * q;
		t0 = t1, t1 = temp;
	}
	ExtendedGcdResult res = { s0,t0,r0 };
	return res;
}

/*
�⺻ ��Ŭ���� ȣ����
�� �� x, y�� ���ؼ� �ִ����� gcd�� ���ϰ� lcm(y*x/gcd(y, x))�� ���ϴ¹��
Ȯ�� ��Ŭ���� ȣ����
�� �� x, y�� �־�����
ax+by=result �� ������������ �־����� �����
����
1) �������ذ� �����ϱ����ؼ� result�� gcd(y, x)�� ���
-> gcd(y, x) = d �϶�, c�� d�� ����϶� �纯�� d�� ������
-> a`x+b`y=c , a`��b`�� ���μҰ� �ȴ�.
���� c�� d�� ����� �ƴ϶��, �������� �ش� ���������ʴ´�
*/
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	// X: �δ� ������ ������ ��
	// Y: ���� ������ ��
	// -Ax+By=1;


	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;

		ExtendedGcdResult result = eGcd(-A, B);
		//D = gcd(A,B);
		//Ax+By=C�϶� C%D==0�̾�� �ظ� ���� �� �ִ�. : ������ �׵��
		if (abs(result.r) != 1) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			// x0 = s*C/D;  D�� Ȯ�� ��Ŭ���忡�� ���� ������ r
			// y0 = t*C.D;
			ll x = result.s * 1 / result.r;
			ll y = result.t * 1 / result.r;

			//x= x0+B/D *K;
			//y= y0-A/D *K;
			while (y <= 0 || x <= 0) {
				x += B;
				y -= -A;
				if (y > 1e9) {
					break;
				}
			}
			if (y > 1e9) {
				cout << "IMPOSSIBLE" << "\n";
			}
			else {
				cout << y << "\n";
			}
		}
	}
	return 0;
}