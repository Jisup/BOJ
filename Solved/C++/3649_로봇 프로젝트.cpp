#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 1000001

//ll rego[MAX];
int tc;
vector <ll> v;
/*
void solve(int width) {
	int left = 0, right = v.size() - 1;
	while (left < right) {
		ll result = v[left] + v[right];
		//cout << left << tap << right << tap << result << endl;
		if (result > width) {
			right--;
		}
		else {
			if (result == width) {
				cout << "yes" << " " << v[left] << " " << v[right] << endl;
				return;
			}
			left++;
		}
	}
	cout << "danger" << endl;
}
*/

void solve(int width) {
	for (int i = 0; i < v.size() && v[i] <= width / 2; i++) {
		int left = i+1, right = v.size() - 1;
		cout << endl;
		while (left <= right) {
			int mid = (left + right) / 2;
			//���ο� �̺�Ž������̾���
			//��������� Ư�������� ã�ư������� �̺�Ž���������ߴµ�
			//����� �������� �ΰ��� ���ذ����Ͽ���
			//�ε��������� ������� ã�ư�����
			//�׷��� �� �������� �� ���� ���� ����̾��� (sort ������)
			//�ߺ��������ϱ����� set�������µ�
			//�����б�������� L1 <= L2 ���⋚���� �ߺ��������ϸ� �ȵ�
			
			//�̺�Ž���� �ϳ��� �������� �������ϳ��� ���� ��� ����ã�ƾ��ϴµ�
			//���Ѱ��� �Ǻ��Ͽ� �̺�Ž���� ������
			
			//������ for�������� ��üŽ��
			//���ذ����� �̺�Ž�������� ����
			//�ΰ��� ������� ��
			ll result = v[i] + v[mid];
			cout << left << " " << right <<" "<< mid << tap << v[i] << " "<< v[mid] << " " << result << endl;
			if (result > width) right = mid - 1;
			else if (result < width) left = mid + 1;
			else {
				cout << "yes" << " " << v[i] << " " << v[mid] << endl;
				return;
			}
		}
	}
	cout << "danger" << endl;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int width = 0;
	while (cin >> width) {
		width *= 10000000;

		v = vector<ll>();

		cin >> tc;
		for (int i = 0; i < tc; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		sort(v.begin(), v.end());
		solve(width);
	}
}