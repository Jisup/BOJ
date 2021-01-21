
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <climits>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define LLM LLONG_MAX
#define fs first
#define se second
#define MAX 100001

int total, day;
int temper[MAX];
int res = -INF;
void solve() {
	// 매 순간마다 5개의 구간을 더해줘서 시간초과가남
	// 매 순간마다 loof를 도는것이아닌 구간에대한 합을구해놓고 양끝을 가감하는것으로 풀이
	// 탈출조건문에있어서 헤멨음
	// 첨에 result에 대해 res와 비교해서 값을 저장하고갔으면 while에 t+day<today를 적어도됐고
	// 첨에 result에 대해 res와 비교를안했을경우 아래 코드처럼 진행해야 맞음
	int t = 0, result=0;
	for (int i = t; i < t + day; i++)
		result += temper[i];
	while (true) {
		if (res < result) {
			res = result;
		}
		if (t + day >= total) break;
		result = result + temper[t + day] - temper[t++];
	}
	cout << res;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> total >> day;
	for (int i = 0; i < total; i++)
		cin >> temper[i];
	solve();
}
