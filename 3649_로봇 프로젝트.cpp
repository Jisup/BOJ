#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#pragma warning(disable:4996)
using namespace std;
#define ll long long
#define endl "\n"
#define tap "\t"
#define MAX 1000001

//ll rego[MAX];
int tc;
vector <ll> v;
/*
void solve(int width) {
	int left = 0, right = v.size() - 1;
	while (left < right) {
		ll result = v[left] + v[right];
		//cout << left << tap << right << tap << result << endl;
		if (result > width) {
			right--;
		}
		else {
			if (result == width) {
				cout << "yes" << " " << v[left] << " " << v[right] << endl;
				return;
			}
			left++;
		}
	}
	cout << "danger" << endl;
}
*/

void solve(int width) {
	for (int i = 0; i < v.size() && v[i] <= width / 2; i++) {
		int left = i+1, right = v.size() - 1;
		cout << endl;
		while (left <= right) {
			int mid = (left + right) / 2;
			//새로운 이분탐색방법이었음
			//결과에대한 특이점값을 찾아가기위해 이분탐색을진행했는데
			//결과의 값을위해 두값을 더해가야하였음
			//인덱스에따라서 결과값을 찾아가야함
			//그래서 위 두포인터 가 가장 편한 방법이었음 (sort 했을시)
			//중복을제거하기위해 set을썻었는데
			//문제읽기오류였음 L1 <= L2 였기떄문에 중복을제거하면 안됨
			
			//이분탐색은 하나를 기준으로 나머지하나에 대해 모든 합을찾아야하는데
			//더한값을 판별하여 이분탐색을 진행함
			
			//기준을 for문을통해 전체탐색
			//더해갈수를 이분탐색을통해 선정
			//두값을 결과값과 비교
			ll result = v[i] + v[mid];
			cout << left << " " << right <<" "<< mid << tap << v[i] << " "<< v[mid] << " " << result << endl;
			if (result > width) right = mid - 1;
			else if (result < width) left = mid + 1;
			else {
				cout << "yes" << " " << v[i] << " " << v[mid] << endl;
				return;
			}
		}
	}
	cout << "danger" << endl;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int width = 0;
	while (cin >> width) {
		width *= 10000000;

		v = vector<ll>();

		cin >> tc;
		for (int i = 0; i < tc; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		sort(v.begin(), v.end());
		solve(width);
	}
}