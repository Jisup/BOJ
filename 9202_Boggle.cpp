#include <iostream>
#include <string.h>
#include <string>
#include <set>
#pragma warning(disable:4996)
using namespace std;
/*

Ʈ���� : ���ڿ��� �����ϰ� ȿ�������� Ž���ϱ����� Ʈ�������� �ڷᱸ��
���ڿ�Ž���� �����ϰԾ��� -> �˻��� �ڵ��ϼ�, ��������ã��, ���ڿ��˻�
���ϱ乮�ڿ� L / �� ���ڿ� �� M
�����ð����⵵ On(L*M)
Ž���ð����⵵ On(L)

*/

//Ʈ���� �⺻����!
#define endl "\n"
#define MAX 4
//�湮�迭�� ���� ���̸�ŭ
int total, tc;
set <string> res;

int ay[] = { 0,0,-1,1,-1,-1,1,1 };
int ax[] = { -1,1,0,0,-1,1,-1,1 };
char map[MAX][MAX];
bool visit[MAX][MAX];
int score[] = { 0,0,0,1,1,2,3,5,11 };
bool range(int y, int x) {
	return y<0 || x<0 || y>MAX - 1 || x>MAX - 1 ? 0 : 1;
}
struct Trie {
	bool isFinish;
	Trie* children[26];

	//constructor ������
	Trie() : isFinish(false) {
		memset(children, 0, sizeof children);
	}
	//destructor �Ҹ���
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (children[i])delete this->children[i];
	}
	//key ���� 
	void insert(const char *key) {
		//������� �ڽ��� ���κ��̶��, ���κ����� ǥ��(isFinish)
		if (*key == '\0') isFinish = true;
		else {
			int cur = *key - 'A'; // index - cursor(Ŀ��, ��ġ)
			if (children[cur] == NULL) children[cur] = new Trie();//�ڽ����������������� ����
			//key�� '0'�� ����ų������ �ڽ��� ����
			children[cur]->insert(key + 1);
		}
	}
	//key ��Ī
	//bfs-dfs�� ���յ� ���ڿ�Ž��
	//bfs-dfs�� �ʿ��� ��ǥ(y, x)�� �߰������� �ʿ��ϰ�
	//�湮ǥ�ø� ����ϴ� visit�迭, ������ �Ѿ���ʵ��� �������ְ�
	//������ǥ�� ���� NULL�̶��, Trie�� �������� �������̶�� �������־���ϸ�
	//���� �������� �Ѿ �� �ְԲ� ���������� ���־����
	void search(int y, int x, string key) {
		if (!range(y, x)) return;
		if (visit[y][x])return;
		//�������� �־��� �ִ���� �ƿ� ����
		if (key.size() >= 8)return;
		visit[y][x] = true;
		//Ű ���� ã�ư���
		key += map[y][x];

		//���� x y�� �ʿ����� child������ ����
		int cur = map[y][x] - 'A';

		if (children[cur] == NULL) {	// �������������� �̹湮ǥ���� ����
			visit[y][x] = false;
			return;
		}
		//�ڽĳ���� ���̶�� �������� �־��� �ߺ��� ������ set�� insert
		if (children[cur]->isFinish) res.insert(key);
		//�������� �־��� �迭���� �̵��� �� �ִ� ���� �� Ƚ���� ���� �̵���
		//child�� ���� search�� ���󰡵��� �������
		for (int i = 0; i < 8; i++) {
			int ny = y + ay[i];
			int nx = x + ax[i];
			children[cur]->search(ny, nx, key);
		}
		visit[y][x] = false;
	}

};
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> total;
	//root Ʈ���̱��� ����
	Trie* root = new Trie;
	//���ڸ� �Է¹���������, Ʈ����Ʈ���� ���ڻ���
	while (total-- > 0) {
		char input[10];
		cin >> input;
		root->insert(input);
	}
	cin >> tc;
	while (tc-- > 0) {
		for (int i = 0; i < MAX; i++) cin >> map[i];
		//tc ���� set �ʱ�ȭ
		res.clear();
		// ???
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				root->search(i, j, "");
		//���� �� ���ڿ�
		//why res.begin()
		string longest = *(res.begin());
		//why res.size?
		int scoreSum = 0;
		for (string item : res) {
			//����� ���ڿ�����
			if (longest.size() < item.size())
				longest = item;
			scoreSum += score[item.size()];
		}
		cout << scoreSum << " " << longest << " " << res.size() << endl;
	}
}
