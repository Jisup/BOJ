#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
int type;
vector <int> v;
void permutation() {
	if (prev_permutation(v.begin(), v.end())) {
		for (int item : v)
			cout << item << " ";
		cout << endl;
	}
	else
		cout << -1;
}
void solve() {
	//�ִ��ε�����ġ
	int index = type - 1;
	//���簪�� ���������� ���� �ε���ã��
	while (index > 0 && v[index - 1] <= v[index])
		index--;
	if (index==0) { cout << -1 << endl; return; }
	
	int next_index = type - 1;
	//ã�� �ε������� ���� �ε����� ã��
	while (v[index - 1] <= v[next_index])
		next_index--;
	swap(v[index - 1], v[next_index]);
	
	int sort_index = type - 1;
	//�ܿ� �� �ε����� ã��
	//���������ְ�
	//����<���Ķ�� ��ü������ ���������ָ鼭 ����++,����--
	while (index < sort_index) {
		swap(v[index], v[sort_index]);
		index++;
		sort_index--;
	}
	for (int it : v)
		cout << it << " ";
	cout << endl;
}
int main() {
	cin >> type;
	v.resize(type);
	for (int i = 0; i < type; i++)
		cin >> v[i];
	//permutation();
	solve();
}