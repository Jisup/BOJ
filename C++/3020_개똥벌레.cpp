
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
int total, height, cnt;
vector<int>v;
vector<int>top_wall;
vector<int>bottom_wall;
int result = INF;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> total >> height;
	int a;
	for (int i = 0; i < total; i++) {
		cin >> a;
		if (!(i % 2)) bottom_wall.push_back(a);
		else top_wall.push_back(a);
	}
	sort(top_wall.begin(), top_wall.end());
	sort(bottom_wall.begin(), bottom_wall.end());
	for (int i = 1; i <= height; i++) {
		//upper�� index�ʰ������� ã�ư��� syntax error
		//��üũ�⿡�� ���ִ����� : �ش� upper/lower�� �ش� ���̺κ��� ����ġ�� ���̹Ƿ�
		int up = top_wall.size() - (upper_bound(top_wall.begin(), top_wall.end(), height - i) - top_wall.begin());
		int lo = bottom_wall.size() - (lower_bound(bottom_wall.begin(), bottom_wall.end(), i)-bottom_wall.begin());
		if (result == up + lo) cnt++;
		else if (result > up + lo) {
			result = up + lo; cnt = 1;
		}
	}
	cout << result << " " << cnt;
}
