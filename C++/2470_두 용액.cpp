
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define fs first
#define se second
#define MAX 100005

int total;
int solution[MAX];
ll res = INF;
pair <int, int> tp;
//이분탐색
void binarysearch() {

}
//두포인터
void twopointer() {
	int left = 0, right = total-1;
	
	while (left < right) {
		ll result = solution[left] + solution[right];
		if (res > abs(result)) {
			res = abs(result);
			tp = make_pair(left, right);
		}
		if (result > 0) right--;
		else if (result < 0 && left+1<total) left++;
		else break;
	}
	cout << solution[tp.fs] << " " << solution[tp.se];
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> total;
	for (int i = 0; i < total; i++) {
		cin >> solution[i];
	}
	sort(solution, solution + total, less<int>());
	//binarysearch();
	twopointer();
}
