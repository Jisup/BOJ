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
//세그먼트 트리에 구간중 낮은 인덱스를 저장
int make(int start, int end, int node) {
	if (start == end)return segment_tree[node] = start;
	int mid = (start + end) / 2;
	int left_res = make(start, mid, node * 2);
	int right_res = make(mid + 1, end, node * 2 + 1);
	return segment_tree[node] = num[left_res] < num[right_res] ? left_res : right_res;
}
//query리를통해 segment_tree에 있는 높이가 최소인 최소인덱스를 반환받음
//반환받을때 범위를벗어난반환은 처리하지못하도록 예외처리
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
//계산함수에서 반환받은 최소인덱스로 구간에대한 너비를 찾고
//그 너비가 현재 start~end인부분에서
//start~now / now+1~end 인부분과 비교하여 최대너비반환
//마지막엔 말단노드까지가서 그것에대한 너비반환후
//재귀타고올라오면서 최대너비비교
//이후산출

//아래 calcul이 분할정복부분
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
