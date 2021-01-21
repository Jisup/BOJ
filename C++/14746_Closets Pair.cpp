#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
//vector <int> a;
//vector <int> b;
vector <pair<int, int> > point;
int cnt;

//���尡��� P�� Q�� ã������
//a=x, b=y�� ���� ġȯ��Ŵ
//d(a,b)�� |x_a -x_b| + |y_a - y_b|
int alen, blen, x, y;
int res = INF;

/*
�Ʒ� 2���� solve��� 50x50������ �ð��ʰ��� �翬�� Ǯ�̹��
���� �߿��� Ű����Ʈ�� y�ప������ ���������� x�ప�� �����ָ� �ȴٴ°�.
�� ������� �޾� �����ѵ�
�̿��� ������ �Ÿ��� �ּҰŸ��� ã��
*/
/*
void solve() {
	sort(point.begin(), point.end());
	int high = upper_bound(point.begin(), point.end(), res) - point.begin();
	int low = lower_bound(point.begin(), point.end(), res) - point.begin();
	cout << res + abs(x - y) << " " << high - low;
}
*/
void solve() {
	sort(point.begin(), point.end(), [](pair<int, int>a, pair<int, int>b) {return a.second < b.second; });
	int now = 0;
	for (int k = 0; k + 1 < point.size(); k++) {
		if (point[k].first == point[k + 1].first) continue;
		int result = abs(point[k].second - point[k + 1].second);
		if (res > result) {
			res = result;
			cnt = 1;
		}
		else if (res == result)
			cnt++;
	}
	cout << res + abs(y - x) << " " << cnt;
}
/*
void solve() {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int it : a) {
		for (int item : b) {
			int result = abs(item - it);
			if (result == res) { cnt++; continue; }
			if (result < res) {
				res = result;
				cnt = 1;
			}
		}
	}
	cout << res + abs(x - y) << " " << cnt;
}
*/
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> alen >> blen;
	cin >> x >> y;
	int temp;
	//x y �� ���������� x==y�ΰ�� ���� false�� �ǹ����⶧����
	//���������� key������ ���������־���Ѵ�
	for (int i = 0; i < alen; i++) {
		cin >> temp;
		point.push_back(make_pair(1, temp));
	}
	for (int i = 0; i < blen; i++) {
		cin >> temp;
		point.push_back(make_pair(2, temp));
	}
	/*
	for (int i = 0; i < alen; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < blen; i++) {
		cin >> temp;
		//b.push_back(temp);
		for (int it : a) {
			int input = abs(temp - it);
			if (res >= input) {
				res = input;
				point.push_back(input);
			}
		}
	}
	*/
	solve();
}
