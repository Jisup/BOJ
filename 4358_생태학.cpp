/*
STL contianer : map
#include <map>
map :: key and value 로 이루어진 Dictionary 또는 집합
set과 동일하게 find(), end()로 원소를 찾을 수 있으며 insert()제공
기본정렬기준은 less<>(), key는 유일성을 가짐

생성 및 insert
map <key, value> map;
1) map.insert(make_pair(key, value));
2) map[key]=value;

호출방법
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
		//무조건 암기하기, 문자열 입력받을시 #include<string> 의 getline(cin, inputvalue);
		getline(cin, input);
		if (input == "")
			break;
		cnt++;
		if (m.find(input) == m.end())
			m[input] = 1;
		else
			m[input]++;
	}
	//고정소수점 설정
	cout.setf(ios::fixed);
	//고정소수점 해제 -> 정수포함 precision(n)개의 자릿수가표현됨
	//cout.unsetf(ios::fixed);
	//고정소수점 아래 자리수 출력
	cout.precision(4); 
	for (auto it : m) {
	//for (pair<string, float> it : m)
		for (char out : it.first)
			cout << out;
		cout << " ";
		
		
		float value = (it.second / cnt) * 100;
		cout << value << endl;
	}
	//소수점고정 해제
	//cout.precision(false);
}