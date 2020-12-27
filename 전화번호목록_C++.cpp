#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

char phone[1000001][21];

struct Trie {
	bool isFinish;
	Trie *children[11];

	Trie() : isFinish(false) {
		memset(children, 0, sizeof children);
	}
	~Trie() {
		for (int i = 0; i < 11; i++)
			if (children[i]) delete children[i];
	}
	void insert(const char *key) {
		if (*key == '\0') { isFinish = true; return; }
		int cur = *key - '0';
		if (children[cur] == NULL) children[cur] = new Trie();
		children[cur]->insert(key + 1);
	}
	bool search(const char *key) {
		if (*key == '\0') return true;
		if (isFinish) return false;
		int cur = *key - '0';
		if (!children[cur]) return false;
		return children[cur]->search(key + 1);
	}
};

bool solution(vector<string> phone_book) {
	bool answer = true;
	Trie* root = new Trie;
	int Size = phone_book.size();
	for (int i = 0; i < Size; i++) {
		for (int k = 0; k < phone_book[i].length(); k++)
			phone[i][k] = phone_book[i][k];
	}
	for (int i = 0; i < Size; i++) {
		root->insert(phone[i]);
	}
	for (int i = 0; i < Size; i++) {
		if (!root->search(phone[i])) {
			answer = false;
			break;
		}
	}
	return answer;
}