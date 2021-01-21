
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define LLM LLONG_MAX
#define fs first
#define se second
#define MAX 500001

int total, tc;
ll num[MAX];

vector<ll>segment_tree;
vector<ll>lazy_tree;

//÷�� lazy�� ���� �־����� pix������ ������ �ָ鼭 ���ߵȴٰ� ������
//������ lazy[node]�������� �������� �� �ڽĿ��� �ѷ��ְ�, segƮ������ lazy[node]�������� �������� �־��ִ°�
//
void propagate(int start, int end, int node) {
	if (lazy_tree[node]) {
		if (start != end) {
			/*
			lazy_tree[node * 2] = lazy_tree[node * 2] ^ pix;
			lazy_tree[node * 2 + 1] = lazy_tree[node * 2 + 1] ^ pix;
			*/
			lazy_tree[node * 2] = lazy_tree[node * 2] ^ lazy_tree[node];
			lazy_tree[node * 2 + 1] = lazy_tree[node * 2 + 1] ^ lazy_tree[node];
		}
		//segment_tree[node] = (end - start + 1) ^ pix + segment_tree[node];
		//���ұ����� ������ ������ ��, �� ���ܳ���϶�
		if ((end-start+1)%2) segment_tree[node] = segment_tree[node] ^ lazy_tree[node];
		lazy_tree[node] = 0;
	}
}
ll make(int start, int end, int node) {
	if (start == end)
		return segment_tree[node] = num[start];
	int mid = (start + end) / 2;
	return segment_tree[node] = make(start, mid, node * 2) ^ make(mid + 1, end, node * 2 + 1);
}
ll query(int start, int end, int node, int left, int right) {
	propagate(start, end, node);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	//���������ȯ�Ҷ��� XOR
	return query(start, mid, node * 2, left, right) ^ query(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int left, int right, int pix) {
	propagate(start, end, node);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		//����Ʋ�ȳ�
		//segment_tree[node] = (end - start + 1) ^ pix - segment_tree[node];
		//�ٵ� �̰ŵ��ƴϳ�
		//segment_tree[node] = segment_tree[node] ^ lazy_tree[node];
		//���������ؼ� end-right+1%2 �̰Ϳ����ؼ� ���ʿ䰡����
		//�Ʒ��� start!=end�κκ��� lazyƮ�������ؼ� �ذ��
		//¦������ΰ�� 
		if ((end - start + 1) % 2) segment_tree[node] = segment_tree[node] ^ pix;
		if (start == end) return;
		//����¾ҳ�
		lazy_tree[node * 2] = lazy_tree[node * 2] ^ pix; 
		lazy_tree[node * 2 + 1] = lazy_tree[node * 2 + 1] ^ pix;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, pix);
	update(mid + 1, end, node * 2 + 1, left, right, pix);

	//���⵵ �����ƴϰ� �������� XOR�̹Ƿ� ������
	//�������� �𸣰ٳ� �Ѥ�
	segment_tree[node] = segment_tree[node * 2] ^ segment_tree[node * 2 + 1];
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> total;

	int height = (int)ceil(log2(total));
	int TreeSize = 1 << (height + 1);
	segment_tree.resize(TreeSize);
	lazy_tree.resize(TreeSize);

	for (int i = 0; i < total; i++)
		cin >> num[i];
	make(0, total - 1, 1);
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int a, b, x, y;
		cin >> a;
		if (a == 1) {
			cin >> x >> y >> b;
			update(0, total - 1, 1, x, y, b);
		}
		//1�϶��� pix���̵��°�.
		//0�϶��� ��°���� �����ϸ��
		else {
			cin >> x >> y;
			cout << query(0, total - 1, 1, x, y) << endl;
		}
	}
}
/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, a, b, c, d;
int seg[4004000];
int lazy[4004000];
void u_lazy(int node, int x, int y) {
	if (!lazy[node])
		return;
	if ((y - x + 1) % 2)
		seg[node] ^= lazy[node];
	if (x == y) {
		lazy[node] = 0;
		return;
	}
	lazy[node * 2] ^= lazy[node];
	lazy[node * 2 + 1] ^= lazy[node];
	lazy[node] = 0;
}
void update(int lo, int hi, int val, int node, int x, int y) {
	u_lazy(node, x, y);
	if (y < lo || hi < x)return;
	if (lo <= x && y <= hi) {
		if ((y - x + 1) % 2)seg[node] ^= val;
		if (x == y)return;
		lazy[node * 2] ^= val;
		lazy[node * 2 + 1] ^= val;
		return;
	}
	int mid = (x + y) >> 1;
	update(lo, hi, val, node * 2, x, mid);
	update(lo, hi, val, node * 2 + 1, mid + 1, y);
	seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}
int query(int lo, int hi, int node, int x, int y) {
	u_lazy(node, x, y);
	if (y < lo || hi < x)
		return 0;
	if (lo <= x && y <= hi)
		return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) ^ query(lo, hi, node * 2 + 1, mid + 1, y);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		update(i, i, a, 1, 0, n - 1);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d%d%d", &b, &c, &d);
			update(min(b, c), max(b, c), d, 1, 0, n - 1);
		}
		else {
			scanf("%d%d", &b, &c);
			printf("%d\n", query(min(b, c), max(b, c), 1, 0, n - 1));
		}
	}
	return 0;
}
*/