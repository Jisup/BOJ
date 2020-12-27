/*
STL contianer : map
#include <map>
map :: key and value �� �̷���� Dictionary �Ǵ� ����
set�� �����ϰ� find(), end()�� ���Ҹ� ã�� �� ������ insert()����
�⺻���ı����� less<>(), key�� ���ϼ��� ����

���� �� insert
map <key, value> map;
1) map.insert(make_pair(key, value));
2) map[key]=value;

ȣ����
1) for(auto it = m.begin(); it != m.end(); it++) {
//for(auto it : m) {
	key = it->first;
	value = it->second;
}

2) map<key,value>::iterator it
for(it = m.begin(); it != m.end(); it++) {
//for(it : m)
}
*/
#include <iostream>
#include <string>
#include <map>
#pragma warning(disable:4996)
using namespace std;

map<string, float> m;
#define endl "\n"
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int cnt = 0;
	while (true) {
		string input = "";
		//������ �ϱ��ϱ�, ���ڿ� �Է¹����� #include<string> �� getline(cin, inputvalue);
		getline(cin, input);
		if (input == "")
			break;
		cnt++;
		if (m.find(input) == m.end())
			m[input] = 1;
		else
			m[input]++;
	}
	//�����Ҽ��� ����
	cout.setf(ios::fixed);
	//�����Ҽ��� ���� -> �������� precision(n)���� �ڸ�����ǥ����
	//cout.unsetf(ios::fixed);
	//�����Ҽ��� �Ʒ� �ڸ��� ���
	cout.precision(4); 
	for (auto it : m) {
	//for (pair<string, float> it : m)
		for (char out : it.first)
			cout << out;
		cout << " ";
		
		
		float value = (it.second / cnt) * 100;
		cout << value << endl;
	}
	//�Ҽ������� ����
	//cout.precision(false);
}