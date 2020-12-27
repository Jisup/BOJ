#include <iostream>
#include <string>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

//�����ϴ� alphabet�� ���̿��� ����̾���, �� �ּ� 26(���ĺ� ����)
#define alphabet 27
#define MAX 100001

char name[MAX][501];
char word[MAX][501];
/*
Ʈ���̻�����
�Է¹��� ��簪������ try����
�׸��� �Է¹��� ��簪������ search�� �����Ҷ�,
�ش翡 ���� �κ������ǰ�� IsFinish = ture���׹Ƿ� �̶� cnt++
key = '\0'�� �Ǵºκ��� ������ ����� �߻��ϹǷ�
�ܾ ���� ���̰� �����Ҷ��� ���� �ش���������Ƿ� True�� ��ȯ�ϰԵ�
*/
int cnt;
struct Trie {
	bool isFinish;
	Trie* children[alphabet];

	Trie() :isFinish(false) {
		//memset, isFinish : ��ü��� �ʱ�ȭ�� Ž���������� �ʱ�ȭ
		memset(children, 0, sizeof children);
		//this->isFinish = false;
		//�� ������ isFinis(false)�� ��������
	}
	~Trie() {
		//children[i]�� �����Ҷ� ����
		for (int i = 0; i < alphabet; i++)
			if(children[i]) delete this->children[i];
	}
	void insert(const char* key) {
		if (*key == '\0') {
			isFinish = true;
		}
		//Ű �÷��ֱ� :Ű �÷��ֱ�� BFS,DFS�϶� �÷��ֱ�
		//�ܼ��� ���ڿ��� ã�ư����� �ʿ����
		//��  count���� ���� ���ڿ� �߰��ؼ� �����ʿ����, 
		//���ڿ��� �������� ���Ҷ� ���ϸ鼭 ã�ư�
		//����Űã�ư���
		//Ű ������ �ؼ� ����Ű�� ã�ư��ֱ�
		else {
			int cur = *key - 'a';
			if (children[cur] == NULL) { children[cur] = new Trie(); }
			children[cur]->insert(key + 1);
		}
	}
	bool search(const char* key) {
		//���ڿ����� �ٴٶ�����, �װ��� �̹� �ִ������� �Ǻ��ϱ����ؼ�
		//�� ������������ isFinish�� �����
		//���� isFinish�� �����β����� return��Ű�ų�, üũ�������ʾƵ���
		//��, Ư�����ڿ��� Ž���Ҷ�, �ش籸���� ��ܾ ���ԵǴ����� Ȯ���Ϸ���
		//isFinish�� �����β����� �������ɾ������ ex)��ȭ��ȣ���
		if (*key == '\0') return isFinish;
		//���� ����Ű ã�ư���
		int cur = *key - 'a';
		//NULL ����
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