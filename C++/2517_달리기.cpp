#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
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

int runner;
typedef struct data {
	int ability;
	int index;
}Data;
vector <Data> v;

//���׸�Ʈ Ʈ���� �迭�̾ƴ� ���ͷ� �����Ұ�
//int segment_tree[MAX];
vector <int> segment_tree;
//���� �� ������ ���� ����
int height = (int)ceil(log2(MAX));
int segmentTreeSize = 1 << (height + 1);
/*
int init(int start, int end, int node) {
	if (start == end) return segment_tree[node] = v[start].ability;
	int mid = (start / end) / 2;
	return segment_tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
*/
int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int index, int pix) {
	if (index < start || end < index) return;
	segment_tree[node] += pix;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node*2, index, pix);
	update(mid + 1, end, node*2+1, index, pix);
}
void solve() {
	//���� ������ ����
	segment_tree.resize(segmentTreeSize);
	// �Ƿ¿����� �������� ������ �Ƿ¼����� ���������� ����
	// 0~15�ǹ����� 0~7�ǹ����� ���ΰ� : ��ǥ������
	sort(v.begin(), v.end(), [](Data a, Data b) {return a.ability < b.ability; });
	for (int i = 0; i < v.size(); i++)
		v[i].ability = i;

	sort(v.begin(), v.end(), [](Data a, Data b) {return a.index < b.index; });
	// �ε���(�Ƿ��� ����)�� ���� ���� �� �ջ걸�ϰ�-�Ƿ�����ϰ�-Ʈ��������Ʈ)
	for (int i = 0; i < v.size(); i++) {
		int front = sum(0, MAX, 1, 0, v[i].ability);
		cout << i - front + 1 << endl;
		update(0, MAX, 1, v[i].ability, 1);
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> runner;
	v.resize(runner);
	//�Է¼������ �Ƿ°� index����
	for (int i = 0; i < runner; i++) {
		cin >> v[i].ability;
		v[i].index = i;
	}
	solve();
}

/*
���׸�ƮƮ�� [*������*]���ϱ�

1) �ֻ��� Root index�� 1���ͽ���
2) Adult = Root ( 1) Top = 1 )
3) left child = Adult_index*2
3) right_child = Adult_index*2 + 1

�ݺ��������� ��ͱ��� 1)~4)�� ���� start=1
�ѤѤѤѤѤѤѤѤ�Segment Tree Make�ѤѤѤѤѤѤѤѤ�
// ��ü��尳���� �迭�� ũ��(ex : 1~9 , total=9)���� ū ������ �� ���� �������� �ι�
// �� 8<9<16�̹Ƿ� 16*2=32 (=���׸�Ʈ Ʈ�� ������ �ʿ��� ��� ��)
// ���� �ڵ����� size*4 (=4�� �����ָ�)�� ��� ���� Ŀ������

//�ѤѤѤѤѤѤѤѤ�Segment Tree Inint�ѤѤѤѤѤѤѤѤ�
*init(0, arraysize-1, 1); // �迭�� �����ε���, ���ε���
int init(int start, int end, int node) {
	// �ش��ε����κп� �����ϸ� ������
	if (start==end) return tree[node] = a[start];
	// �ش� �κ��� �ƴ϶�� �� �κ����� ������ ��������� ������
	int mid = (start+end)/2;
	// �ΰ��� �ڽ����γ����� �׵��� ���� �ڽ����� �ϵ��� ����
	return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1)

	}
//�ѤѤѤѤѤѤѤѤ�Segment Tree Sum�ѤѤѤѤѤѤѤѤ�
*0~12������ �� : sum(0, arraysize-1, 1, 0, 12)
int sum(int start, int end, int node, int left, int right) {
	// ���� ������ left�� right �� �������
	if (left > end || right < start) return 0;
	// ���� �ȿ� �����Ұ��
	if (left <= start && end <= right) return tree[node];
	// �׷���������� �κκ����� ����� �ձ��ϱ�
	int mid = (start+end)/2;
	return sum(start, mid, node*2, left, right)+sum(mid+1, end, node*2+1, left, right);
}
//�ѤѤѤѤѤѤѤѤ�Segment Tree Update�ѤѤѤѤѤѤѤѤ�
void update(int start, int end, int node, int index, int pix) {
	// �ε����� �������ϰ�� 
	if (index < start || index > end ) return 0;
	// �ε����� ���� ���ϰ��, �������鼭 �ش� �ε������� ����θ� ������Ʈ
	// �ε��� ��ü�� �����̾ƴ�, �ε��� ������ ����ũ�⸸ŭ�� �����ϴ°�
	tree[node]+=pix;
	int mid = (start+end)/2;
	update(start, mid, node*2, index, pix);
	update(mid+1, end, node*2+1, index, pix);
}
//�ѤѤѤѤѤѤѤѤ�Segment Tree main.cpp�ѤѤѤѤѤѤѤѤ�
int ary[5];
int main() {
	// ���׸�Ʈ Ʈ������ ��� �ʼ� ���� : start, end, node + left& right or index&dif(pix)
	int arysize = ary.size();
	//���׸�Ʈ Ʈ������, 
	init(0, arysize-1, 1);
	// 0~12������ �����ձ��ϱ�
	sum(0, arysize-1, 1, 0, 12);
	// index=5�ΰ��� ���� -5 ���߱�
	update(0, arysize-1, 1, 5, -5);
}
*/