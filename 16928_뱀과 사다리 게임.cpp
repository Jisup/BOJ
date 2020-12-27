#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 101
#define INF 2147483647

int bridge, snake;
vector <int> b[MAX];
vector <int> s[MAX];

typedef struct data {
	int idx;
	int cnt;
}Data;

int visit[MAX];
int least = INF;
void solve() {
	memset(visit, -1, sizeof visit);
	queue <Data> q;
	q.push({ 1, 0 });
	visit[1] = 0;

	while (!q.empty()) {
		Data out = q.front(); q.pop();
		if (out.idx == 100) {
			least = least < out.cnt ? least : out.cnt;
			continue;
		}
		for (int i = 1; i <= 6; i++) {
			int next = out.idx + i;
			int nc = out.cnt + 1;
			//다음칸진행할때 기본적으로 판단하기
			if (next <= 100)
				if (visit[next] == -1 || visit[next] > nc) {
					//다음칸이 뱀이거나 사다리일때
					visit[next] = nc;
					if (b[next].size())
						next = b[next][0];
					else if (s[next].size())
						next = s[next][0];
					//cout << next << tap << nc << endl;
					q.push({ next, nc });
				}
		}
		//cout << endl;
	}
	cout << least;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int temp1, temp2;
	cin >> bridge >> snake;
	for (int i = 0; i < bridge; i++) {
		cin >> temp1 >> temp2;
		b[temp1].push_back(temp2);
	}
	for (int i = 0; i < snake; i++) {
		cin >> temp1 >> temp2;
		s[temp1].push_back(temp2);
	}
	solve();
}
