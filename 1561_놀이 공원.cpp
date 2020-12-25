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
#define INF INT_MAX
ll child;
int game, temp;

vector<int>ary;

ll solve() {
	/*
	����/�̺� Ž�� (Binary Search)
	->���ĵ� ���鿡�� ���ϴ� ���� ã�� �˰���
	�Ķ��Ʈ�� ��ġ (Parametric Search)
	->�־��� ���������� ���ϴ°�, ���ǿ� ���� ��ġ�ϴ� ���� ã�� �˰���
	//https://sarah950716.tistory.com/16
	Ư����Ȳ�� ����ȭ Ǯ�̸� ���������� �ٲٴ°�
	�ּ�-�ִ밪�� ���ϴ� �������� Ư������ ������� �����ϴ����� ���� Ȯ�θ� �ϸ� �Ǵ� ����
	*/
	ll result = -1;
	//�ִ����=���̵��Ǽ�*���̱ⱸ�� �ִ�ð�
	//ll left = 0, right = child * 30;
	//int�� ���� �ΰ��� ���Ҷ�, int������ ����ԵǸ� �����Ѵ�
	//�� ���ڿ� LL�� �������ν� longlong������ ġȯ�� �����ش�
	//���� ���� ���ؼ� ������
	ll left = 0, right = 2000000000LL * 30LL;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = game;
		cout << "������ ���̰� ž���ϴ� �ð� : ";
		//�ð�������, �� ���̱ⱸ�� �����ϴ� Ƚ���� ���ذ�
		//�����ϴ� Ƚ���� ���̵��� Ÿ��Ƚ���� ������
		for (int i = 0; i < game; i++) {
			sum += mid / ary[i];
			cout << mid / ary[i] << " ";
		}
		cout << endl;
		cout << left << " " << right << " " << mid << tap << sum << endl;
		/*
		�ð����� ���̵��� Ÿ��Ƚ���� ���� ���̵������ ���ٸ�
		�ð��� ���̰�, �ݴ��� �ð��� �ø���.
		���� �� ���� ���ٸ�, �ش簪 ������ ��ȯ
		*/
		if (sum >= child) {
			if (sum == child)
				result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return result;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	ll sum = 0;
	cin >> child >> game;
	for (int i = 0; i < game; i++) {
		cin >> temp;
		ary.push_back(temp);
	}
	
	//���̱ⱸ������ ���̵����������� ���̵� ���� �ٷ����
	//�������� ������� Ʋ��
	if (child <= game) {
		cout << child;
		return 0;
	}
	ll time = solve();
	//������ ���̵���ü�� Ÿ�� �ð��� �־������Ƿ�
	sum = game;
	//���������̰� ź ���̱ⱸ�����ϱ����� �ð�-1����Ž��
	cout << "time: " << time << endl;
	for (int i = 0; i < game; i++) {
		sum += (time - 1) / ary[i];
		cout << (time - 1) / ary[i] << " ";
	}
	//�ð�-1�ð��� ���̵��� ź Ƚ���� ���ϰ�
	cout << endl;
	cout << "sum : " << sum << endl;
	//��Ƚ������ ����������, ���̱ⱸ�� Ż���ִ°� �Ǻ��Ͽ� ����!
	for (int i = 0; i < game; i++) {
		if (time%ary[i] == 0)
			sum++;
		if (sum == child) {
			cout << i + 1;
			return 0;
		}
	}
}
