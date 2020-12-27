#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 40001

int A, B;

map <ll, int> a;
map <ll, int> b;

set <ll> prime;

bool check[MAX];
void erastotenes() {
	//소수문제에서 무조건나오는 아래사항 암기하기 ★

	//약수의 특성 : a*b=N일때 a,b는 N의 약수
	//a<=b가 성립할때 N=a*a가 되므로
	//N의 최대약수는 sqrt(N)이 됨


	//즉 최대수가 10억이므로
	//sqrt(10억) = 31622 . 편하게하기위해 40000으로 잡음
	//이때 4만이후의 수는 자기자신을 제외한 약수가 없다고 판단하여
	//자신을 소수라 판단해야 됨
	for (int i = 2; i < MAX; i++) {
		if (!check[i])
			for (int j = i + i; j < MAX; j += i)
				if (!check[j])check[j] = true;
	}
}
//reducible 약분에서 많은게 갈렸다.

void reducible(map<ll, int> &input, ll in) {
	/*
	수를 약분하면서, 약분의수를 체크하고 삽입
	*/
	for (int k = 2; k <= sqrt(in); k++) {
		while (in%k == 0) {
			input[k]++;
			if (prime.find(k) == prime.end())
				prime.insert(k);
			in /= k;
		}
	}
	if (in != 1) {
		input[in]++;
		if (prime.find(in) == prime.end())
			prime.insert(in);
	}
}
void reducible2(map<ll, int> &input, ll in) {
	for (int k = 2; k<= sqrt(in); k++) {
		while (!check[k] && in%k == 0) {
			input[k]++;
			in /= k;
		}
	}
	if (in != 1) {
		input[in]++;
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	erastotenes();
	cin >> A;
	ll temp;
	for (int i = 0; i < A; i++) {
		cin >> temp;
		reducible(a, temp);
	}
	cin >> B;
	for (int i = 0; i < B; i++) {
		cin >> temp;
		reducible(b, temp);
	}
	ll res = 1, flag = false;
	for (int it : prime) {
		if (a[it] != 0 && b[it] != 0) {
			int cnt = min(a[it], b[it]);
			for (int i = 0; i < cnt; i++) {
				res *= it;
				if (res > 999999999) {
					flag = true;
					res %= 1000000000;
				}
			}
			//pow는 실수형집합에해당되기때문에
			//정수형에서는 pow사용을 가급적 금한다
			//res *= pow(it, min(a[it], b[it]));
		}
	}
	/*
	for (auto item = a.begin(); item != a.end(); item++) {
		ll it = item->first;
		if (b.find(it) != b.end()) {
			int cnt = min(a[it], b[it]);
			for (int i = 0; i < cnt; i++) {
				res *= it;
				if (res > 999999999) {
					flag = true;
					res %= 1000000000;
				}
			}
		}
	}
	*/
	if (flag) {
		
		string output = "";
		int cnt = 0;
		while (res != 0) {
			output += res % 10 + '0';
			res /= 10;
			cnt++;
		}
		for (int i = cnt; i < 9; i++)output += '0';
		for (int i = 8; i >= 0; i--)
			cout << output[i];
		cout << endl;
		
		/*
		string s = to_string(res);
		stack <char> st;
		for (int i = s.length() - 1; i >= 0; i--)
			st.push(s[i]);
		while (st.size() < 9)
			st.push('0');
		for (int i = 0; i < 9; i++) {
			cout << st.top();
			st.pop();
		}
		*/
	}
	else {
		cout << res;
	}
}
/*
두개의 vector에 입력받는수 삽입 1000*1000 최대
그냥 최대 최대에넣어놓고
map으로하면?
map으로비교하고 넣는거지
*/