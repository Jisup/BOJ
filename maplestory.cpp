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
#define INF INT_MAX
ll child;
int game, temp;

vector<int>ary;

ll solve() {
	/*
	이진/이분 탐색 (Binary Search)
	->정렬된 값들에서 원하는 값을 찾는 알고리즘
	파라메트릭 서치 (Parametric Search)
	->주어진 범위내에서 원하는값, 조건에 가장 일치하는 값을 찾는 알고리즘
	//https://sarah950716.tistory.com/16
	특정상황의 최적화 풀이를 결정문제로 바꾸는것
	최소-최대값을 구하는 문제에서 특정값이 어떤조건을 만족하는지에 대해 확인만 하면 되는 문제
	*/
	ll result = -1;
	//최대범위=아이들의수*놀이기구의 최대시간
	//ll left = 0, right = child * 30;
	//int형 숫자 두개를 곱할때, int범위를 벗어나게되면 역행한다
	//각 숫자에 LL을 붙임으로써 longlong형으로 치환후 곱해준다
	//수를 직접 곱해서 넣을때
	ll left = 0, right = 2000000000LL * 30LL;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = game;
		cout << "마지막 아이가 탑승하는 시간 : ";
		//시간에따라서, 각 놀이기구가 운행하는 횟수를 더해감
		//운행하는 횟수는 아이들이 타는횟수와 동일함
		for (int i = 0; i < game; i++) {
			sum += mid / ary[i];
			cout << mid / ary[i] << " ";
		}
		cout << endl;
		cout << left << " " << right << " " << mid << tap << sum << endl;
		/*
		시간내에 아이들이 타는횟수가 현재 아이들수보다 많다면
		시간을 줄이고, 반대라면 시간을 늘린다.
		만약 두 수가 같다면, 해당값 저장후 반환
		*/
		if (sum >= child) {
			if (sum == child)
				result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return result;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	ll sum = 0;
	cin >> child >> game;
	for (int i = 0; i < game; i++) {
		cin >> temp;
		ary.push_back(temp);
	}
	
	//놀이기구수보다 아이들수가적을경우 아이디 수를 바로출력
	//이조건이 빠질경우 틀림
	if (child <= game) {
		cout << child;
		return 0;
	}
	ll time = solve();
	//위에서 아이들전체가 타는 시간이 주어졌으므로
	sum = game;
	//마지막아이가 탄 놀이기구를구하기위해 시간-1부터탐색
	cout << "time: " << time << endl;
	for (int i = 0; i < game; i++) {
		sum += (time - 1) / ary[i];
		cout << (time - 1) / ary[i] << " ";
	}
	//시간-1시간에 아이들이 탄 횟수를 구하고
	cout << endl;
	cout << "sum : " << sum << endl;
	//그횟수부터 최종수까지, 놀이기구를 탈수있는가 판별하여 증가!
	for (int i = 0; i < game; i++) {
		if (time%ary[i] == 0)
			sum++;
		if (sum == child) {
			cout << i + 1;
			return 0;
		}
	}
}
