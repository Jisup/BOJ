#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;

#define endl "\n"
#define MAX 100001

int total, task;
vector <int> segment_tree;
vector <int> lazy_tree;

void propagate(int start, int end, int node) {
	if (lazy_tree[node]) {
		if (start != end) {
			//����ġ�� on off�̹Ƿ�
			//�� ����ġ ���¿� �ش��ϴ� ���� lazy_tree[node]�̴ϱ�
			//�ش� segement_tree���� lazy_tree�� �������� ���Ե�
			//�����հ�����쿡�� segment_tree�� lazy_tree�� �ջ������
			//����ġ�� on off�� �ش��ϹǷ� segmenttree�� ���º�ȭ�� ����
			//segment_Tree�� �����ϴ°Ծƴϰ� lazytree�� ������
			//propagate������ lazy_tree�� ��ü���� ���º�ȭ�� �Ű澲�°�
			//update�� segment�� ���º�ȭ�� �Ű澲�°����� �������� �����Ұ�
			lazy_tree[node * 2] = !lazy_tree[node * 2];
			lazy_tree[node * 2 + 1] = !lazy_tree[node * 2 + 1];
		}
		//segment_tree���ŵ� ���������� �����հ������
		//lazy_Tree �Ǻ���Ȱ��� �ջ�Ǿ�������� 
		//����ġ�ǰ�� ���� segmenttree������� ����ġ�������� ������Ű���ǹ̷�
		//���ΰ����ؾ���

		segment_tree[node] = (end - start + 1) - segment_tree[node];
		//segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
		//������ ��������µ� �ٽ� ���ŵ� �ʿ䰡 ����.
		//lazyƮ���ȿ� �ִ� ���ڸ�segment�� �����ϴ� ���̹Ƿ� segment�θ��� ������ Ȯ���� �ʿ䰡 ����?
		lazy_tree[node] = 0;
	}
}
int make(int start, int end, int node) {
	if (start == end)return segment_tree[node];
	int mid = (start + end) / 2;
	return segment_tree[node] = make(start, mid, node * 2) + make(mid + 1, end, node * 2 + 1);
}
int query(int start, int end, int node, int left, int right) {
	propagate(start, end, node);
	if (left > end || right < start) return 0;
	//���⵵Ʋ�ȳ�
	if (left <= start && end <= right)return segment_tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}
//update�� ��ټ� void���� �̹�ȯ����
void update(int start, int end, int node, int left, int right) {
	propagate(start, end, node);
	/*
	if (start == end) return segment_tree[node];
	�� �Ʒ��������� �����̳�������
	query���� ������ �Ǵ� ���������� ����ϸ鼭 �ܿ��
	*/
	// query�� �������� : ������ �Ǵ��� ����ó��
	//					  ���� ���� �Ǵ��ϱ�
	// query�� �ٸ���   : ���� �����϶� node�� ���� ��ȯ�ϴ°Ծƴ� lazy_tree ������ segment_Tree�� lazy_tree ����
	//					  �������Ŀ� �Ʊ� propagate���� ������ �θ𰻽��� update���� �Ͼ�Ե�			  
	if (left > end || right < start) return;

	/*
	start==end�϶��� ������ �Լ��� ���ϵǴ� �������� �����ؾ���
	if (start == end) {
		segment_tree[node] = segment_tree[node] == 1 ? 0 : 1;
	}
	*/
	
	//�� ��Ÿ�־��� end << right : �ݺ������� ������ �Ǽ� üũ
	if (left <= start && end <= right) {
		//�����տ����� lazy�� ������ ������ �ٲ��ص� �簻�����ߵ�
		/*
		lazy_tree[node] = 1;
		propagate(left, right, node);
		return 0;
		*/
		//����ġ������ start==end �϶� ����ġ�� ��ȯ�ǹǷ�
		//�θ��忡�� ������ ���Եȴٸ�, �ڽĳ����� switch ���������� �ٲ�����
		segment_tree[node] = (end - start + 1) - segment_tree[node];
		//start==end���´� ���ܳ���̹Ƿ�
		//���ܳ�嶧�� lazy �ڽ����� ��ѷ������ϹǷ�.
		if (start == end)return;
		lazy_tree[node * 2] = !lazy_tree[node * 2];
		lazy_tree[node * 2 + 1] = !lazy_tree[node * 2 + 1];
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right);
	update(mid + 1, end, node * 2 + 1, left, right);

	//��ü ���׸�Ʈ Ʈ���� ������
	segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> total >> task;

	int height = (int)ceil(log2(total));
	int segmentTreeSize = 1 << (height + 1);
	segment_tree.resize(segmentTreeSize);
	lazy_tree.resize(segmentTreeSize);
	
	for (int i = 0; i < task; i++) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a==0) {
			update(0, total - 1, 1, b - 1, c - 1);
			continue;
		}
		cout << query(0, total - 1, 1, b - 1, c - 1) << endl;;
	}
}