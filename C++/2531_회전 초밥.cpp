
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
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
#define MAX 3001

int dish, menu, relay, fre;
int food[MAX*100+10];
int check[MAX];
int result;
int high = -INF;
void solve() {
	for (int i = 0; i < relay; i++) {
		if (check[food[i]]==0) result++;
		check[food[i]]++;
		// ��ü Dish���̵常���Ƽ� ���Ʋ����
		// ��ü Dish���̵尡�ƴ� �Ϻ��� Roof�� ���ƾ���
		// �� �� Dish�� �������� relay�� ������ �ִ� ���հ����� ã�ƾߵ�
		food[i + dish] = food[i];
	}
	for (int i = 0; i < dish; i++) {
		if (check[fre]==0) high = max(result + 1, high);
		else high = max(result, high);
		//�����ߴµ� ������ --
		check[food[i]]--;
		if (check[food[i]]==0)result--;
		//�߰��ߴµ� ������ ++
		if (check[food[i + relay]]==0) result++;
		check[food[i + relay]]++;
		//�����¿� ���� ���ð� ������ 0 ������ 1 +
		
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> dish >> menu >> relay >> fre;
	for (int i = 0; i < dish; i++)
		cin >> food[i];
	solve();
	cout << high;
}