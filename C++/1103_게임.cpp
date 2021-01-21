#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define fs first
#define se second
#define MAX 51

int h, w, high = -INF;
char map[MAX][MAX];
bool check[MAX][MAX] = { 0, };
//�� �� �� ��
int aX[4] = { -1, 0, 1, 0 };
int aY[4] = { 0, -1, 0 ,1 };
int dp[MAX][MAX];

//Cycle�� �����ϸ� -1 ���
//���븦����� �ش� ���븦 �ٽù����� ������ Cycle
//dfs	//'0'=32
//����	1) ���������  return
//		2) ���ۿ����� return
//		3) return �Ҷ� �ִ밪 ��
//		4) ���� �̹������ΰ��� �̸�ŭ �� ���� �־�並 �˼��ֳ�?
//		5) ������±��� ������ Ƚ�� : cnt
//		6) return �ɶ� �ش� dp�ڸ��� ���⿡ ���� �� ���� �ִ� Ƚ�� ����
//		7) dp�� �����ִٸ� ���� ���簪 ������ high�� ���� return
//		8) dp�� ���̾��ٸ� �״������
//		9) dp ���� : ������ġ(y, x)
//		10)dp���� -1�̸� �ѹ��� ����������, dp���� 0�̻��̸� ������ �װ��̻� �� �� �մ��ǹ�

bool range(int y, int x) {
	return map[y][x]=='H' || y > h - 1 || x > w - 1 || y < 0 || x < 0 ? 1 : 0;
}
int dfs(int y, int x) {
	//������ ����� ���̻� ���̾����� continue
	if (range(y, x)) return 0;
	//�湮�ߴ� ���̶�� Cycle�̴� -1���
	if (check[y][x]) { cout << "-1"; exit(0);}
	//�湮 �Ǿ ������ �����ֵ��� �ش簪 return
	if (dp[y][x] != -1) return dp[y][x];
	//���������ٸ� 0 �ʱ�ȭ, �湮ǥ��
	dp[y][x] = 0;
	check[y][x] = true;
	int nv = map[y][x] - '0';
	for (int i = 0; i < 4; i++) {
		int ny = y + aY[i] * nv;
		int nx = x + aX[i] * nv;
		//���� ��ġ���� �� �� �ִ� �� Ƚ�� �ִ�ġ ����
		dp[y][x] = max(dp[y][x], dfs(ny, nx)+1);
	}
	check[y][x] = false;
	return dp[y][x];
}
void init() {
	memset(dp, -1, sizeof dp);
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++)
		scanf("%s", &map[i]);
	init();
	cout << dfs(0,0);
}