
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

//자료형 전체적으로 int->ll로 맞춰준뒤 통과됨
//DIV값으로 나누기에 ll지정을 하지않았지만, 특정초과범위가 존재했나봄
//DIV값은 1억인데 ㅎ
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
	// right <= end 로 설정해서 틀림 근데왜 아 정확하게 포함해야되니까 아아
	// right <= end로 해버리면 0~3 값을 받아야되는데 0~6값을 받을수도있음
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return (query(start, mid, node * 2, left, right)*query(mid + 1, end, node * 2 + 1, left, right)) % DIV;
}
//곱 업데이트 다른점 적기
//make와 query를 동시에 진행함
//기존의 구간합같은경우 변하는값에 대한 유동적인 변화만 트리내부구조에 변경시켜주면됐는데
//달리기같은경우는 사람이 한명씩 제쳐지는거므로 +1
//구간합같은경우는 특정 유동적인값이 경로에 모두 변경점(차이값)이 더해지는거므로 +=pix
//구간곱같은경우는 0의 경우때문에 make를 다시한다는점
//즉 make기본틀 (1) 말단노드는 값대입 (2) 부모노드는 자식노드의 결과값을저장하는것 을 토대로
//update기본틀인 인덱스관련해서 추가, 인덱스 벗어날시에는 해당 노드의 값 리턴해주도록 설정
ll update(int start, int end, int node, int index, ll mul) {
	if (index > end || index < start) return segment_tree[node];
	if (start == end)return segment_tree[node] = mul;
	int mid = (start + end) / 2;
	return segment_tree[node] = (update(start, mid, node * 2, index, mul) * update(mid + 1, end, node * 2 + 1, index, mul))%DIV;
}
// 덧셈일때 : 그 차이를 더해가면됨
// 곱셈일때 : 1*2*3*4*5 -> 1*2*6*4*5
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