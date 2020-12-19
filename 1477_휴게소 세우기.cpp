#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 1001

int now, more, Max;
int result;
typedef struct data {
	int left;
	int right;
}Data;

vector <int> v;

void solve() {
	/*
	�ּ�~�ִ� �߰����� ���ϰ�, �߰��������ؼ�
	�߰������� �� �����Ÿ����� �������ٸ�
	�ް�Ҹ� ��ġ�� �� �ִ� �ǹ��̹Ƿ� ������ ���ذ�
	�ִ� ��ġ������ ���ذ���
	�������� ���������ٸ� ����1������, �ƴ϶�� �״�� ����
	���ؿ°��� �������� ���ٸ� right ���̱�,
	ũ�ٸ� left���̱��ε�, ���⼱ left�� �پ�� ��찡 ����.
	-> �̺�Ž������ Ǯ�� �ʾƵ� �ȴٴ¸�.
	*/
	int left = 0, right = Max;
	while (left <= right) {
		int cnt = 0;
		int mid = (left + right) / 2;
		//���� mid��, �� ����� �ִ� �Ÿ��� ��������
		//��ü������ �̰Ÿ���ŭ �ް�Ҹ�������
		//�������ϴ� ��ǥġ���� ������ �� �ִ��� �Ǵ�
		//�Ұ����ϸ� �ִ�������, �������Ѿ�� �ּҹ���Ȯ��
		for (int i = 0; i < v.size() - 1; i++) {
			int dist = v[i + 1] - v[i];
			if (dist / mid > 0) {
				if (dist%mid == 0)
					cnt += (dist - 1) / mid;
				else
					cnt += dist / mid;
			}
		}
		if (cnt <= more) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> now >> more >> Max;

	v.push_back(0);
	for (int i = 0; i < now; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	v.push_back(Max);

	sort(v.begin(), v.end());

	solve();
}