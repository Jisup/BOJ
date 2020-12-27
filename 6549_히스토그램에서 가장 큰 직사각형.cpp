#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <algorithm>
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
#define MAX 100001

int total;
ll num[MAX];

vector <int> segment_tree;

ll make(int start, int end, int node) {
	if (start == end) return segment_tree[node] = start;
	int mid = (start + end) / 2;
	int left_res = make(start, mid, node * 2);
	int right_res = make(mid + 1, end, node * 2 + 1);
	return segment_tree[node] = num[left_res] < num[right_res] ? left_res : right_res;
}
ll query(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right)return segment_tree[node];
	int mid = (start + end) / 2;
	int left_res = query(start, mid, node * 2, left, right);
	int right_res = query(mid + 1, end, node * 2 + 1, left, right);
	if (left_res == -1) return right_res;
	else if (right_res == -1) return left_res;
	else return num[left_res] < num[right_res] ? left_res : right_res;
}
ll calcul(int left, int right) {
	int index = query(0, total - 1, 1, left, right);
	ll height = (right - left + 1)*num[index];

	if (left <= index-1)
		height = max(height, calcul(left, index - 1));
	if (index + 1 <= right)
		height = max(height, calcul(index + 1, right));
	return height;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		cin >> total;
		if (total == 0) break;
		for (int i = 0; i < total; i++)
			cin >> num[i];
		segment_tree = vector<int>();
		int height = (int)ceil(log2(total));
		int segmentTreeSize = 1 << (height + 1);
		segment_tree.resize(segmentTreeSize);
		make(0, total - 1, 1);
		cout << calcul(0, total - 1) << endl;
	}
}
