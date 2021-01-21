#include <iostream>
#include <string.h>
#include <string>
#include <set>
#pragma warning(disable:4996)
using namespace std;
/*

트라이 : 문자열을 저장하고 효율적으로 탐색하기위한 트리형태의 자료구조
문자열탐색시 유용하게쓰임 -> 검색어 자동완성, 사전에서찾기, 문자열검사
제일긴문자열 L / 총 문자열 수 M
생성시간복잡도 On(L*M)
탐색시간복잡도 On(L)

*/

//트라이 기본구조!
#define endl "\n"
#define MAX 4
//방문배열은 맵의 길이만큼
int total, tc;
set <string> res;

int ay[] = { 0,0,-1,1,-1,-1,1,1 };
int ax[] = { -1,1,0,0,-1,1,-1,1 };
char map[MAX][MAX];
bool visit[MAX][MAX];
int score[] = { 0,0,0,1,1,2,3,5,11 };
bool range(int y, int x) {
	return y<0 || x<0 || y>MAX - 1 || x>MAX - 1 ? 0 : 1;
}
struct Trie {
	bool isFinish;
	Trie* children[26];

	//constructor 생성자
	Trie() : isFinish(false) {
		memset(children, 0, sizeof children);
	}
	//destructor 소멸자
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (children[i])delete this->children[i];
	}
	//key 삽입 
	void insert(const char *key) {
		//만들어진 자식중 끝부분이라면, 끝부분임을 표기(isFinish)
		if (*key == '\0') isFinish = true;
		else {
			int cur = *key - 'A'; // index - cursor(커서, 위치)
			if (children[cur] == NULL) children[cur] = new Trie();//자식이존재하지않으면 생성
			//key가 '0'을 가르킬때까지 자식을 생성
			children[cur]->insert(key + 1);
		}
	}
	//key 서칭
	//bfs-dfs가 결합된 문자열탐색
	//bfs-dfs에 필요한 좌표(y, x)가 추가적으로 필요하고
	//방문표시를 담당하는 visit배열, 범위를 넘어가지않도록 제어해주고
	//현재좌표의 값이 NULL이라면, Trie가 생성되지 않은값이라면 제거해주어야하며
	//다음 방향으로 넘어갈 수 있게끔 방향조정을 해주어야함
	void search(int y, int x, string key) {
		if (!range(y, x)) return;
		if (visit[y][x])return;
		//문제에서 주어진 최대길이 아웃 설정
		if (key.size() >= 8)return;
		visit[y][x] = true;
		//키 만들어서 찾아가기
		key += map[y][x];

		//현재 x y의 맵에대한 child에따라서 결정
		int cur = map[y][x] - 'A';

		if (children[cur] == NULL) {	// 존재하지않으면 미방문표시후 리턴
			visit[y][x] = false;
			return;
		}
		//자식노드의 끝이라면 문제에서 주어진 중복자 제거후 set에 insert
		if (children[cur]->isFinish) res.insert(key);
		//문제에서 주어진 배열에서 이동할 수 있는 범위 및 횟수에 따라 이동후
		//child가 다음 search를 따라가도록 경로제어
		for (int i = 0; i < 8; i++) {
			int ny = y + ay[i];
			int nx = x + ax[i];
			children[cur]->search(ny, nx, key);
		}
		visit[y][x] = false;
	}

};
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> total;
	//root 트라이구조 선언
	Trie* root = new Trie;
	//문자를 입력받을때마다, 트라이트리에 문자삽입
	while (total-- > 0) {
		char input[10];
		cin >> input;
		root->insert(input);
	}
	cin >> tc;
	while (tc-- > 0) {
		for (int i = 0; i < MAX; i++) cin >> map[i];
		//tc 마다 set 초기화
		res.clear();
		// ???
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				root->search(i, j, "");
		//가장 긴 문자열
		//why res.begin()
		string longest = *(res.begin());
		//why res.size?
		int scoreSum = 0;
		for (string item : res) {
			//가장긴 문자열저장
			if (longest.size() < item.size())
				longest = item;
			scoreSum += score[item.size()];
		}
		cout << scoreSum << " " << longest << " " << res.size() << endl;
	}
}
