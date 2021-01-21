#include <iostream>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 0

vector <ll> ary, segment_tree;

int Size, tc;

ll query(int start, int end, int node, int left, int right) {
	if (left > end || right < start)return 0;
	//left<=right, end<=start �̰ŷ��ĳ��� �̻��������Ÿ��ϴ����̾���
	//left<=start, end<=right
	if (left <= start && end <= right)return segment_tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int index, ll val) {
	if (index > end || index < start)return;
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
	cin.tie(0); cout.tie(0);

	cin >> Size >> tc;
	int height = (int)ceil(log2(Size));
	int TreeSize = 1 << (height + 1);
	segment_tree.resize(TreeSize);
	ary.resize(Size);

	while (tc-- > 0) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a) {
			//�Է¿� �ش� ary�� ��ȯ�Ҷ�, �Է°������� ���̸� update���ֱ�
			ll value = c - ary[b - 1];
			ary[b - 1] = c;
			update(0, Size - 1, 1, b - 1, value);
		}
		else {
			//�Է¿� ū�����־����� �����ʾ����Ƿ� ���ǰɾ��ֱ�
			if (b > c) {
				int temp = b;
				b = c;
				c = temp;
			}
			cout << query(0, Size - 1, 1, b - 1, c - 1) << endl;
		}
	}
}
