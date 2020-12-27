
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define LLM LLONG_MAX
#define fs first
#define se second
#define MAX 4000

vector <ll> v1;
ll ary[4][MAX];
int arysize;
//result ��������ǰ����� int�λ����� 4000*4
//4000�� �迭 4���̹Ƿ� 4000^4�� LL�ؾ��� �̷��� ����Ʋ��
ll result;
void solve() {
	sort(v1.begin(), v1.end(), less<ll>());
	for (int i = 0; i < arysize; i++) {
		for (int j = 0; j < arysize; j++) {
			ll sum = ary[2][i] + ary[3][j];
			int high = upper_bound(v1.begin(), v1.end(), -sum) - v1.begin();
			int low = lower_bound(v1.begin(), v1.end(), -sum) - v1.begin();
			//cout << "sum : " << sum << " \/ high : " << high << " \/ low : " << low << endl;
			result += high - low;
		}
	}
	cout << result;
}
void sum() {
	for (int j = 0; j < arysize; j++) {
		for (int i = 0; i < arysize; i++) {
			v1.push_back(ary[0][j] + ary[1][i]);
		}
	}
	
	solve();
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> arysize;
	for (int j = 0; j < arysize; j++) {
			for (int i = 0; i < 4; i++) {
				cin >> ary[i][j];
		}
	}
	sum();
}
	/*
	https://jaimemin.tistory.com/1108
	https://github.com/RYUDAYUN/cpp/blob/master/a7453.cpp
	��ü�Է��� 0�̵Ǵ°�쿡��, a-b-c-d �� �����ϴ� ��츦 cnt�ϸ�?
	a-b-c-d �� �˼��ִ� ����̾���
	���� vector�� value�� arraynum�� �����ϰ�
	sort first value, second arraynum���� �Ѵٸ�? -> ������

	�� �迭�� sort�� a+b/c+d �� �����¹�->�������� 0����ã��

	�� ���� 4�� ��� �κ��տ����� ����Ǽ��� ���ϴ°��̹Ƿ�
	�κ���!�� ã�°��̰�
	�ߺ��� �����Ѵٴ¸��̾����� upper-lower_bound�� ����ϴ°��� ���� �����ѹ��

	�ݹ�ó�� ? -> �����ϱ�
	1+1 & 2 ó��? -> �����ϱ�

	�̺�Ž������ �����ϱ�
	*/