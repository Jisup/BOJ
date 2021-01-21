/*
�����ѹ���, pre/in/post order�� ���� �����ϰ�
��ºκ��� ���� �� �ִٸ� ��������Ǫ�¹���

������ �迭�� 2��Ʈ���� �����������
�ִ�ġ�� 2^27�̵ǹ����⶧���� �޸��ʰ� �߻�����������
�׷��������ϰ�
27���� �ڽĵ��� �������������ִ� node�� ����, �������� �޸��ʰ� ����

�Է��ǰ�� �׻� A������ ���´ٴ� �̾߱Ⱑ�����Ƿ�
�� ù��带 A�� �������ְ�
�Է¿����� root ���ĺ� ������������ ���� �� �Է¹޾� �ذ�
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define endl "\n"
#define tap "\t"
#define sub 'A'+1
#define MAX 27

typedef struct data {
	char root;
	char left;
	char right;
}Data;
int TreeSize;
typedef struct data2 {
	char left;
	char right;
}Next;
vector <Next> tree;
vector <Data> input;
string pre_order, in_order, post_order;
void traversal(char node) {
	if (node == 0)return;
	pre_order += node;
	traversal(tree[node - sub].left);
	in_order += node;
	traversal(tree[node - sub].right);
	post_order += node;
}
int tc;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	tree.resize(MAX);
	char a, b, c;
	for (int i = 0; i < tc; i++) {
		cin >> a >> b >> c;
		input.push_back({ a,b,c });
	}
	sort(input.begin(), input.end(), [](Data a, Data b) {return a.root < b.root; });
	for (Data item : input) {
		if (item.left == '.' && item.right == '.') continue;
		if (item.left != '.' && item.right != '.') {
			tree[item.root - sub] = { item.left, item.right };
			continue;
		}
		if (item.left != '.') {
			tree[item.root - sub] = { item.left, 0 };
		}
		if (item.right != '.') {
			tree[item.root - sub] = { 0, item.right };
		}
	}
	traversal('A');
	for (char item : pre_order) cout << item;
	cout << endl;
	for (char item : in_order) cout << item;
	cout << endl;
	for (char item : post_order) cout << item;
}