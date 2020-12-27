
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int scale, yscale;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string res = "";
	for (int i = 0; i < 8; i++) {
		scanf("%d", &scale);
		if (i == 0) {
			yscale = scale;
			if (scale == 1) res = "ascending";
			else if (scale == 8) res = "descending";
			else {
				res = "mixed";
				break;
			}
			continue;
		}
		if (res == "ascending" && yscale + 1 != scale) {
			res = "mixed";
			break;
		}
		else if (res == "descending"&& yscale - 1 != scale) {
			res = "mixed";
			break;
		}
		yscale = scale;
	}
	for(int i=0;i<res.length();i++)
		printf("%c", res[i]);
}
