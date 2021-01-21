
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

#define tap "\t"
#define endl "\n"
#define ll long long
#define MAX 1000001
#define DIV 1000000007

int num[MAX];
int total, change, multiplex;

typedef struct data {
	int a;
	int b;
	int c;
}Data;
Data tc[MAX / 100 * 2];

//마찬가지로 곱의 결과가 int를 넘어갈 수 있음
//10^5 * 10^5
//10^10 , int = 10^9*2
vector <ll> segment_tree;
void init(int s_size) {
	for (int i = 0; i < s_size; i++)
		if (segment_tree[i] == 0)
			segment_tree[i] = 1;
}
ll make(int start, int end, int node) {
	if (start == end)
		return segment_tree[node] = num[start];
	int mid = (start + end) / 2;
	return segment_tree[node] = (make(start, mid, node * 2) * make(mid + 1, end, node * 2 + 1)) % DIV;
}
ll query(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return (query(start, mid, node * 2, left, right)*query(mid + 1, end, node * 2 + 1, left, right)) % DIV;
}
ll update(int start, int end, int node, int index, int mul) {
	if (index > end || index < start) return segment_tree[node];
	if (start == end)return segment_tree[node] = mul;
	int mid = (start + end) / 2;
	return segment_tree[node] = (update(start, mid, node * 2, index, mul) * update(mid + 1, end, node * 2 + 1, index, mul)) % DIV;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int total = 0, round = 0;
		cin >> total >> round;
		if (total == 0 || round == 0) break;

		segment_tree = vector<ll>();
		for (int i = 0; i < total; i++)
			cin >> num[i];

		int height = (int)ceil(log2(total));
		int segmentTreeSize = 1 << (height + 1);
		segment_tree.resize(segmentTreeSize);
		init(segmentTreeSize);
		make(0, total - 1, 1);

		for (int i = 0; i < round; i++) {
			char type; int a = 0, b = 0;
			cin >> type;
			if (type == 'C') {//chnage
				cin >> a >> b;
				update(0, total - 1, 1, a - 1, b);
			}
			else {	//pix
				cin >> a >> b;
				ll result = query(0, total - 1, 1, a - 1, b - 1);
				if (result > 0) cout << "+";
				else if (result < 0)cout << "-";
				else cout << "0";
			}
		}
		cout << endl;
	}
}