#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 101
#define INF MAX*100001

int c, bus;

int cost[MAX][MAX];

void floyd() {
	for (int k = 1; k <= c; k++)
		for (int y = 1; y <= c; y++)
			for (int x = 1; x <= c; x++)
				if (y != x && cost[y][x] > cost[y][k] + cost[k][x])
					cost[y][x] = cost[y][k] + cost[k][x];
}
void view() {
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= c; j++) {
			if (cost[i][j] == INF) {
				cout << 0 << " ";
				continue;
			}
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}
}
void init() {
	for (int i = 1; i <= c; i++)
		for (int j = 1; j <= c; j++)
			cost[i][j] = INF;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c;
	cin >> bus;
	int start, end, value;
	
	init();
	for (int i = 0; i < bus; i++) {
		cin >> start >> end >> value;
		if (cost[start][end] > value)
			cost[start][end] = value;
	}
	floyd();
	view();
}