
/*
사실상 이해가되지않는 문제다
딱 value들을 index로 치환하는것까지밖에 접근하지못했음
A라는 배열에 기존값들을 N개만큼 대입받고
N개만큼 다음 숫자들을의 값에 대한 A의 인덱스를 B에저장한다

그림으로 그리면서 진행하니 한결 이해가쉬워졌다
위와같이 index를 두줄로나열하고
연결하면서
b[i]~N까지 누적합계를구한다.
합계를구하고나면 1로 바꿔주는데 선이생겼다는 소리다
즉 기존에 2->2로 선을그을때 2~5까지 선이존재하지않으므로 0 (즉 3,4,5 번에대해 선이존재하지않으므로)
//단 위에 해당되는말은 인덱스가 처음시작할때와 동일하므로
//처음에는 선이그어져있지않을것이니 생각하지않는것이편하다
4~>4선그을때 4~5까지선이없으므로 0 (이전에그어진선은 2이므로)
1~>1로 선그을때, 1~5까지중 2와 4의선이있으므로 누적합계+2
3->3으로 선그을때 3~5까지중 4의선이그어져있으므로 누적합계+1
5->5로 그을때 5~5는 자신이고, 그사이엔 그어진선이 없으므로 0

두 라인이주어질때 서로연결하고 교차점을 찾는문제에서 사용할 수 있음
*/
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
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

int total, temp;
int num[MAX];
int ary[MAX];
ll result;

vector <ll> segment_tree;

ll query(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segment_tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}
void update2(int start, int end, int node, int index, int val) {
	if (index < start || index > end) return;
	if (start == end) { segment_tree[node] = val; return; }
	int mid = (start + end) / 2;
	update2(start, mid, node * 2, index, val);
	update2(mid + 1, end, node * 2 + 1, index, val);
	segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> total;
	int height = (int)ceil(log2(total));
	int TreeSize = 1 << (height + 1);
	segment_tree.resize(TreeSize);
	for (int i = 0; i < total; i++)
		cin >> num[i];
	for (int i = 0; i < total; i++) {
		//첫부분으로 index를 찾는게아니고
		//두번쨰줄의 값에대한 index순서대로 진행하게끔
		//즉 b1 b2 b3 b4 b5에 대해서 0 1 2 3 4 가 들어가고
		//쿼리시에는 첫줄에 받은 a1 a2 a3 a4 a5 값으로 인덱스를찾아가게 해놓음 그래서 예제에대한 결과는
		//3->1->4->2->5
		cin >> temp;
		ary[temp] = i;
	}
	for (int k = 0; k < total; k++) {
		result += query(0, total - 1, 1, ary[num[k]], total - 1);
		update2(0, total - 1, 1, ary[num[k]], 1);
	}
	cout << result;
}
