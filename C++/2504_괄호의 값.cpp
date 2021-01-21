/*
÷���������������� ��Ȯ�� ���� �������ѹ���
�������׾ư��� ������ ã�Ƴ��°����߿�
��ȣ�ȿ� �����ϴ� ���� ����̾���
��ȣ�ȿ� �����ϴ� ����°���
(())[[]] �̰��� (2)(3)���� ��ȯ�ȰͰ� ���ٰ������
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