
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define fs first
#define se second
#define MAX 16

int l, ea;
vector <char> word;
char result[MAX];
bool check[MAX];
bool match(char a) {
	return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ? 1 : 0;
}

void dfs(int vowel, int consonant, int index, int cnt) {
	if (cnt == l) {
		if (vowel >= 1 && consonant >= 2) {
			for (int i = 0; i < cnt; i++) {
				cout << result[i];
			}
			cout << endl;
		}
		return;
	}
	for (int i = index; i < ea; i++) {
		if (!check[i]) {
			check[i] = true;
			result[cnt] = word[i];
			if(match(word[i]))
				dfs(vowel+1, consonant, i, cnt + 1);
			else
				dfs(vowel, consonant+1, i, cnt + 1);
			check[i] = false;
		}
	}
}
void view() {
	for (int i = 0; i < word.size(); i++)
		cout << word[i];
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d\n", &l, &ea);
	char temp;
	for (int i = 0; i < ea; i++) {
		scanf("%c ", &temp);
		word.push_back(temp);
	}
	sort(word.begin(), word.end());
	dfs(0, 0, 0, 0);
}
