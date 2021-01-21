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
	//char �ƴϰ� Trie*
	Trie* children[wordlen];

	Trie() : isFinish(false){
		//������ -> �ʱ�ȭ! ����ϱ�
		memset(children, 0, sizeof children);
		//this-> ��Ʈ�����ʱ� : ������ �Ҹ��ڿ��� �ݵ���ʿ�
		this->isFinish = false;
	}
	~Trie() {
		//�Ҹ���! ������ children��λ����ϱ�
		for (int i = 0; i < wordlen; i++)
			if (children[i])delete this->children[i];
	}
	void insert(const char *key) {
		//���ܳ��� �Ϲݳ�� ��������
		if (*key == '\0') isFinish = true;
		else {
			//��ǥ���� '0' -> 0
			int cur = *key - '0';
			//�ڽ�cursor�� Null�϶� �ڽĳ�� �������ֱ�
			if (children[cur] == NULL)  children[cur] = new Trie();
			//�ڽĳ�尡 ���̾ƴ϶��! ����Ű�� ��ȸ
			children[cur]->insert(key + 1);
		}
	}
	//�⺻���� 1���� ���ڿ�Ž��
	bool search(const char *key) {
		//�Ʒ��� search�⺻����
		//Ű�� ���� �ٴٸ��� �������Ϸ�
		if (*key == '\0') return true;
		//�߰��� isFinish�� �����ԵǸ� �ش繮�ڿ��� ����������
		//��ġ�� ���ڰ� �����Ѵٴ� �ǹ�
		if (isFinish) return false;
		//���� cursor�� ã�ư���
		int cur = *key - '0';
		//why ? �ٵ��� key+1�ϱ� ?
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
		//new Trie() �ƴ�, Ŭ�������� �ƴϰ�, ����������
		//�Է¼�����
		//1)  Trie�� root ����
		//root�� ����� �ܾ�� ����
		//root�� ���� search
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