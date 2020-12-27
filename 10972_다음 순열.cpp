#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
int type;
vector <int> v;
void permutation() {
	if (next_permutation(v.begin(), v.end())) {
		for (int item : v)
			cout << item << " ";
		cout << endl;
	}
	else
		cout << -1;
}
void solve() {
	//최대인덱스위치
	int index = type - 1;
	//현재값이 이전값보다 큰 인덱스찾기
	while (index > 0 && v[index - 1] >= v[index])
		index--;
	if (index == 0) { cout << -1 << endl; return; }

	int next_index = type - 1;
	//찾은 인덱스보다 큰 인덱스를 찾기
	while (v[index - 1] >= v[next_index])
		next_index--;
	swap(v[index - 1], v[next_index]);

	int sort_index = type - 1;
	//외워 두 인덱스를 찾고
	//스왑을해주고
	//이전<이후라면 전체적으로 스왑을해주면서 이전++,이전--
	while (index < sort_index) {
		swap(v[index], v[sort_index]);
		index++;
		sort_index--;
	}
	for (int it : v)
		cout << it << " ";
	cout << endl;
}
int main() {
	cin >> type;
	v.resize(type);
	for (int i = 0; i < type; i++)
		cin >> v[i];
	permutation();
	//solve();
}