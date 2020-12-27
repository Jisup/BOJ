#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#pragma warning (disable:4996)
using namespace std;

#define endl "\n"
#define MAX 100001
#define ll long long
int total, question;
ll num[MAX];
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
	if (index < start || index > end) return;
	segment_tree[node] += pix;
	if (start == end) return;
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
	cin >> total >> question;
	for (int i = 0; i < total; i++)
		cin >> num[i];

	int height = (int)ceil(log2(total));
	int segmentTreeSize = 1 << (height + 1);
	segment_tree.resize(segmentTreeSize);
	make(0, total - 1, 1);

	for (int i = 0; i < question; i++) {
		int x, y, a; ll b;
		cin >> x >> y >> a >> b;
		//함정이존재했음, 범위에대해 오름차순으로 입력되지 않음
		//바보같이 y가 클경우로 보내버림
		if (x > y) {
			int temp = x;
			x = y;
			y = temp;
		}
		cout << query(0, total - 1, 1, x - 1, y - 1) << endl;
		ll value = b - num[a - 1];
		num[a-1] = b;
		update(0, total - 1, 1, a-1, value);
	}
}