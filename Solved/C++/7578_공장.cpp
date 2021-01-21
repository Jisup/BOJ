
/*
��ǻ� ���ذ������ʴ� ������
�� value���� index�� ġȯ�ϴ°ͱ����ۿ� ��������������
A��� �迭�� ���������� N����ŭ ���Թް�
N����ŭ ���� ���ڵ����� ���� ���� A�� �ε����� B�������Ѵ�

�׸����� �׸��鼭 �����ϴ� �Ѱ� ���ذ���������
���Ͱ��� index�� ���ٷγ����ϰ�
�����ϸ鼭
b[i]~N���� �����հ踦���Ѵ�.
�հ踦���ϰ��� 1�� �ٲ��ִµ� ���̻���ٴ� �Ҹ���
�� ������ 2->2�� ���������� 2~5���� �����������������Ƿ� 0 (�� 3,4,5 �������� �����������������Ƿ�)
//�� ���� �ش�Ǵ¸��� �ε����� ó�������Ҷ��� �����ϹǷ�
//ó������ ���̱׾��������������̴� ���������ʴ°������ϴ�
4~>4�������� 4~5�������̾����Ƿ� 0 (�������׾������� 2�̹Ƿ�)
1~>1�� ��������, 1~5������ 2�� 4�Ǽ��������Ƿ� �����հ�+2
3->3���� �������� 3~5������ 4�Ǽ��̱׾��������Ƿ� �����հ�+1
5->5�� ������ 5~5�� �ڽ��̰�, �׻��̿� �׾������� �����Ƿ� 0

�� �������־����� ���ο����ϰ� �������� ã�¹������� ����� �� ����
*/
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
#define MAX 1000001

int total, temp;
int num[MAX];
int ary[MAX];
ll result;

vector <ll> segment_tree;

ll query(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}
void update2(int start, int end, int node, int index, int val) {
	if (index < start || index > end) return;
	if (start == end) { segment_tree[node] = val; return; }
	int mid = (start + end) / 2;
	update2(start, mid, node * 2, index, val);
	update2(mid + 1, end, node * 2 + 1, index, val);
	segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
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
	for (int i = 0; i < total; i++)
		cin >> num[i];
	for (int i = 0; i < total; i++) {
		//ù�κ����� index�� ã�°Ծƴϰ�
		//�ι������� �������� index������� �����ϰԲ�
		//�� b1 b2 b3 b4 b5�� ���ؼ� 0 1 2 3 4 �� ����
		//�����ÿ��� ù�ٿ� ���� a1 a2 a3 a4 a5 ������ �ε�����ã�ư��� �س��� �׷��� ���������� �����
		//3->1->4->2->5
		cin >> temp;
		ary[temp] = i;
	}
	for (int k = 0; k < total; k++) {
		result += query(0, total - 1, 1, ary[num[k]], total - 1);
		update2(0, total - 1, 1, ary[num[k]], 1);
	}
	cout << result;
}
