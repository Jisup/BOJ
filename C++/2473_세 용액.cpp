
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <climits>	//: LLONG_MAX define���� ����ϱ� ���� Import
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF LLONG_MAX //9,223,372,036,854,775,807
#define ll long long
#define fs first
#define se second
#define MAX 5000

int total;
//�Ʒ� �迭 �Է��ڷ���ũ���� 10~10����̶� int�����Ͽ����� ���Ʋ��
ll solution[MAX];
ll res = INF;

typedef struct data {
	int x;
	int y;
	int z;
}Data;
Data tp;
//��������
void twopointer() {
	int left = 0, right = 0;
	for (int i = 0; i < total; i++) {
		left = i + 1;
		right = total - 1;
		while (left < right) {
			ll result = solution[i] + solution[left] + solution[right];
			if (res > abs(result)) {
				res = abs(result);
				tp = { i,left,right };
			}
			if (result > 0) right++;
			else if (result < 0 && left + 1 < total) left++;
			else break;
		}
	}
	cout << solution[tp.x] << " " << solution[tp.y] << " " << solution[tp.z];
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> total;
	for (int i = 0; i < total; i++) {
		cin >> solution[i];
	}
	sort(solution, solution + total, less<int>());
	
	twopointer();
}
