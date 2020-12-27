
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
//result 결과값쌍의개수를 int로생각함 4000*4
//4000개 배열 4개이므로 4000^4로 LL해야함 이래서 ㅈㄴ틀림
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
	전체입력후 0이되는경우에서, a-b-c-d 가 존재하는 경우를 cnt하면?
	a-b-c-d 를 알수있는 방법이없음
	만약 vector로 value와 arraynum을 저장하고
	sort first value, second arraynum으로 한다면? -> 쓰레기

	각 배열을 sort후 a+b/c+d 로 나누는법->나누고난뒤 0값을찾기

	즉 합이 4인 모든 부분합에대한 경우의수를 구하는것이므로
	부분합!을 찾는것이고
	중복은 제외한다는말이없으니 upper-lower_bound를 사용하는것이 가장 간편한방법

	반반처리 ? -> 구현하기
	1+1 & 2 처리? -> 구현하기

	이분탐색으로 구현하기
	*/