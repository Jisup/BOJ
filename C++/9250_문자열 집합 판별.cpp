#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define alphabet 26

char word[10001];

struct Trie {
	//bool isFinish :; finish��� output (������)
	bool output;
	//���ڿ� ���� go~�������� �������� ������, �ǵ��ư��� ���
	Trie* fail;
	//Trie* children[alphabet] :; ���� ��忡�� ���ڸ� �ް� �������� ����
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
	//��ȣ�ڶ�Ŀ��� search�� �ʿ���� , ���� Bfs�Լ��� ��������⶧��
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
��ȣ�ڶ�� : Aho-Corasick
1:N ���ϸ�Ī���� KMP�� ��������, KMP�� Aho-Corasick�� ��������

Ʈ���� ������ ����ɶ�, ���ڿ� ���� ������ΰ� �������������� ù ���� ����
������ΰ� �����Ѵٸ� �� ����� ���� [ Go ],
Ư������������������, �׺κп� ��Ī�Ǵ� ���ڿ��� �ִٸ� �̰��� [ Output ]�̶� �θ���

�̶� ���� ���ĺ��� ������ΰ� �����ϴ� �����ִµ�,
�̸� �����ؾ��ϴ� �߰������Լ��� [ fail ]�Լ�

[ fail ]
1) state (�������) x, ��ǲ c�� ���ؼ� go(x, c)�� �����ϸ� �̵�
���������ʴٸ�, fail(x)�� �̵��� �ٽ� state x->c �� Ȯ����
��, ��Ʈ��� �ƹ��ϵ� ������������
*/

bool isExist(const char* key, Trie* temp) {
	//���� ù���� input�� root���� ������
	Trie* here = temp;
	//for(int i=0;i<key.length();i++)
	for (int i = 0; key[i]; i++) {
		int cur = *key - 'a';
		//���� ��忡�� �� �� �ִ� ���� ��������������
		//fail�� ����ؼ� ����
		while (here != temp && !here->go[cur])
			here = here->fail;
		//go�Լ��� �����ϸ� �̵�
		//��Ʈ��� false�� �� ���� (?)
		if (here->go[cur]) here = here->go[cur];
		//�ܾ ��Ī�Ȱ�� �ܾ������ľǸ���
		if (here->output) return true;
	}
	//�ش� �κп��� ���ڸ� ã�ư� �� ����.
	return false;
}
//fail�Լ� �����ϱ� : �����߿��Ѻκ�
void bfs(Trie* root) {
	queue <Trie*> q;
	q.push(root);
	while (q.size()) {
		Trie* here = q.front(); q.pop();
		for (int i = 0; i < alphabet; i++) {
			Trie* next = here->go[i];
			// �������������� �����ܾ��
			if (!next) continue;
			// root��  fail��δ� root�� ����
			if (here == root)next->fail = root;
			else {
				Trie* failure = here->fail;
				//������ ���� ����� �θ� ã�ư�
				while (failure != root && !failure->go[i])
					failure = failure->fail;
				//fail(px) = go(fail(p), x)
				if (failure->go[i]) failure = failure->go[i];
				next->fail = failure;
			}
			// fail(x) = y, output(y) �� output(x)
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
	//����
	for (int i = 0; i < s; i++) {
		cin >> word;
		root->insert(word);
	}
	// root��  fail��δ� root�� ����
	root->fail = root;
	bfs(root);
	cin >> a;
	//�˻����ڿ�
	for (int i = 0; i < a; i++) {
		cin >> word;
		cout << isExist(word, root) ? "YES" : "NO";
		cout << endl;
	}
	delete root;
}