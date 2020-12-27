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
	//�Ҽ��������� �����ǳ����� �Ʒ����� �ϱ��ϱ� ��

	//����� Ư�� : a*b=N�϶� a,b�� N�� ���
	//a<=b�� �����Ҷ� N=a*a�� �ǹǷ�
	//N�� �ִ����� sqrt(N)�� ��


	//�� �ִ���� 10���̹Ƿ�
	//sqrt(10��) = 31622 . ���ϰ��ϱ����� 40000���� ����
	//�̶� 4�������� ���� �ڱ��ڽ��� ������ ����� ���ٰ� �Ǵ��Ͽ�
	//�ڽ��� �Ҽ��� �Ǵ��ؾ� ��
	for (int i = 2; i < MAX; i++) {
		if (!check[i])
			for (int j = i + i; j < MAX; j += i)
				if (!check[j])check[j] = true;
	}
}
//reducible ��п��� ������ ���ȴ�.

void reducible(map<ll, int> &input, ll in) {
	/*
	���� ����ϸ鼭, ����Ǽ��� üũ�ϰ� ����
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
			//pow�� �Ǽ������տ��ش�Ǳ⶧����
			//������������ pow����� ������ ���Ѵ�
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
�ΰ��� vector�� �Է¹޴¼� ���� 1000*1000 �ִ�
�׳� �ִ� �ִ뿡�־����
map�����ϸ�?
map���κ��ϰ� �ִ°���
*/