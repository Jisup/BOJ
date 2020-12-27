#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define MAX 1000001

typedef struct data {
	int fs;
	int se;
	int sub;
}Data;

int num;
int prime_index[MAX];
bool check[MAX];
Data res;
vector <int> prime;

void eratostenes() {
	int cnt = 0;
	for (int i = 2; i < MAX; i++) {
		if (!check[i]) {
			check[i] = true;
			prime_index[i] = cnt++;
			prime.push_back(i);
		}
		for (int j = i + i; j < MAX; j+=i)
			if (!check[j]) check[j] = true;
	}
}

void solve() {
	int left = 0, right = 0, cnt = num;
	while (true) {
		right = prime_index[cnt--];
		if (right !=0)
			break;
	}
	//중복된 소수를 사용하여 나타낼 수도 있었음, 이부분을 배제시키고 생각하여 틀림
	while (left <= right) {
		int result = prime[left] + prime[right];
		if (result > num) {
			right--;
		}
		else {
			if (result == num) {
				int temp = prime[right] - prime[left];
				if (temp > res.sub) {
					res = { prime[left], prime[right], temp };
					break;
				}
			}
			left++;
		}
	}
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	eratostenes();
	while (true) {
		cin >> num;
		if (!num)break;
		res = { 0,0,-1 };

		solve();
		if (res.se != -1)
			printf("%d = %d + %d\n", num, res.fs, res.se);
		else
			cout << "Goldbach`s conjecture is wrong." << endl;
	}
}