#include <iostream>
#include <string>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

//생성하는 alphabet의 길이에는 상관이없음, 단 최소 26(알파벳 개수)
#define alphabet 27
#define MAX 100001

char name[MAX][501];
char word[MAX][501];
/*
트라이생성후
입력받은 모든값에대해 try삽입
그리고 입력받은 모든값에대해 search를 진행할때,
해당에 대한 부분집합의경우 IsFinish = ture일테므로 이때 cnt++
key = '\0'이 되는부분은 범위를 벗어날때 발생하므로
단어가 같고 길이가 동등할때는 위에 해당되지않으므로 True로 반환하게됨
*/
int cnt;
struct Trie {
	bool isFinish;
	Trie* children[alphabet];

	Trie() :isFinish(false) {
		//memset, isFinish : 전체경로 초기화및 탐색서브조건 초기화
		memset(children, 0, sizeof children);
		//this->isFinish = false;
		//위 생성시 isFinis(false)로 같은역할
	}
	~Trie() {
		//children[i]가 존재할때 삭제
		for (int i = 0; i < alphabet; i++)
			if(children[i]) delete this->children[i];
	}
	void insert(const char* key) {
		if (*key == '\0') {
			isFinish = true;
		}
		//키 늘려주기 :키 늘려주기는 BFS,DFS일때 늘려주기
		//단순히 문자열을 찾아갈때는 필요없음
		//즉  count수가 들어갈땐 문자열 추가해서 비교할필요없고, 
		//문자열이 동등한지 비교할땐 더하면서 찾아감
		//다음키찾아가기
		//키 설정을 해서 다음키를 찾아가주기
		else {
			int cur = *key - 'a';
			if (children[cur] == NULL) { children[cur] = new Trie(); }
			children[cur]->insert(key + 1);
		}
	}
	bool search(const char* key) {
		//문자열끝에 다다랐을때, 그것이 이미 있던것임을 판별하기위해선
		//그 마지막잘이의 isFinish를 보면됨
		//굳이 isFinish를 밖으로꺼내서 return시키거나, 체크해주지않아도됨
		//단, 특정문자열을 탐색할때, 해당구간에 어떤단어가 포함되는지를 확인하려면
		//isFinish를 밖으로꺼내서 조건을걸어줘야함 ex)전화번호목록
		if (*key == '\0') return isFinish;
		//이후 다음키 찾아가기
		int cur = *key - 'a';
		//NULL 배제
		if (children[cur] == NULL) return false;
		return children[cur]->search(key + 1);
	}
};
int total, line;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> total >> line;
	Trie* root = new Trie;
	for (int i = 0; i < total; i++) {
		cin >> name[i];
		root->insert(name[i]);
	}
	for (int i = 0; i < line; i++) {
		cin >> word[i];
		 if (root->search(word[i]))
			cnt++;
	}
	cout << cnt;
	delete root;
}