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
// ��������ó�� �ش� ���鿡���� ��ǥ�����ѵ� �ױ������� �ִ�� �ּҸ� ���Ϸ��� ���� �迭���� ���������� �ּ��ִ�� �� ���� ���������ߴµ�
// �� ������ �ִ밪�� �ּҰ��� �����س��´� �����ϰ� ���׸�Ʈ Ʈ���� �����ؾ���
// �� ���׸�ƮƮ���� ������ ���� ���̾ƴ� �ּ�, �ִ븦 ���� Ư���� ���� ���°�
// �Ѳ����� �������� ���׸�Ʈ Ʈ���� Pair�� �����ϰų�
// Ʈ���� �ΰ��� �����ϴ°�
// ���� �ο��ؼ� �Ѳ����� �����ϰڴ�.


int total, test;
int make(int start, int end, int node, int check) {
	// min, max�� ���� �������� ���ϴ� ���׸�Ʈ Ʈ������
	if (start == end)
		return check ? segment_tree[node].fs = v[start] : segment_tree[node].second = v[start];

	int mid = (start + end) / 2;
	int left_res = make(start, mid, node * 2, check);
	int right_res = make(mid + 1, end, node * 2 + 1, check);

	// �� ��� ������ Ž���ÿ� Ž���� ������ ���� �ڽ��� ��忡
	// check�� ���� �ִ�, �ּҰ��� �����ϰ�, ���� ��ͽ��� ���������� �ִ�-�ּҸ� ���Ҽ� �ְ� ����
	return check ? segment_tree[node].fs = min(left_res, right_res) : segment_tree[node].second = max(left_res, right_res);

}
// �����κ�, �� ���������ؼ� �ּҿ� �ִ븦 ã�¹�
int query(int start, int end, int node, int left, int right, bool check) {
	if (left > end || right < start) {
		// �ڷ����ȸ����ָ� -1(error) return�Ͽ� ����
		//2,147,483,647 2,000,000,000
		//��� Ʋ�������� :: LONG_MAX�� LONG_MIN�� ����� �׷��� Ʋ������
		//https://docs.microsoft.com/ko-kr/cpp/c-language/cpp-integer-limits?view=vs-2019
		return check ? INT_MAX : INT_MIN;
	}
	// �ش� �����ȿ� �����Ұ�� �ٷθ���
	if (left <= start && end <= right)
		return check ? segment_tree[node].fs : segment_tree[node].se;

	int mid = (start + end) / 2;
	// �� ����������, left-right������ ����� min, max���� �ִ�-�ּҰ��� ��ȯ�ϰ� ����
	// ������ ������ �� ���������� ����
	// ������ �����߿� �� �Լ���Ͱ��� ��������� ������ �ִ�-�ּ�ġ�� �Է��Ǿ� ������ ���� ��ġ������
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
10868_�ּڰ�
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