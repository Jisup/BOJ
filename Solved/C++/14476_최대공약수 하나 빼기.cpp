#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

#define MAX 1000001
int num[1000001];

vector <int> segment_tree;
int gcd(int y, int x) {
	int res = 0;
	while (x != 0) {
		res = y % x;
		y = x;
		x = res;
	}
	return y;
}
 int make(int start, int end, int node) {
	if (start == end) return segment_tree[node] = num[start];
	int mid = (start + end) / 2;
	int left = make(start, mid, node * 2);
	int right = make(mid + 1, end, node * 2 + 1);
	return segment_tree[node] = gcd(left, right);
}
 int update(int start, int end, int node, int index, int value) {
	 if (index < start || index > end) return segment_tree[node];
	 if (start == end) return segment_tree[node] = value;
	 int mid = (start + end) / 2;
	 int left = update(start, mid, node * 2, index, value);
	 int right = update(mid + 1, end, node * 2 + 1, index, value);
	 return segment_tree[node] = gcd(left, right);
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int total;
	cin >> total;
	for(int i=0;i<total;i++)
		cin >> num[i];

	int height = (int)ceil(log2(total));
	int TreeSize = 1 << (height + 1);
	segment_tree.resize(TreeSize);
	make(0, total - 1, 1);

	//high_gcd, indexvalue :: 뺐을때 최대공약수, 뺀수
	pair<int, int> result = { 0, -1 };
	for (int i = 0; i < total; i++) {
		update(0, total - 1, 1, i, 0);
		if (result.first < segment_tree[1])
			result = { segment_tree[1], num[i] };
		//cout << "result : " << result.first << " " << result.second << endl;
		update(0, total - 1, 1, i, num[i]);
	}
	if (result.second % result.first == 0) {
		cout << -1;
		return 0;
	}
	cout << result.first << " " << result.second;
}
//https://chanqun.tistory.com/199 누적합개념
//https://wjdgus2951.tistory.com/103 세그먼트트리개념