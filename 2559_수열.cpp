
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
	// �� �������� 5���� ������ �����༭ �ð��ʰ�����
	// �� �������� loof�� ���°��̾ƴ� ���������� �������س��� �糡�� �����ϴ°����� Ǯ��
	// Ż�����ǹ����־ �����
	// ÷�� result�� ���� res�� ���ؼ� ���� �����ϰ����� while�� t+day<today�� ����ư�
	// ÷�� result�� ���� res�� �񱳸���������� �Ʒ� �ڵ�ó�� �����ؾ� ����
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
