/*
첨에문제를접했을때 정확한 길을 잡지못한문제
스택을쌓아갈때 계산법을 찾아내는것이중요
괄호안에 존재하는 수는 상관이없음
괄호안에 존재하는 수라는것은
(())[[]] 이것이 (2)(3)으로 변환된것과 같다고생각됨
*/
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
string input;
stack<char> s;
int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> input;
	long long result = 0;
	int temp = 1;
	for (int i = 0; i < input.size(); i++){
		if (input[i] == '('){
			temp *= 2;
			s.push('(');
		}
		else if (input[i] == '['){
			temp *= 3;
			s.push('[');
		}
		else if (input[i] == ')' && (s.empty() || s.top() != '('))	{
			cout << "0";
			return 0;
		}
		else if (input[i] == ']' && (s.empty() || s.top() != '['))	{
			cout << "0";
			return 0;
		}
		else if (input[i] == ')')	{
			if (input[i - 1] == '(')
				result += temp;
			s.pop();
			temp /= 2;
		}
		else if (input[i] == ']') {
			if (input[i - 1] == '[')
				result += temp;
			s.pop();
			temp /= 3;
		}
	}
	if (!s.empty()) result = 0;
	cout << result;
	return 0;
}