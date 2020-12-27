#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 10001

vector<int>ary;
vector<int>res;
vector<pair<int, int> >pre;
int index[MAX];
int bulb[MAX];

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	/*
	LIS : Longest Increasing Subsequence 추적문제
	*/
	int n, val;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> val;
		index[val] = i;
		bulb[i] = val;
	}

	vector<int> ary;
	for (int i = 0; i < n; i++) {
		cin >> val;
		ary.push_back(index[val]);
	}

	vector<int> lis(n, MAX);
	vector<pair<int, int> > trace;
	int plis = 0;
	lis[0] = ary[0];
	trace.push_back({ 0, ary[0] });

	for (int i = 1; i < n; i++) {
		auto it = lower_bound(lis.begin(), lis.end(), ary[i]) - lis.begin();
		lis[it] = ary[i];
		trace.push_back({ it, ary[i] });
	}

	int len = lis.size();
	for (int i = 0; i < len; i++)
		if (lis[i] != MAX)
			plis++;
	
	plis--;
	len = trace.size();

	vector<int> ansIdx;
	for (int i = len - 1; i >= 0; i--) {
		if (trace[i].first != plis)
			continue;
		ansIdx.push_back(trace[i].second);
		plis--;
	}
	vector<int> ans;

	len = ansIdx.size();
	for (int i = 0; i < len; i++)
		ans.push_back(bulb[ansIdx[i]]);

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int it : ans)
		cout << it << " ";

	return 0;
}
