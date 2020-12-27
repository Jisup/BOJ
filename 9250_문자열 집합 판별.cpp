#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define alphabet 26

char word[10001];

struct Trie {
	//bool isFinish :; finish대신 output (가독성)
	bool output;
	//문자에 대해 go~목적지가 존재하지 않을때, 되돌아가는 노드
	Trie* fail;
	//Trie* children[alphabet] :; 현재 노드에서 문자를 받고 다음으로 진행
	Trie* go[alphabet];

	Trie() : output(false){
		memset(go, 0, sizeof go);
	}
	~Trie() {
		for (int i = 0; i < alphabet; i++)
			if (go[i])delete this->go[i];
	}
	void insert(const char* key) {
		if (*key == '\0') output = true;
		else {
			int cur = *key - 'a';
			if (go[cur] == NULL) go[cur] = new Trie();
			go[cur]->insert(key + 1);
		}
	}
	//야호코라식에선 search가 필요없음 , 따로 Bfs함수가 만들어지기때문
	/*bool search(const char* key) {
		if (*key == '\0') return this;
		if (isFinish) return true;
		int cur = *key - 'a';
		if (children[cur] == NULL)return-1;
		return children[cur]->search(key + 1);
	}*/
};
/*
https://m.blog.naver.com/kks227/220992598966
아호코라식 : Aho-Corasick
1:N 패턴매칭으로 KMP의 상위버전, KMP는 Aho-Corasick의 하위버전

트라이 구조로 진행될때, 글자에 대한 다음경로가 존재하지않으면 첫 노드로 복귀
다음경로가 존재한다면 그 경로의 노드로 [ Go ],
특정노드까지도달했을때, 그부분에 매칭되는 문자열이 있다면 이곳을 [ Output ]이라 부른다

이때 같은 알파벳에 여러경로가 존재하는 때가있는데,
이를 제어해야하는 추가적인함수가 [ fail ]함수

[ fail ]
1) state (현재상태) x, 인풋 c에 대해서 go(x, c)가 존재하면 이동
존재하지않다면, fail(x)로 이동후 다시 state x->c 를 확인함
단, 루트라면 아무일도 진행하지않음
*/

bool isExist(const char* key, Trie* temp) {
	//제일 첫시작 input은 root부터 시작함
	Trie* here = temp;
	//for(int i=0;i<key.length();i++)
	for (int i = 0; key[i]; i++) {
		int cur = *key - 'a';
		//현재 노드에서 갈 수 있는 길이 존재하지않으면
		//fail을 계속해서 따라감
		while (here != temp && !here->go[cur])
			here = here->fail;
		//go함수가 존재하면 이동
		//루트라면 false일 수 있음 (?)
		if (here->go[cur]) here = here->go[cur];
		//단어가 매칭된경우 단어존재파악리턴
		if (here->output) return true;
	}
	//해당 부분에서 문자를 찾아갈 수 없음.
	return false;
}
//fail함수 생성하기 : 제일중요한부분
void bfs(Trie* root) {
	queue <Trie*> q;
	q.push(root);
	while (q.size()) {
		Trie* here = q.front(); q.pop();
		for (int i = 0; i < alphabet; i++) {
			Trie* next = here->go[i];
			// 존재하지않으면 다음단어로
			if (!next) continue;
			// root의  fail경로는 root로 고정
			if (here == root)next->fail = root;
			else {
				Trie* failure = here->fail;
				//참조할 가장 가까운 부모를 찾아감
				while (failure != root && !failure->go[i])
					failure = failure->fail;
				//fail(px) = go(fail(p), x)
				if (failure->go[i]) failure = failure->go[i];
				next->fail = failure;
			}
			// fail(x) = y, output(y) ⊂ output(x)
			if (next->fail->output) next->output = true;
			q.push(next);
		}
	}
}
int s, a;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Trie* root = new Trie;
	cin >> s;
	//집합
	for (int i = 0; i < s; i++) {
		cin >> word;
		root->insert(word);
	}
	// root의  fail경로는 root로 고정
	root->fail = root;
	bfs(root);
	cin >> a;
	//검색문자열
	for (int i = 0; i < a; i++) {
		cin >> word;
		cout << isExist(word, root) ? "YES" : "NO";
		cout << endl;
	}
	delete root;
}