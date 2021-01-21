

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

int total, change, sum;
int ary[MAX];
/*Lazy Propagate : ������ ���ŵǴ�, SegementTree*/
vector <ll> segment_tree;
vector <ll> lazy_tree;

typedef struct data {
	int a;
	int b;
	int c;
	int d;
}Data;
vector <Data> input;
//lazy_tree�� �������ִ� �Լ� 
//left��right�� �ش� ������ �����ϰ� ���Եȴٸ�
//���̻� ������带 ���������ʰ�, �ڽſ��� �������
//�θ���� �ٷΰ���
//�ڽĵ��� ���߿� �鸮�Եȴٸ� ����
void propagate(int start, int end, int node) {
	//lazyƮ�� node�� ���� �����Ѵٸ� ����
	if (lazy_tree[node]) {
		//left�� right�� �����ʴٸ� :: �� �ڽ��� �ִٸ�
		if (start != end) {
			//�ڽĵ鿡�� �ڽ��� ���� �ѷ��ش�.
			lazy_tree[node * 2] += lazy_tree[node];
			lazy_tree[node * 2 + 1] += lazy_tree[node];
		}
		//�ڽ��� �ִ� ����
		//�ش� ��忡 ���� ���Ž�Ŵ
		//��, node�� �ش��ϴ� ������ �������°���
		//�������̸� ���ؼ� ���� ���Ž�Ű�°�
		//�� ���� ���ŵ� ������ ���׸�ƮƮ�� = >
		//= > ���׸�Ʈ Ʈ�� �����տ� + [Ư������������ ��]*[�� ������ ����]
		segment_tree[node] += lazy_tree[node] * (end - start + 1);
		lazy_tree[node] = 0;
	}
}
ll make(int start, int end, int node) {
	if (start == end) return segment_tree[node] = ary[start];
	int mid = (start + end) / 2;
	//return segment_tree[node] = make(start, mid, node << 1) + make(mid + 1, end, node << 1 | 1);
	return segment_tree[node] = make(start, mid, node * 2) + make(mid + 1, end, node * 2 + 1);
}
ll query(int start, int end, int node, int left, int right) {
	//�������� ���Ҷ����� �ش籸���� lazy�� ����
	propagate(start, end, node);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node << 1 | 1, left, right);
}
void update(int start, int end, int node, int left, int right, int pix) {
	//������update�� index�� ���� ����Ǹ� index�� �������� �����
	//lazy_segment�� ���������� ��ü���� ���� ����ǹǷ� index��� leff-right�� ��

	//���������� �� ������ �ش籸�� lazy�� ����
	propagate(start, end, node);
	//if (index < start || index > end) return;=>
	if (left > end || right < start) return;
	//�׸��� ���������� ������ ���ԵǴ� ��찡����
	//query�� ������ ����ϰ� �����
	//end << right ��Ÿ������ Ʈ�� �����ջ� �̻�������
	if (left <= start && end <= right) {
		//�Ϻ��ϰ����Եȴٸ�, lazy�� �ش纯�氪���� ������ lazy_tree����
		lazy_tree[node] = pix;
		propagate(start, end, node);
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, pix);
	update(mid + 1, end, node * 2 + 1, left, right, pix);
	//��簻���� ��������, �ش� ������ �θ��忡 ������Ѿ���
	segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> total >> change >> sum;
	for (int i = 0; i < total; i++)
		cin >> ary[i];

	for (int i = 0; i < change + sum; i++) {
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a;
		//input�� 3�� 4�����⶧����, ó���� 4���� �����Է¹޾Ƽ� ���ġ ������
		if (a == 1) {
			cin >> b >> c >> d;
			input.push_back({ a,b,c,d });
		}
		else {
			cin >> b >> c;
			input.push_back({ a,b,c,d });
		}

	}

	int height = (int)ceil(log2(total));
	int segmentTreeSize = 1 << (height + 1);
	segment_tree.resize(segmentTreeSize);
	lazy_tree.resize(segmentTreeSize);

	make(0, total - 1, 1);

	for (Data item : input) {
		if (item.a == 1) {	//1�ϰ�� update
			update(0, total - 1, 1, item.b - 1, item.c - 1, item.d);
		}
		else {	//2�ϰ�� query
			cout << query(0, total - 1, 1, item.b - 1, item.c - 1) << endl;
		}
	}
}
