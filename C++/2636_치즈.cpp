/*
#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 101

int h, w;

int ay[] = {0,0,-1,1};
int ax[] = {-1,1,0,0};

bool map[MAX][MAX];
bool air[MAX][MAX];
bool chiz[MAX][MAX];
bool check[MAX][MAX];
bool visit[MAX][MAX];

typedef struct data {
	int y;
	int x;
}Data;

void chk_view() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << check[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void chiz_view() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << chiz[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void air_view() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << air[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
bool range(int y, int x) {
	return y<0 || x<0 || y>h - 1 || x>h - 1;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> h >> w;
	//치즈구하기
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				chiz[i][j] = true;
			}
		}
	queue<Data>q;
	q.push(Data{ 0, 0 });
	//치즈 밖부분구하기
	while (!q.empty()) {
		Data out = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = out.y + ay[i];
			int nx = out.x + ax[i];
			if (!chiz[ny][nx] && !check[ny][nx] && !range(ny, nx)) {
				check[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
	//치즈안쪽 공기구하기
	vector <Data> inair;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			//치즈가아니고, 밖공기가 아닌경우
			if (!chiz[i][j] && !check[i][j]) {
				inair.push_back({ i,j });
				air[i][j] = true;
			}
		}
	chiz_view();
	chk_view();
	int Size = 0;
	int cnt = 0;
	while (true) {
		vector <Data> temp;
		//치즈녹일부분 찾기
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (chiz[i][j]) {
					for (int k = 0; k < 4; k++) {
						int ny = i + ay[k];
						int nx = j + ax[k];
						if (check[ny][nx]) {
							temp.push_back({ i, j });
							break;
						}
					}
				}
			}
		}
		cout << temp.size() << endl;
		if (temp.size() == 0)
			break;
		//치즈녹이기
		Size = temp.size();
		for (Data it : temp) {
			chiz[it.y][it.x] = false;
			check[it.y][it.x] = true;
		}
		chiz_view();
		chk_view();
		air_view();
		//치즈가녹은뒤 안쪽공기가 밖공기와 만났다면
		//만난곳의 섬을 check=1로 진행하기
		for (Data it : inair) {
			for (int i = 0; i < 4; i++) {
				int ny = it.y + ay[i];
				int nx = it.x + ax[i];
				if (check[ny][nx] && !check[it.y][it.x]) {
					q.push(it);
					while (!q.empty()) {
						Data out = q.front(); q.pop();
						for (int k = 0; k < 4; k++) {
							int ky = out.y + ay[k];
							int kx = out.x + ax[k];
							if (!check[ky][kx] && air[ky][kx]) {
								check[ky][kx] = true;
								q.push({ ky, kx });
							}
						}
					}
					break;
				}
			}
		}
		chiz_view();
		chk_view();

		cnt++;
	}
	cout << cnt << endl;
	cout << Size << endl;
}
*/