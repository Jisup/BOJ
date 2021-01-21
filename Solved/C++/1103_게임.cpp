#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define fs first
#define se second
#define MAX 51

int h, w, high = -INF;
char map[MAX][MAX];
bool check[MAX][MAX] = { 0, };
//좌 상 우 하
int aX[4] = { -1, 0, 1, 0 };
int aY[4] = { 0, -1, 0 ,1 };
int dp[MAX][MAX];

//Cycle이 존재하면 -1 출력
//자취를남기며 해당 자취를 다시밟으면 무조건 Cycle
//dfs	//'0'=32
//조건	1) 범위벗어나면  return
//		2) 구멍에들어가면 return
//		3) return 할때 최대값 비교
//		4) 내가 이방향으로가면 이만큼 더 갈수 있어요를 알수있나?
//		5) 현재상태까지 움직인 횟수 : cnt
//		6) return 될때 해당 dp자리에 방향에 따라 더 갈수 있는 횟수 저장
//		7) dp에 값이있다면 값과 현재값 더한후 high와 비교후 return
//		8) dp에 값이없다면 그대로진행
//		9) dp 인자 : 현재위치(y, x)
//		10)dp값이 -1이면 한번도 오지않은것, dp값이 0이상이면 앞으로 그값이상 갈 수 잇는의미

bool range(int y, int x) {
	return map[y][x]=='H' || y > h - 1 || x > w - 1 || y < 0 || x < 0 ? 1 : 0;
}
int dfs(int y, int x) {
	//범위에 벗어나면 더이상 길이없으니 continue
	if (range(y, x)) return 0;
	//방문했던 곳이라면 Cycle이니 -1출력
	if (check[y][x]) { cout << "-1"; exit(0);}
	//방문 되어서 정보가 남아있따면 해당값 return
	if (dp[y][x] != -1) return dp[y][x];
	//정보가없다면 0 초기화, 방문표시
	dp[y][x] = 0;
	check[y][x] = true;
	int nv = map[y][x] - '0';
	for (int i = 0; i < 4; i++) {
		int ny = y + aY[i] * nv;
		int nx = x + aX[i] * nv;
		//현재 위치에서 갈 수 있는 길 횟수 최대치 저장
		dp[y][x] = max(dp[y][x], dfs(ny, nx)+1);
	}
	check[y][x] = false;
	return dp[y][x];
}
void init() {
	memset(dp, -1, sizeof dp);
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++)
		scanf("%s", &map[i]);
	init();
	cout << dfs(0,0);
}