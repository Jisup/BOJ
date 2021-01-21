#include <iostream>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define ll long long
#define MAX 1000000
int total;

vector<ll>segment_tree;

//사탕이 각 사탕의번호 index위치에 cnt만큼 가지고있음을 segment트리로 표현해야한다
//즉 말단노드들은 좋고나쁨이 1~1,000,000 까지 index를 가지고 해당 index에 cnt가 추가된다
//세그먼트트리의 부모들은 자식의 cnt수에 대한 합산을 지니고있는다
//사탕을 한개 빼내는 행위를 할때, 해당 index에 달하는 사탕을 출력하고, 그 수를 1개 감소시켜주어야한다
int query(int start, int end, int node, int cnt) {
	if (start == end) return start;
	int mid = (start + end) / 2;

	//왼쪽 자식을 탐색하기위한 조건. : 핵심부분
	if (segment_tree[node * 2] >= cnt) return query(start, mid, node * 2, cnt);
	//else return query(mid + 1, end, node * 2 + 1, cnt);
	//why cnt-segment_tree[node*2]?
	//이해가 완벽하게 되지않은 문제
	return query(mid + 1, end, node * 2 + 1, cnt - segment_tree[node * 2]);
}
void update(int start, int end, int node, int index,  int val) {
	if (index > end || index < start) return;
	segment_tree[node] += val;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, val);
	update(mid + 1, end, node * 2 + 1, index, val);
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	cin >> total;

	int height = (int)ceil(log2(total));
	//int height = (int)ceil(log2(MAX));
	int TreeSize = 1 << (height + 1);
	segment_tree.resize(TreeSize);

	int a, b, c;
	for (int i = 0; i < total; i++) {
		cin >> a;
		if (a == 2) {
			cin >> b >> c;
			if (c < 0) continue;
			update(1, total, 1, b, c);
			//update(1, MAX, 1, b, c);
		}
		else {
			cin >> b;
			cout << query(1, total, 1, b) << endl;
			update(1, total, 1, b, -1);
			//cout << query(1, MAX, 1, b) << endl;
			//update(1, MAX, 1, b, -1);
		}
	}
}
