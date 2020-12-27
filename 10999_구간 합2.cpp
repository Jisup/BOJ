

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
/*Lazy Propagate : 느리게 갱신되는, SegementTree*/
vector <ll> segment_tree;
vector <ll> lazy_tree;

typedef struct data {
	int a;
	int b;
	int c;
	int d;
}Data;
vector <Data> input;
//lazy_tree를 갱신해주는 함수 
//left와right가 해당 범위에 완전하게 포함된다면
//더이상 하위노드를 갱신하지않고, 자신에서 종료시켜
//부모들을 바로갱신
//자식들은 나중에 들리게된다면 갱신
void propagate(int start, int end, int node) {
	//lazy트리 node에 값이 존재한다면 실행
	if (lazy_tree[node]) {
		//left와 right가 같지않다면 :: 즉 자식이 있다면
		if (start != end) {
			//자식들에게 자신의 값을 뿌려준다.
			lazy_tree[node * 2] += lazy_tree[node];
			lazy_tree[node * 2 + 1] += lazy_tree[node];
		}
		//자식이 있던 없던
		//해당 노드에 합을 갱신시킴
		//즉, node에 해당하는 구간에 더해지는값에
		//구간길이를 곱해서 합을 갱신시키는것
		//즉 새로 갱신된 구간합 세그먼트트리 = >
		//= > 세그먼트 트리 구간합에 + [특정구간에더할 합]*[그 구간의 길이]
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
	//구간합을 구할때마다 해당구간의 lazy값 갱신
	propagate(start, end, node);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node << 1 | 1, left, right);
}
void update(int start, int end, int node, int left, int right, int pix) {
	//기존의update는 index의 값이 변경되면 index를 기준으로 변경됨
	//lazy_segment는 구간에대한 전체적인 값이 변경되므로 index대신 leff-right가 들어감

	//구간갱신을 할 때마다 해당구간 lazy값 갱신
	propagate(start, end, node);
	//if (index < start || index > end) return;=>
	if (left > end || right < start) return;
	//그리고 기존에없던 구간이 포함되는 경우가생김
	//query의 구조와 비슷하게 변경됨
	//end << right 오타로인해 트리 구간합산 이상생겼었음
	if (left <= start && end <= right) {
		//완벽하게포함된다면, lazy값 해당변경값으로 변경후 lazy_tree갱신
		lazy_tree[node] = pix;
		propagate(start, end, node);
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, pix);
	update(mid + 1, end, node * 2 + 1, left, right, pix);
	//모든갱신이 끝났을때, 해당 갱신을 부모노드에 적용시켜야함
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
		//input이 3개 4개였기때문에, 처음에 4개로 고정입력받아서 결과치 오류남
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
		if (item.a == 1) {	//1일경우 update
			update(0, total - 1, 1, item.b - 1, item.c - 1, item.d);
		}
		else {	//2일경우 query
			cout << query(0, total - 1, 1, item.b - 1, item.c - 1) << endl;
		}
	}
}
