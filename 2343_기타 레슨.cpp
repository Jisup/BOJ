
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 100001
#define INF 2147483647
int lesson, bluelay;
int guiter[MAX];
int res = 2147483647;
bool recording(int mid) {
	//���������� �ִ� ��緹�̼��� mid�� �ȴٸ�
	//��==mid�� �Ǵ°�찡 �ݵ�������ϴ°���̹Ƿ�
	//����point�� 1���� ������
	int point = 1;
	int sum = 0;

	for (int i = 0; i < lesson; i++) {
		//�� ������ �ִ� ��緹�̼����� �� �� ����
		if (guiter[i] > mid) return false;
		sum += guiter[i];
		if (sum > mid) {
			sum = guiter[i];
			point++;
		}
	}
	cout << "point: " << point << endl;
	return bluelay >= point ? 1 : 0;
}
void solve(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		cout << left << tap << right << tap << mid << endl;
		//�Ǵ����� : �ּ� bluelay�ǰ��� �ش��ϴ� ������ ��� �ִ°�
		if (recording(mid)) {
			res = res < mid ? res : mid;
			cout << "res: " << res << endl;
			//��緹�̰����� �ּҰ������� �������
			right = mid - 1;
		}
		else {
			//��緹�̰����� �ּҰ������� �������
			left = mid + 1;
		}
	}
	cout << res;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> lesson >> bluelay;
	int sum = 0;
	for (int i = 0; i < lesson; i++) {
		cin >> guiter[i];
		sum += guiter[i];
	}
	solve(1,sum);
}
