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
			����������������Ǯ�̹�, ��ù����� color�� name�� ����
			root���� ���� trie�������� color�� ���� true�� ���ý�
			root�� �ǵ��ư� name�� ���� Ž���ϴ°��̾���.
			�翬�� ����� �޸��ʰ�����
			�ٵ� �̰���
			���ڿ� ù��°�� ������ color�������� ���Ŀ� name�� �����Ƿ�
			color�� ���� insert����, ��üŰŽ���� color�� �����Ѵٸ�
			������ ���� key (�̰ɻ��������� key�� ��ü������ redshift�� �־�����
			key+1�ɶ����� key�� edshift->dshift->shift�� �Ǵ°��� ������������,
			������ϸ鼭 ���ֺ����� ����ε� Ȱ��, �����������Ͽ���)
			�� name�� �����ؾߵǹǷ�
			���� �Է¹��� name�� �ߺ������ʴ°��̰�, ����/������ ���θ� ���Ծ˼��մ� set���̿��Ͽ� �Ǻ�
			���� �����Ѵٸ� s.find()!=s.end() = true�϶�
			key(name)�� �����Ҽ� �ִ�
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
