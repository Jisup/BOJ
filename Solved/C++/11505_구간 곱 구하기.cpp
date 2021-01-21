
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

//�ڷ��� ��ü������ int->ll�� �����ص� �����
//DIV������ �����⿡ ll������ �����ʾ�����, Ư���ʰ������� �����߳���
//DIV���� 1���ε� ��
ll num[MAX];
int total, change, multiplex;

typedef struct data {
	int a;
	int b;
	ll c;
}Data;
Data tc[MAX / 100 * 2];
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
	// right <= end �� �����ؼ� Ʋ�� �ٵ��� �� ��Ȯ�ϰ� �����ؾߵǴϱ� �ƾ�
	// right <= end�� �ع����� 0~3 ���� �޾ƾߵǴµ� 0~6���� ������������
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return (query(start, mid, node * 2, left, right)*query(mid + 1, end, node * 2 + 1, left, right)) % DIV;
}
//�� ������Ʈ �ٸ��� ����
//make�� query�� ���ÿ� ������
//������ �����հ������ ���ϴ°��� ���� �������� ��ȭ�� Ʈ�����α����� ��������ָ�ƴµ�
//�޸��ⰰ������ ����� �Ѹ� �������°ŹǷ� +1
//�����հ������� Ư�� �������ΰ��� ��ο� ��� ������(���̰�)�� �������°ŹǷ� +=pix
//�������������� 0�� ��춧���� make�� �ٽ��Ѵٴ���
//�� make�⺻Ʋ (1) ���ܳ��� ������ (2) �θ���� �ڽĳ���� ������������ϴ°� �� ����
//update�⺻Ʋ�� �ε��������ؼ� �߰�, �ε��� ����ÿ��� �ش� ����� �� �������ֵ��� ����
ll update(int start, int end, int node, int index, ll mul) {
	if (index > end || index < start) return segment_tree[node];
	if (start == end)return segment_tree[node] = mul;
	int mid = (start + end) / 2;
	return segment_tree[node] = (update(start, mid, node * 2, index, mul) * update(mid + 1, end, node * 2 + 1, index, mul))%DIV;
}
// �����϶� : �� ���̸� ���ذ����
// �����϶� : 1*2*3*4*5 -> 1*2*6*4*5
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> total >> change >> multiplex;
	int height = (int)ceil(log2(total));
	int segmentTreeSize = 1 << (height + 1);
	for (int i = 0; i < total; i++)
		cin >> num[i];
	
	segment_tree.resize(segmentTreeSize);
	init(segmentTreeSize);
	make(0, total - 1, 1);

	for (int i = 0; i < change + multiplex; i++) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		tc[i] = { a,b,c };
	}
	for (int i = 0; i < change + multiplex; i++) {
		if (tc[i].a == 1) {
			ll value = num[tc[i].b - 1];
			num[tc[i].b - 1] = tc[i].c;
			update(0, total - 1, 1, tc[i].b - 1, tc[i].c);
		}
		else {
			cout << query(0, total - 1, 1, tc[i].b - 1, tc[i].c - 1) << endl;
		}
	}
}