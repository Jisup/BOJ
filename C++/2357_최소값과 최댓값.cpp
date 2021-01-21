#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define LLM LLONG_MAX
#define LM LONG_MAX
#define fs first
#define se second
#define MAX 100001

vector <int> v;
vector <pair<int, int> > tc;
vector <pair<int, int> > segment_tree;
// 기존문제처럼 해당 값들에대해 좌표압축한뒤 그구간에서 최대와 최소를 구하려는 그저 배열에서 구간에대한 최소최대비교 와 같은 방식을사용했는데
// 각 구간에 최대값과 최소값을 설정해놓는다 가정하고 세그먼트 트리를 생성해야함
// 즉 세그먼트트리에 구간에 대해 합이아닌 최소, 최대를 가진 특정한 값이 들어가는것
// 한꺼번에 넣으려면 세그먼트 트리를 Pair로 설정하거나
// 트리르 두개로 생성하는것
// 나는 인용해서 한꺼번에 생성하겠다.


int total, test;
int make(int start, int end, int node, int check) {
	// min, max에 관한 구간값을 지니는 세그먼트 트리생성
	if (start == end)
		return check ? segment_tree[node].fs = v[start] : segment_tree[node].second = v[start];

	int mid = (start + end) / 2;
	int left_res = make(start, mid, node * 2, check);
	int right_res = make(mid + 1, end, node * 2 + 1, check);

	// 좌 우로 분할후 탐색시에 탐색이 끝난후 현재 자신의 노드에
	// check에 따라 최대, 최소값을 저장하고, 값을 재귀시켜 구간에대해 최대-최소를 구할수 있게 설정
	return check ? segment_tree[node].fs = min(left_res, right_res) : segment_tree[node].second = max(left_res, right_res);

}
// 쿼리부분, 각 구간에대해서 최소와 최대를 찾는법
int query(int start, int end, int node, int left, int right, bool check) {
	if (left > end || right < start) {
		// 자료형안맞춰주면 -1(error) return하여 오류
		//2,147,483,647 2,000,000,000
		//계속 틀리던이유 :: LONG_MAX와 LONG_MIN을 써야함 그래서 틀린거임
		//https://docs.microsoft.com/ko-kr/cpp/c-language/cpp-integer-limits?view=vs-2019
		return check ? INT_MAX : INT_MIN;
	}
	// 해당 범위안에 존재할경우 바로리턴
	if (left <= start && end <= right)
		return check ? segment_tree[node].fs : segment_tree[node].se;

	int mid = (start + end) / 2;
	// 각 구간에들어설때, left-right범위에 벗어나면 min, max값에 최대-최소값을 반환하게 설정
	// 범위에 만족할 수 있을때까지 분할
	// 분할후 시행중에 그 함수재귀값이 범윌벗어나면 어차피 최대-최소치가 입려되어 기존의 값을 해치지않음
	int left_res = query(start, mid, node * 2, left, right, check);
	int right_res = query(mid + 1, end, node * 2 + 1, left, right, check);
	//cout << "start:" << start << "\/end:" << end << tap << "node:" << node << "\/check:" << check << tap << left_res << endl;
	//cout << "start:" << start << "\/end:" << end << tap << "node:" << node << "\/check:" << check << tap << right_res << endl;
	return check ? min(left_res, right_res) : max(left_res, right_res);
}
void solve() {

	int height = (int)ceil(log2(total));
	int segmentTreeSize = 1 << (height + 1);
	segment_tree.resize(segmentTreeSize);

	make(0, total - 1, 1, true);
	make(0, total - 1, 1, false);

	for (int t = 0; t < test; t++) {
		int fs = tc[t].fs - 1;
		int se = tc[t].second - 1;

		int min_res = query(0, total - 1, 1, fs, se, true);
		int max_res = query(0, total - 1, 1, fs, se, false);

		cout << min_res << " " << max_res << endl;
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> total >> test;
	v.resize(total);
	for (int i = 0; i < total; i++)
		cin >> v[i];
	for (int i = 0; i < test; i++) {
		int a, b;
		cin >> a >> b;
		tc.push_back(make_pair(a, b));
	}
	solve();
}
/*
10868_최솟값
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define LLM LLONG_MAX
#define LM LONG_MAX
#define fs first
#define se second
#define MAX 100001

vector <int> v;
vector <pair<int, int> > tc;
vector <int> segment_tree;
int total, test;
int make(int start, int end, int node) {
	if (start == end)
		return segment_tree[node] = v[start];

	int mid = (start + end) / 2;
	int left_res = make(start, mid, node * 2);
	int right_res = make(mid + 1, end, node * 2 + 1);

	return segment_tree[node] = min(left_res, right_res) ;

}

int query(int start, int end, int node, int left, int right) {
	if (left > end || right < start) {
		return INT_MAX;
	}

	if (left <= start && end <= right)
		return segment_tree[node];

	int mid = (start + end) / 2;
	int left_res = query(start, mid, node * 2, left, right);
	int right_res = query(mid + 1, end, node * 2 + 1, left, right);
	return min(left_res, right_res);
}
void solve() {
	int height = (int)ceil(log2(total));
	int segmentTreeSize = 1 << (height + 1);
	segment_tree.resize(segmentTreeSize);

	make(0, total - 1, 1);
	for (int t = 0; t < test; t++) {
		int fs = tc[t].fs - 1;
		int se = tc[t].second - 1;
		int min_res = query(0, total - 1, 1, fs, se);
		cout << min_res << endl;
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> total >> test;
	v.resize(total);
	for (int i = 0; i < total; i++)
		cin >> v[i];
	for (int i = 0; i < test; i++) {
		int a, b;
		cin >> a >> b;
		tc.push_back(make_pair(a, b));
	}
	solve();
}

*/