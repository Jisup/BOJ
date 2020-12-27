#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
#define endl "\n"
string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	map <string, int> m;
	map <string, int> m2;
	for (string item : completion)
		m[item]++;
	for (string item : participant) {
		if (!m[item]) {
			answer = item;
			continue;
		}
		m[item]--;
	}
	return answer;
}