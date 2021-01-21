#include <iostream>
#include <string>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
#define tap "\t"
#define endl "\n"
#define alphabet 26
struct Trie {
	//isFinish를 int로 바꾼뒤 진행했지만, 그에대한결과는 그저 문자의 길이를 저장하는것으로 끝남
	//모든문자열을 저장한후, 현재확인중인 문자에서 다음 문자로 넘어가는 경로가 2이상이거나
	//해당지점에서 문자열이 끝나는 경우 버튼을 눌러야 하는 경우이므로
	//위 두가지경우에 count증가시켜 return하면된다

	int set;	//문자가 새로 생성될경우 cnt증가
	bool isFinish;
	Trie* children[alphabet];

	Trie() : isFinish(false), set(0) {
		memset(children, 0, sizeof children);
	}
	~Trie() {
		for (int i = 0; i < alphabet; i++)
			if (children[i])delete this->children[i];
	}
	void insert(const char* key) {
		if (*key == '\0') { isFinish = true; }
		else {
			int cur = *key - 'a';
			if (children[cur] == NULL) {
				//노드를 새로 추가할때
				//노드의 수를 나타내는 set을 증가시킴
				children[cur] = new Trie();
				set++;
			}
			children[cur]->insert(key + 1);
		}
	}
	int search(int y, const char* key) {
		if (*key == '\0') return y;
		else {
			//해당구간이 1이상이거나, 겹치는 문자가 존재할경우
			//새로운 타자를 눌러야 하는의미
			if (set > 1 || isFinish)
				y++;
			int cur = *key - 'a';
			return children[cur]->search(y, key + 1);
		}
	}
};

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(2);
	while (true) {
		int tc = 0;
		cin >> tc;
		if (!tc) break;
		Trie* root = new Trie;
		char word[10001][81];
		for (int i = 0; i < tc; i++) {
			cin >> word[i];
			root->insert(word[i]);
		}
		int result = 0;
		for (int i = 0; i < tc; i++) {
			int res = root->search(0, word[i]);
			//root에서 가는 자식의 경우의수가 1개인경우 매번 추가
			if (root->set == 1) result += 1;
			if (res != -1) {
				result += res;
			}
		}
		float out = (float)result / tc;
		cout << out << endl;
		delete root;
	}
}
