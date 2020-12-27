#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0

vector< vector<int> > segment_tree;
vector<int>ary;

int Size, tc, temp;

void make(int start, int end, int node, int index) {
	if (index > end || index < start) return;
	segment_tree[node].push_back(ary[index]);
	if (start == end)return;
	int mid = (start + end) / 2;
	make(start, mid, node * 2, index);
	make(mid + 1, end, node * 2 + 1, index);
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> Size >> tc;
	int height = (int)ceil(log2(Size));
	int TreeSize = 1 << (height + 1);
	segment_tree.resize(TreeSize);

	for (int i = 0; i < Size; i++) {
		cin >> temp;
		ary.push_back(temp);
		make(0, Size - 1, 1, i);
	}
	for (int i = 0; i < segment_tree.size(); i++) {
		sort(segment_tree[i].begin(), segment_tree[i].end());
	}
	while (tc-- > 0) {
		int left, right, index;
		cin >> left, right, index;
	}
	/*

	*/
}
