#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define LLM LLONG_MAX
#define fs first
#define se second
#define MAX 1000001

ll num[MAX];
int total, change, sum;

vector <ll> segment_tree;

ll make(int start, int end, int node) {
	if (start == end) return segment_tree[node] = num[start];
	int mid = (start + end) / 2;
	return segment_tree[node] = make(start, mid, node * 2) + make(mid + 1, end, node * 2 + 1);
}
ll query(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int index, ll pix) {
	if (index <start || index > end) return;
	segment_tree[node] += pix;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, pix);
	update(mid + 1, end, node * 2 + 1, index, pix);
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cin >> total >> change >> sum;
	for (int i = 0; i < total; i++)
		cin >> num[i];
	//a=1�ΰ��, b�� c�� �ٲٰ�
	//a=2�ΰ��, b~c���� ���� ���ϱ�
	int height = (int)ceil(log2(total));
	int segmentTreeSize = 1 << (height + 1);
	segment_tree.resize(segmentTreeSize);
	make(0, total - 1, 1);

	for (int i = 0; i < change + sum; i++) {
		int a = 0, b = 0; ll c = 0;
		cin >> a >> b >> c;
		if (a == 1) {
			ll dif = c - num[b - 1];
			//���氪������ ���̰������ؼ� <- ������� ��������
			num[b - 1] = c;
			update(0, total - 1, 1, b - 1, dif);
		}
		// �����򰥸������� node�� 1������~�ִ�N*4������, tree�� 0������~N-1������
		else
			cout << query(0, total - 1, 1, b - 1, c - 1) << endl;
	}
}
