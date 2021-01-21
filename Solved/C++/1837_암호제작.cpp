#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 1000001

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string key; int Max;
	cin >> key >> Max;

	int res = 0;
	for (int i = 2; i < Max; i++) {
		res = 0;
		//�Ҽ�*�Ҽ�=�Ҽ�
		//������ ����� ���ڿ��� ���� ����� ���������� �Ǻ��Ҷ�
		//(���ڸ���+���������ؿ� ���� ��������)%�Ҽ� �� ���� ����ũ�� �̻����� �Ѿ���ʰ���
		for (int k = 0; k < key.length(); k++) {
			res = (res * 10 + key[k] - '0') % i;
		}
		if (!res) {
			cout << "BAD " << i;
			return 0;
		}
	}
	cout << "GOOD";
}
