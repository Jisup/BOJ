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
	ll q;		//몫
	ll r;		//나머지
	ll s = y;	//초기 y값 저장
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
기본 유클리드 호제법
두 수 x, y에 대해서 최대공약수 gcd를 구하고 lcm(y*x/gcd(y, x))을 구하는방법
확장 유클리드 호제법
두 수 x, y가 주어질때
ax+by=result 인 부정방정식이 주어질때 사용함
조건
1) 방정식해가 존재하기위해선 result가 gcd(y, x)의 배수
-> gcd(y, x) = d 일때, c가 d의 배수일때 양변을 d로 나누면
-> a`x+b`y=c , a`와b`는 서로소가 된다.
만약 c가 d의 배수가 아니라면, 방정식의 해는 존재하지않는다
*/
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	// X: 인당 나눠줄 사탕의 수
	// Y: 사탕 봉지의 수
	// -Ax+By=1;


	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;

		ExtendedGcdResult result = eGcd(-A, B);
		//D = gcd(A,B);
		//Ax+By=C일때 C%D==0이어야 해를 가질 수 있다. : 배주의 항등식
		if (abs(result.r) != 1) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			// x0 = s*C/D;  D가 확장 유클리드에서 나온 마지막 r
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