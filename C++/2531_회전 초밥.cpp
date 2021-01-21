
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define LLM LLONG_MAX
#define fs first
#define se second
#define MAX 3001

int dish, menu, relay, fre;
int food[MAX*100+10];
int check[MAX];
int result;
int high = -INF;
void solve() {
	for (int i = 0; i < relay; i++) {
		if (check[food[i]]==0) result++;
		check[food[i]]++;
		// 전체 Dish사이드만돌아서 계속틀렸음
		// 전체 Dish사이드가아닌 완벽한 Roof를 돌아야함
		// 즉 각 Dish를 기준으로 relay로 먹을수 있는 조합가지를 찾아야됨
		food[i + dish] = food[i];
	}
	for (int i = 0; i < dish; i++) {
		if (check[fre]==0) high = max(result + 1, high);
		else high = max(result, high);
		//삭제했는데 없으면 --
		check[food[i]]--;
		if (check[food[i]]==0)result--;
		//추가했는데 없으면 ++
		if (check[food[i + relay]]==0) result++;
		check[food[i + relay]]++;
		//현상태에 쿠폰 접시가 있으면 0 없으면 1 +
		
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> dish >> menu >> relay >> fre;
	for (int i = 0; i < dish; i++)
		cin >> food[i];
	solve();
	cout << high;
}