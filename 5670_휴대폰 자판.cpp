#include <iostream>
#include <string>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
#define tap "\t"
#define endl "\n"
#define alphabet 26
struct Trie {
	//isFinish�� int�� �ٲ۵� ����������, �׿����Ѱ���� ���� ������ ���̸� �����ϴ°����� ����
	//��繮�ڿ��� ��������, ����Ȯ������ ���ڿ��� ���� ���ڷ� �Ѿ�� ��ΰ� 2�̻��̰ų�
	//�ش��������� ���ڿ��� ������ ��� ��ư�� ������ �ϴ� ����̹Ƿ�
	//�� �ΰ�����쿡 count�������� return�ϸ�ȴ�

	int set;	//���ڰ� ���� �����ɰ�� cnt����
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
				//��带 ���� �߰��Ҷ�
				//����� ���� ��Ÿ���� set�� ������Ŵ
				children[cur] = new Trie();
				set++;
			}
			children[cur]->insert(key + 1);
		}
	}
	int search(int y, const char* key) {
		if (*key == '\0') return y;
		else {
			//�ش籸���� 1�̻��̰ų�, ��ġ�� ���ڰ� �����Ұ��
			//���ο� Ÿ�ڸ� ������ �ϴ��ǹ�
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
			//root���� ���� �ڽ��� ����Ǽ��� 1���ΰ�� �Ź� �߰�
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
