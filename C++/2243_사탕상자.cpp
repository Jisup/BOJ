#include <iostream>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define ll long long
#define MAX 1000000
int total;

vector<ll>segment_tree;

//������ �� �����ǹ�ȣ index��ġ�� cnt��ŭ ������������ segmentƮ���� ǥ���ؾ��Ѵ�
//�� ���ܳ����� �������� 1~1,000,000 ���� index�� ������ �ش� index�� cnt�� �߰��ȴ�
//���׸�ƮƮ���� �θ���� �ڽ��� cnt���� ���� �ջ��� ���ϰ��ִ´�
//������ �Ѱ� ������ ������ �Ҷ�, �ش� index�� ���ϴ� ������ ����ϰ�, �� ���� 1�� ���ҽ����־���Ѵ�
int query(int start, int end, int node, int cnt) {
	if (start == end) return start;
	int mid = (start + end) / 2;

	//���� �ڽ��� Ž���ϱ����� ����. : �ٽɺκ�
	if (segment_tree[node * 2] >= cnt) return query(start, mid, node * 2, cnt);
	//else return query(mid + 1, end, node * 2 + 1, cnt);
	//why cnt-segment_tree[node*2]?
	//���ذ� �Ϻ��ϰ� �������� ����
	return query(mid + 1, end, node * 2 + 1, cnt - segment_tree[node * 2]);
}
void update(int start, int end, int node, int index,  int val) {
	if (index > end || index < start) return;
	segment_tree[node] += val;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, val);
	update(mid + 1, end, node * 2 + 1, index, val);
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	cin >> total;

	int height = (int)ceil(log2(total));
	//int height = (int)ceil(log2(MAX));
	int TreeSize = 1 << (height + 1);
	segment_tree.resize(TreeSize);

	int a, b, c;
	for (int i = 0; i < total; i++) {
		cin >> a;
		if (a == 2) {
			cin >> b >> c;
			if (c < 0) continue;
			update(1, total, 1, b, c);
			//update(1, MAX, 1, b, c);
		}
		else {
			cin >> b;
			cout << query(1, total, 1, b) << endl;
			update(1, total, 1, b, -1);
			//cout << query(1, MAX, 1, b) << endl;
			//update(1, MAX, 1, b, -1);
		}
	}
}
