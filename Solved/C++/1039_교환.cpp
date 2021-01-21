
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define fs first
#define se second
#define MAX 0

int high = -INF;
int len;
char temp[8];
int result(string a) {
	int res = 0;
	for(int i=0;i<len;i++) {
		res += (a[i]-'0') * pow(10, len - 1 - i);
	}
	return res;
}
//2개를 겹치지않게 n번 고르는경우
//이전의 index를 바로 교환하는 경우만 제외시키면됨
//bfs에서 구조체에 
typedef struct data {
	string word;
	int index_a;	//이전에 사용된 인덱스 1
	int index_b;	//이전에 사용된 인덱스 2
	int touch;
}Data;
void solve(int touch) {
	queue <Data> q;
	q.push({ temp, -1, -1, 0 });
	while (!q.empty()) {
		int roof = q.size();
		set <string> s;
		for (int k = 0; k < roof; k++) {
			Data out = q.front(); q.pop();
			if (touch == out.touch) {
				int res = result(out.word);
				high = high > res ? high : res;
//				cout << "high =" << high << endl;
				continue;
			}
			for (int i = 0; i < len; i++) {
				for (int j = i + 1; j < len; j++) {
					string nw = out.word;
					char temp = nw[i];
					nw[i] = nw[j];
					nw[j] = temp;
					if (s.find(nw) == s.end()) {
						if (nw[0] != '0') {
							q.push({ nw, i, j, out.touch + 1 });
							s.insert(nw);
//							for (int i = 0; i < len; i++)
//								cout << nw[i];
//							cout << "\t" << i << "\t" << j << "\ttouch : " << out.touch + 1 << endl;
						}
					}
				}
			}
		}
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int touch;
	scanf("%s %d", &temp, &touch);
	len = strlen(temp);
	if (strlen(temp)>1) 
		solve(touch);
	high == -INF ? printf("-1") : printf("%d", high);
}
 