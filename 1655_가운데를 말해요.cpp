
#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0
#define INF 2147483647
//�߰����� ã������ ����� �ϳ�
//�ΰ��� ť�� index�� 1�������ö� �Ʒ����ǿ����� ť������
//���� ť�� top�� ���Ͽ� �������� �߰����̵�
//�������� 1���� top�� �ִ밪�� ������ ��������
//�ٸ� 1���� top�� �ּҰ��� ������ ������������ �����ؾ���


priority_queue<int, vector<int>, less<int> > q_max;
priority_queue<int, vector<int>, greater<int> > q_min;
//priority_queue <int, vector<int>, less<int> > q_max;
//priority_queue <int, vector<int>, greater<int> > q_min;
int total, input;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> total;
	for (int i = 0; i < total; i++) {
		cin >> input;		
		//�ִ��� size = �ּ��� size or +1
		//�ּ��� top >= �ִ��� top
		if (q_max.size() > q_min.size()) 
			q_min.push(input);
		else
			q_max.push(input);
		if (!q_max.empty() && !q_min.empty()) {
			if (q_max.top() > q_min.top()) {
				int high = q_max.top();
				int low = q_min.top();
				q_max.pop();
				q_min.pop();
				q_max.push(low);
				q_min.push(high);
			}
		}
		cout << q_max.top() << endl;
	}
}