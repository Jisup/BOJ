/*
간단한문제, pre/in/post order에 대해 이해하고
출력부분을 정할 수 있다면 비교적쉽게푸는문제

하지만 배열로 2진트리를 구현했을경우
최대치가 2^27이되버리기때문에 메모리초과 발생가능이있음
그래서간단하게
27개의 자식들의 정보를가지고있는 node를 생성, 구성으로 메모리초과 방지

입력의경우 항상 A가먼저 들어온다는 이야기가없으므로
맨 첫노드를 A로 지정해주고
입력에대해 root 알파벳 오름차순으로 정렬 후 입력받아 해결
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