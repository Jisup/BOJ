#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 0

ll child;
int c;
ll total;
vector <int> color;
ll result=LLONG_MAX;
void solve() {
	ll left = 1, right = total;
	while (left <= right) {
		ll mid = (left + right) / 2;
		/*
		mid로 각 사탕을 나누엇을때
		각사탕의 몫이 child와 같은경우
		가장 큰개수를 가진 보석에대해
		나머지+mid가 질투심이되고, 그질투심을 최소로 갱신한다
		*/
		ll sum = 0;
		for (int i = 0; i < c; i++) {
			sum += color[i] / mid;
			//나머지가존재할경우 한명에게 더 나누어준다 생각해야함
			if (color[i] % mid != 0) sum++;
		}
		cout << left << " " << right << " " << mid << tap << sum << endl;
		if (sum <= child) {
			//sum==child일때 조건을 걸어줘서 틀렸었음
			result = result < mid ? result : mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> child >> c;
	for (int i = 0; i < c; i++) {
		ll temp;
		cin >> temp;
		color.push_back(temp);
		total = total > temp ? total : temp;
	}
	//sort는 사실상 무의미한수,
	//위에서 최대값을 구하지않았을때 sort후
	//마지막배열크기참조하여 right로 지정하는방식도가능
	//sort(color.begin(), color.end());
	solve();
	cout << result;
}
