#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0

map <string, int> m;
vector <string> v;
vector <string> out;
set <string> s;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc-- > 0) {
		string name, type;
		cin >> name >> type;
		if (s.find(name) == s.end()) {
			s.insert(name);
			v.push_back(name);
		}
		if (type == "enter")
			m[name]++;
		else
			m[name]--;
	}
	for (string it : v) {
		if (m[it]) out.push_back(it);
	}
	sort(out.begin(), out.end(), greater<string>());
	for (string it : out)
		cout << it << endl;
}
