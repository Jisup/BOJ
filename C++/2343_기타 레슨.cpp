
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 100001
#define INF 2147483647
int lesson, bluelay;
int guiter[MAX];
int res = 2147483647;
bool recording(int mid) {
	//구간에대해 최대 블루레이수가 mid가 된다면
	//합==mid가 되는경우가 반드시존재하는경우이므로
	//시작point를 1부터 시작함
	int point = 1;
	int sum = 0;

	for (int i = 0; i < lesson; i++) {
		//한 레슨이 최대 블루레이수보다 길 수 없음
		if (guiter[i] > mid) return false;
		sum += guiter[i];
		if (sum > mid) {
			sum = guiter[i];
			point++;
		}
	}
	cout << "point: " << point << endl;
	return bluelay >= point ? 1 : 0;
}
void solve(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		cout << left << tap << right << tap << mid << endl;
		//판단조건 : 최소 bluelay의값에 해당하는 구간이 몇개나 있는가
		if (recording(mid)) {
			res = res < mid ? res : mid;
			cout << "res: " << res << endl;
			//블루레이갯수가 최소개수보다 적을경우
			right = mid - 1;
		}
		else {
			//블루레이갯수가 최소개수보다 많을경우
			left = mid + 1;
		}
	}
	cout << res;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> lesson >> bluelay;
	int sum = 0;
	for (int i = 0; i < lesson; i++) {
		cin >> guiter[i];
		sum += guiter[i];
	}
	solve(1,sum);
}
