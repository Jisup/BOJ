#include <iostream>
#include <string.h>
#include <string>
#include <set>
#pragma warning(disable:4996)
using namespace std;
#define wordlen 11
#define MAX 10001

char phone[MAX][wordlen];
struct Trie {
	bool isFinish;
	//char 아니고 Trie*
	Trie* children[wordlen];

	Trie() : isFinish(false){
		//생성자 -> 초기화! 기억하기
		memset(children, 0, sizeof children);
		//this-> 빠트리지않기 : 생성자 소멸자에서 반드시필요
		this->isFinish = false;
	}
	~Trie() {
		//소멸자! 생성한 children모두삭제하기
		for (int i = 0; i < wordlen; i++)
			if (children[i])delete this->children[i];
	}
	void insert(const char *key) {
		//말단노드랑 일반노드 구분짓기
		if (*key == '\0') isFinish = true;
		else {
			//좌표압축 '0' -> 0
			int cur = *key - '0';
			//자식cursor가 Null일때 자식노드 생성해주기
			if (children[cur] == NULL)  children[cur] = new Trie();
			//자식노드가 널이아니라면! 다음키값 순회
			children[cur]->insert(key + 1);
		}
	}
	//기본적인 1차원 문자열탐색
	bool search(const char *key) {
		//아래가 search기본구조
		//키의 끝에 다다르면 정상적완료
		if (*key == '\0') return true;
		//중간에 isFinish를 만나게되면 해당문자열이 끝나기전에
		//겹치는 문자가 존재한다는 의미
		if (isFinish) return false;
		//다음 cursor를 찾아가기
		int cur = *key - '0';
		//why ? 근데왜 key+1일까 ?
		return children[cur]->search(key + 1);
	}
};
bool flag;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc, book;
	cin >> tc;
	while (tc-- > 0) {
		cin >> book;
		for (int i = 0; i < book; i++)
			cin >> phone[i];
		//new Trie() 아님, 클래스생성 아니고, 구조생성임
		//입력순서는
		//1)  Trie의 root 생성
		//root에 연결된 단어들 생성
		//root를 통해 search
		Trie* root = new Trie;
		flag = true;
		for (int i = 0; i < book; i++)
			root->insert(phone[i]);
		for (int i = 0; i < book; i++) {
			if (!root->search(phone[i]))
				flag = false;
		}
		flag ? cout << "YES" : cout << "NO" ;
		cout << endl;
	}
}