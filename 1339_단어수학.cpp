
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define fs first
#define se second
#define MAX 11

int temp;
char tmp[MAX];
int alpha[27];
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &temp);
	for (int i = 0; i < temp; i++) {
		scanf("%s", &tmp);
		for (int k = 0; k < strlen(tmp); k++) {
			alpha[tmp[k] - 'A'] += pow(10, strlen(tmp) - 1 - k);
			//cout << tmp[k] << "ดย" << alpha[tmp[k] - 'A'] << endl;
		}
	}
	sort(alpha, alpha + 27, [](const int &a, const int &b) {return a > b; });
	//for (int i = 0; i < 27; i++) cout << alpha[i] << " ";
	//cout << endl;
	int num = 10, result = 0;
	for (int i = 0; i < MAX; i++) {
		result += --num*alpha[i];
	}
	cout << result;
}