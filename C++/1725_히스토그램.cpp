#define _CRT_SECUORE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
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
//���׸�Ʈ Ʈ���� ������ ���� �ε����� ����
int make(int start, int end, int node) {
	if (start == end)return segment_tree[node] = start;
	int mid = (start + end) / 2;
	int left_res = make(start, mid, node * 2);
	int right_res = make(mid + 1, end, node * 2 + 1);
	return segment_tree[node] = num[left_res] < num[right_res] ? left_res : right_res;
}
//query�������� segment_tree�� �ִ� ���̰� �ּ��� �ּ��ε����� ��ȯ����
//��ȯ������ �����������ȯ�� ó���������ϵ��� ����ó��
int query(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	int left_res = query(start, mid, node * 2, left, right);
	int right_res = query(mid + 1, end, node * 2 + 1, left, right);

	if (left_res == INF) return right_res;
	else if (right_res == INF)return left_res;
	else return num[left_res] < num[right_res] ? left_res : right_res;
}
//����Լ����� ��ȯ���� �ּ��ε����� ���������� �ʺ� ã��
//�� �ʺ� ���� start~end�κκп���
//start~now / now+1~end �κκа� ���Ͽ� �ִ�ʺ��ȯ
//�������� ���ܳ��������� �װͿ����� �ʺ��ȯ��
//���Ÿ��ö���鼭 �ִ�ʺ��
//���Ļ���

//�Ʒ� calcul�� ���������κ�
ll calcul(int start, int end) {
	int index = query(0, total - 1, 1, start, end);
	ll height_max = (end - start + 1) * num[index];

	if (start <= index - 1) {
		height_max = max(height_max, calcul(start, index - 1));
	}
	if (index + 1 <= end) {
		height_max = max(height_max, calcul(index + 1, end));
	}
	return height_max;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> total;
	for (int i = 0; i < total; i++)
		cin >> num[i];
	int height = (int)ceil(log2(total));
	int segmentTreeSize = 1 << (height + 1);
	segment_tree.resize(segmentTreeSize);

	make(0, total - 1, 1);
	cout << calcul(0, total - 1) << endl;
}
