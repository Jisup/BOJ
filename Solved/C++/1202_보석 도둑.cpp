
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define ll long long
#define MAX 300001

int total, have;
vector <pair<int, int> > jewelry;
vector <int> bag;
bool check[MAX];
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	cin >> total >> have;

	int a, b;
	for (int i = 0; i < total; i++) {
		cin >> a >> b;
		jewelry.push_back({ a, b });
	}
	//, [](pair<int, int> a, pair<int, int>b) {return a.second > b.second; }
	sort(jewelry.begin(), jewelry.end());
	for (int i = 0; i < have; i++) {
		cin >> a;
		bag.push_back(a);
	}
	sort(bag.begin(), bag.end(), less<int>());
	//ũ������� �����س���, ũ�⿡�����ϴٸ� ���ϰ� continue
	//pick and pic �� �ƴϰ� All_pick and pic
	//�Ѱ��� ��󰡸鼭 �����ϴ°��� �ƴϰ�
	//��ü�� �ְ�, �ϳ��� ���ì���
	ll result = 0;
	int cnt = 0;
	priority_queue<int>q;
	for (int item : bag) {
		//cout << item << endl;
		//ť�� ������ ����κ��� �׾Ƶΰ�, ������ �ִ�ġ�� ����� �� �ִ�
		//������ ���Ժ��� �����ؼ�~
		while (cnt < total && jewelry[cnt].first <= item) {
			//cout << "idx : " << cnt << tap << "value : " << jewelry[cnt].second << endl;
			q.push(jewelry[cnt++].second);
		}
		//���ذ��ȵǴ¹���
		//�����ǹ��Ը� 6�� 1�� �����ϰ�
		//������ 2 5 4�� �س�������� ���� 99���Ǿ�߸����ѵ�
		//�̷� ��찡 �־����� �ʴ°���

		//���� �����Ѱ��� ������ ������ ���� ���� �������
		//��� ��츦 �����Ҷ�, �����ȴٴ°��� �ľ���

		//������ ���ϳ��� �������� �����Ͽ��� cnt, index�� ����
		if (!q.empty()) {
			//cout << q.top() << endl;
			result += q.top();
			q.pop();
		}
	}
	cout << result;
}
