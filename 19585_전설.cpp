#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <set>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0
#define alphabet 26

char temp[2005];
set <string> s;

struct Trie {
	bool isFinish=false;
	Trie* children[alphabet] = { NULL, 0 };
	/*
	Trie() :isFinish(false) {
		memset(children, 0, sizeof children);
	}
	
	~Trie() {
		for (int i = 0; i < alphabet; i++)
			if (children[i]) delete children[i];
	}
	*/
	void insert(const char* key) {
		if (*key == '\0') { isFinish = true; }
		else {
			int cur = *key - 'a';
			if (children[cur] == NULL) children[cur] = new Trie;
			children[cur]->insert(key + 1);
		}
	}
	bool search(const char* key) {
		if (*key == '\0') return false;
		if (isFinish) {
			/*
			정말생각지도못한풀이법, 내첫설계는 color와 name에 대해
			root에서 전부 trie설계이후 color에 대한 true가 나올시
			root로 되돌아가 name에 대해 탐색하는것이었다.
			당연히 결과는 메모리초과였음
			근데 이것은
			문자열 첫번째에 무조건 color가나오고 이후에 name이 나오므로
			color에 대해 insert이후, 전체키탐색시 color가 존재한다면
			나머지 글자 key (이걸생각못했음 key가 전체적으로 redshift가 주어질때
			key+1될때마다 key는 edshift->dshift->shift가 되는것을 인지하지못함,
			디버그하면서 자주봐왔을 모습인데 활용, 응용하지못하였음)
			가 name에 존재해야되므로
			기존 입력받은 name은 중복되지않는것이고, 존재/미존재 여부를 쉽게알수잇는 set을이용하여 판별
			이후 존재한다면 s.find()!=s.end() = true일때
			key(name)은 수상할수 있다
			*/
			if (s.find(key) != s.end()) return true;
		}
		int cur = *key - 'a';
		if (children[cur] != NULL) {
			return children[cur]->search(key + 1);
		}
		else return false;
	}
};

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, n;
	cin >> c >> n;

	Trie* root = new Trie();
	for (int i = 0; i < c; i++) {
		cin >> temp;
		root->insert(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		s.insert(temp);
	}
	int tc;
	cin >> tc;
	while (tc-- > 0) {
		cin >> temp;
		root->search(temp) ? puts("Yes") : puts("No");
	}
}
