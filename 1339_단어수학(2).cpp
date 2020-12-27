
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define fs first
#define se second
#define MAX 11


int temp;
char tmp[MAX][9];
vector <string> word;
bool check[27];
char res[27];
string result;

void solve() {
	memset(check, 0, sizeof check);
	sort(word.begin(), word.end(), [](const string &a, const string &b) {return a.size() < b.size() || a.size() == b.size() && a < b; });
	int len = word[word.size() - 1].length();
	for (int i = 0; i < len; i++) {
		for (int k = 0; k < word.size(); k++) {
			if (word[k].length() > i) result += word[k][i];
		}
	}
	reverse(result.begin(), result.end());
	int num = 10;
//	for (int i = 0; i < result.length(); i++)
//		cout << result[i];
//	cout << endl;
	for (int i = 0; i < result.length(); i++) {
		if (!check[result[i] - 'A']) {
			check[result[i] - 'A'] = true;
			res[result[i] - 'A'] = --num;
		}
	}
	for (int k = 0; k < temp; k++) {
		for (int i = 0; i < strlen(tmp[k]); i++) {
			tmp[k][i] = res[tmp[k][i]-'A']+'0';
		}
	}
	//view();
	int output = 0;
	for(int i=0;i<temp;i++)
		for (int j = 0; j < strlen(tmp[i]); j++) {
			//cout << (tmp[i][strlen(tmp[i]) - j - 1] - '0') * pow(10, j) << endl;
			output += (tmp[i][strlen(tmp[i]) - j - 1] - '0') * pow(10, j);
		}
	cout << output;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d\n", &temp);
	for (int k = 0; k < temp; k++) {
		string tp = "";
		scanf("%s", &tmp[k]);
		for (int i = strlen(tmp[k]) - 1; i >= 0; i--)
			tp += tmp[k][i];
		word.push_back(tp);
	}
	solve();
}
