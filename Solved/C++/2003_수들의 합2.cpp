
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define fs first
#define se second
#define MAX 100000001

int len, res;
int num[MAX];
int f, s, result, cnt;
void solve() {
	// while �� ���ǽ��� �߰��ؼ� result>res�ΰ�� f�� �پ�鶧 res���� ���ð�찡 �����ǾƲ��
	// ���ǽ� : f<=s (������� ����) && s < len(�� �κб��� �˻���)
	while (true) {
		if (result < res) {
			if (s == len) break;
			result += num[s++];
		}
		else if (result >= res){
			if (result == res)cnt++;
			result -= num[f++];
		}
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &len, &res);
	for (int i = 0; i < len; i++) {
		scanf("%d", &num[i]);
	}
	solve();
	cout << cnt;
}
