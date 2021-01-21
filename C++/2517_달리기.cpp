#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define LLM LLONG_MAX
#define fs first
#define se second
#define MAX 500001

int runner;
typedef struct data {
	int ability;
	int index;
}Data;
vector <Data> v;

//세그먼트 트리를 배열이아닌 벡터로 구현할것
//int segment_tree[MAX];
vector <int> segment_tree;
//높이 및 사이즈 설정 고정
int height = (int)ceil(log2(MAX));
int segmentTreeSize = 1 << (height + 1);
/*
int init(int start, int end, int node) {
	if (start == end) return segment_tree[node] = v[start].ability;
	int mid = (start / end) / 2;
	return segment_tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
*/
int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int index, int pix) {
	if (index < start || end < index) return;
	segment_tree[node] += pix;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node*2, index, pix);
	update(mid + 1, end, node*2+1, index, pix);
}
void solve() {
	//벡터 사이즈 설정
	segment_tree.resize(segmentTreeSize);
	// 실력에따라 오름차순 정렬후 실력순서를 선형증가로 변경
	// 0~15의범위를 0~7의범위로 줄인것 : 좌표압축기술
	sort(v.begin(), v.end(), [](Data a, Data b) {return a.ability < b.ability; });
	for (int i = 0; i < v.size(); i++)
		v[i].ability = i;

	sort(v.begin(), v.end(), [](Data a, Data b) {return a.index < b.index; });
	// 인덱스(실력의 순서)에 따라 정렬 후 합산구하고-실력출력하고-트리업데이트)
	for (int i = 0; i < v.size(); i++) {
		int front = sum(0, MAX, 1, 0, v[i].ability);
		cout << i - front + 1 << endl;
		update(0, MAX, 1, v[i].ability, 1);
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> runner;
	v.resize(runner);
	//입력순서대로 실력과 index설정
	for (int i = 0; i < runner; i++) {
		cin >> v[i].ability;
		v[i].index = i;
	}
	solve();
}

/*
세그먼트트리 [*구간합*]구하기

1) 최상위 Root index가 1부터시작
2) Adult = Root ( 1) Top = 1 )
3) left child = Adult_index*2
3) right_child = Adult_index*2 + 1

반복구현보다 재귀구현 1)~4)를 토대로 start=1
ㅡㅡㅡㅡㅡㅡㅡㅡㅡSegment Tree Makeㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 전체노드개수는 배열의 크기(ex : 1~9 , total=9)보다 큰 제곱근 중 가장 작은수의 두배
// 즉 8<9<16이므로 16*2=32 (=세그먼트 트리 생성시 필요한 노드 수)
// 실제 코딩에선 size*4 (=4를 곱해주면)로 모든 범위 커버가능

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡSegment Tree Inintㅡㅡㅡㅡㅡㅡㅡㅡㅡ
*init(0, arraysize-1, 1); // 배열의 시작인덱스, 끝인덱스
int init(int start, int end, int node) {
	// 해당인덱스부분에 도착하면 값삽입
	if (start==end) return tree[node] = a[start];
	// 해당 부분이 아니라면 두 부분으로 나누는 기준점잡고 나누기
	int mid = (start+end)/2;
	// 두개의 자식으로나눈뒤 그들의 합을 자신으로 하도록 설정
	return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1)

	}
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡSegment Tree Sumㅡㅡㅡㅡㅡㅡㅡㅡㅡ
*0~12까지의 합 : sum(0, arraysize-1, 1, 0, 12)
int sum(int start, int end, int node, int left, int right) {
	// 범위 밖으로 left와 right 가 나갈경우
	if (left > end || right < start) return 0;
	// 범위 안에 존재할경우
	if (left <= start && end <= right) return tree[node];
	// 그렇지않을경우 두부분으로 나누어서 합구하기
	int mid = (start+end)/2;
	return sum(start, mid, node*2, left, right)+sum(mid+1, end, node*2+1, left, right);
}
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡSegment Tree Updateㅡㅡㅡㅡㅡㅡㅡㅡㅡ
void update(int start, int end, int node, int index, int pix) {
	// 인덱스가 범위밖일경우 
	if (index < start || index > end ) return 0;
	// 인덱스가 범위 안일경우, 내려가면서 해당 인덱스까지 모든경로를 업데이트
	// 인덱스 자체값 수정이아닌, 인덱스 값에서 일정크기만큼을 수정하는것
	tree[node]+=pix;
	int mid = (start+end)/2;
	update(start, mid, node*2, index, pix);
	update(mid+1, end, node*2+1, index, pix);
}
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡSegment Tree main.cppㅡㅡㅡㅡㅡㅡㅡㅡㅡ
int ary[5];
int main() {
	// 세그먼트 트리관련 재귀 필수 인자 : start, end, node + left& right or index&dif(pix)
	int arysize = ary.size();
	//세그먼트 트리생성, 
	init(0, arysize-1, 1);
	// 0~12까지의 구간합구하기
	sum(0, arysize-1, 1, 0, 12);
	// index=5인곳의 값을 -5 낮추기
	update(0, arysize-1, 1, 5, -5);
}
*/