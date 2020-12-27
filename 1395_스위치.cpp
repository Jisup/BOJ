#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;

#define endl "\n"
#define MAX 100001

int total, task;
vector <int> segment_tree;
vector <int> lazy_tree;

void propagate(int start, int end, int node) {
	if (lazy_tree[node]) {
		if (start != end) {
			//스위치가 on off이므로
			//그 스위치 상태에 해당하는 값이 lazy_tree[node]이니까
			//해당 segement_tree에는 lazy_tree의 반전값이 들어가게됨
			//구간합같은경우에는 segment_tree에 lazy_tree가 합산되지만
			//스위치는 on off에 해당하므로 segmenttree에 상태변화만 저장
			//segment_Tree에 저장하는게아니고 lazytree에 저장함
			//propagate에서는 lazy_tree의 전체적인 상태변화를 신경쓰는곳
			//update가 segment의 상태변화를 신경쓰는곳으로 구분지어 생각할것
			lazy_tree[node * 2] = !lazy_tree[node * 2];
			lazy_tree[node * 2 + 1] = !lazy_tree[node * 2 + 1];
		}
		//segment_tree갱신도 마찬가지로 구간합같은경우
		//lazy_Tree 의변경된값이 합산되어야하지만 
		//스위치의경우 기존 segmenttree에저장된 스위치정보값을 역전시키는의미로
		//새로갱신해야함

		segment_tree[node] = (end - start + 1) - segment_tree[node];
		//segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
		//위에서 갱신해줬는데 다시 갱신될 필요가 없음.
		//lazy트리안에 있는 인자를segment로 병합하는 것이므로 segment부모의 값까지 확인할 필요가 없다?
		lazy_tree[node] = 0;
	}
}
int make(int start, int end, int node) {
	if (start == end)return segment_tree[node];
	int mid = (start + end) / 2;
	return segment_tree[node] = make(start, mid, node * 2) + make(mid + 1, end, node * 2 + 1);
}
int query(int start, int end, int node, int left, int right) {
	propagate(start, end, node);
	if (left > end || right < start) return 0;
	//여기도틀렸네
	if (left <= start && end <= right)return segment_tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}
//update는 대다수 void형태 미반환형태
void update(int start, int end, int node, int left, int right) {
	propagate(start, end, node);
	/*
	if (start == end) return segment_tree[node];
	이 아래구문으로 생각이나지않음
	query와의 차이점 또는 동일한점을 기억하면서 외울것
	*/
	// query와 동일한점 : 범위밖 판단후 예외처리
	//					  범위 안쪽 판단하기
	// query와 다른점   : 범위 안쪽일때 node의 값을 반환하는게아닌 lazy_tree 변경후 segment_Tree에 lazy_tree 갱신
	//					  갱신이후에 아까 propagate에서 적었던 부모갱신이 update에서 일어나게됨			  
	if (left > end || right < start) return;

	/*
	start==end일때는 무조건 함수가 리턴되는 방향으로 생각해야함
	if (start == end) {
		segment_tree[node] = segment_tree[node] == 1 ? 0 : 1;
	}
	*/
	
	//또 오타있었음 end << right : 반복적으로 나오는 실수 체크
	if (left <= start && end <= right) {
		//구간합에서는 lazy를 변경할 값으로 바꿔준뒤 재갱신을했따
		/*
		lazy_tree[node] = 1;
		propagate(left, right, node);
		return 0;
		*/
		//스위치에서는 start==end 일때 스위치가 전환되므로
		//부모노드에서 범위에 포함된다면, 자식노드들의 switch 상태정보가 바뀌어야함
		segment_tree[node] = (end - start + 1) - segment_tree[node];
		//start==end상태는 말단노드이므로
		//말단노드때만 lazy 자식으로 흩뿌려져야하므로.
		if (start == end)return;
		lazy_tree[node * 2] = !lazy_tree[node * 2];
		lazy_tree[node * 2 + 1] = !lazy_tree[node * 2 + 1];
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right);
	update(mid + 1, end, node * 2 + 1, left, right);

	//전체 세그먼트 트리는 동일함
	segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> total >> task;

	int height = (int)ceil(log2(total));
	int segmentTreeSize = 1 << (height + 1);
	segment_tree.resize(segmentTreeSize);
	lazy_tree.resize(segmentTreeSize);
	
	for (int i = 0; i < task; i++) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a==0) {
			update(0, total - 1, 1, b - 1, c - 1);
			continue;
		}
		cout << query(0, total - 1, 1, b - 1, c - 1) << endl;;
	}
}