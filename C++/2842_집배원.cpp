#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define fs first
#define se second
#define MAX 55

int hw;

int ay[] = { -1,-1,1,1,0,1,0,-1 };
int ax[] = { -1,1,-1,1,-1,0,1,0 };

vector <int> tired;
pair <int, int> start;
bool check[MAX][MAX];
int area[MAX][MAX];
char map[MAX][MAX];

typedef struct data {
	int y;
	int x;
}Data;
bool range(int y, int x) {
	return y<0 || x<0 || y>hw - 1 || x>hw - 1 || check[y][x] ? 0 : 1;
}
int transport, result=INF;
void solve() {
	queue <Data> q;
	int left = 0, right = 0;
	//two포인터개념을 사용해서 while진행
	//탈출조건은 left가 피로도 vector를 넘어갈때
	while (left < tired.size()) {
		int village = 0;
		memset(check, 0, sizeof check);
		//P부터 항상 시작해야하고, P가 left와 right사이에 존재할때 q에 넣어야함
		if (tired[left] <= area[start.fs][start.second] &&
			tired[right] >= area[start.fs][start.second]) {
			q.push({ start.fs,start.se });
			check[start.fs][start.second] = true;
		}
		//q에 시작부분이 들어갔을 때, 해당부분에 대해
		//left와 right 사이에 존재하는 모든 구간을 검색
		while (!q.empty()) {
			Data out = q.front(); q.pop();
			for (int i = 0; i < 8; i++) {
				int ny = out.y + ay[i];
				int nx = out.x + ax[i];
				if (range(ny, nx) &&
					tired[left] <= area[ny][nx] &&
					tired[right] >= area[ny][nx]) {
					check[ny][nx] = true;
					if (map[ny][nx] == 'K')
						village++;
					q.push({ ny, nx });
				}
			}
		}
		if (village == transport) {
			result = min(result, tired[right] - tired[left]);
			left++;
		}
		// 더한값이 전체범위를 넘어가면안되는것을 잊지 말아야함
		// 거친 마을이 적을때 right를 올려주는 경우지만, 조건은 위를 따라야함
		else if (right+1 < tired.size()) {
			right++;
		}
		else
			break;
	}

}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*
	Two Pointer가 쓰이는 문제유형 정리해보기
	Two Pointer문제 다풀기 <- 이번주말까지 끝내서 블로그에정리하기
	*/
	cin >> hw;
	for (int i = 0; i < hw; i++) {
		cin >> map[i];
		for (int j = 0; j < hw; j++) {
			if (map[i][j] == 'P')
				start = { i,j };
			else if (map[i][j] == 'K')
				transport++;
		}
	}
	for (int i = 0; i < hw; i++)
		for (int j = 0; j < hw; j++) {
			cin >> area[i][j];
			tired.push_back(area[i][j]);
		}

	sort(tired.begin(), tired.end());
	tired.erase(unique(tired.begin(), tired.end()), tired.end());
	//vector에서 sort 이후에 중복을 제거하는 방법
	//또는 set container를 사용해도 무방
	/*
	set <int> s;
	s.push_back(area[i][j]);
	for(int i=0;i<s.size();i++) tired.push_back(s[i]);
	*/
	solve();
	cout << result;
}

/*
int hw;
vector<npair>K;
npair start;
pair<int, int> result=make_pair(-INF,INF);
int ay[] = { -1,1,1,-1,0,-1,1,0 };
int ax[] = { -1,1,-1,1,1,0,0,-1 };

char map[MAX][MAX];
ll visit[MAX][MAX];
int area[MAX][MAX];
typedef struct data {
	int y;
	int x;
	ll h;	//high
	ll l;	//low
	ll t;	//tired
}Data;
bool range(int y, int x) {
	return y<0 || x<0 || y>hw - 1 || x>hw - 1 ? 0 : 1;
}
bool village(int y, int x) {
	return map[y][x] == 'P' || map[y][x] == 'K' ? 1 : 0;
}
void init() {
	for (int i = 0; i < hw; i++)
		for (int j = 0; j < hw; j++)
			visit[i][j] = INF;
}
void view() {
	for (int i = 0; i < hw; i++) {
		for (int j = 0; j < hw; j++)
			printf("%10d  ", visit[i][j]);
		cout << endl;
	}
	cout << endl;
}
void solve() {
	queue <Data> q;
	init();
	q.push({ start.fs, start.second,-INF,INF,0 });
	while (!q.empty()) {
		Data out = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = out.y + ay[i];
			int nx = out.x + ax[i];
			int nh = out.h > area[ny][nx] ? out.h : area[ny][nx];
			int nl = out.l < area[ny][nx] ? out.l : area[ny][nx];
			ll nt = out.t;
			if (range(ny, nx)) {
				if (area[ny][nx] - area[out.y][out.x] > 0)
					nt += area[ny][nx] - area[out.y][out.x];
				if (visit[ny][nx] > nt) {
					visit[ny][nx] = nt;
					if (village(ny, nx)) {
						result.fs = result.fs > nh ? result.fs : nh;
						result.second = result.second < nl ? result.second : nl;
						//cout << "height : " << result.fs << tap << result.second << endl;
						continue;
					}
					q.push({ ny,nx,nh,nl,nt });
				}
			}
		}
	}
	//view();
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> hw;
	for (int i = 0; i < hw; i++) {
		scanf("%s", &map[i]);
		for (int j = 0; j < hw; j++) {
			if (map[i][j] == 'K') {
				K.push_back(make_pair(i, j));
			}
			if (map[i][j] == 'P') {
				start = make_pair(i, j);
			}
		}
	}
	for (int i = 0; i < hw; i++)
		for (int j = 0; j < hw; j++)
			cin >> area[i][j];
	solve();
	cout << result.fs << tap << result.second << endl;
	cout << result.fs - result.second;
}
단순 BFS구현코드, 50개 전부 K일때 터짐
*/
