#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 0

ll child;
int c;
ll total;
vector <int> color;
ll result=LLONG_MAX;
void solve() {
	ll left = 1, right = total;
	while (left <= right) {
		ll mid = (left + right) / 2;
		/*
		mid�� �� ������ ����������
		�������� ���� child�� �������
		���� ū������ ���� ����������
		������+mid�� �������̵ǰ�, ���������� �ּҷ� �����Ѵ�
		*/
		ll sum = 0;
		for (int i = 0; i < c; i++) {
			sum += color[i] / mid;
			//�������������Ұ�� �Ѹ��� �� �������ش� �����ؾ���
			if (color[i] % mid != 0) sum++;
		}
		cout << left << " " << right << " " << mid << tap << sum << endl;
		if (sum <= child) {
			//sum==child�϶� ������ �ɾ��༭ Ʋ�Ⱦ���
			result = result < mid ? result : mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> child >> c;
	for (int i = 0; i < c; i++) {
		ll temp;
		cin >> temp;
		color.push_back(temp);
		total = total > temp ? total : temp;
	}
	//sort�� ��ǻ� ���ǹ��Ѽ�,
	//������ �ִ밪�� �������ʾ����� sort��
	//�������迭ũ�������Ͽ� right�� �����ϴ¹�ĵ�����
	//sort(color.begin(), color.end());
	solve();
	cout << result;
}
