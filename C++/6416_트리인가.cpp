
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"

set <int> s;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, cnt=0, tc = 1;
	while (true) {		
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		if (a == 0 && b == 0) {
			if (s.size() == cnt + 1 || cnt == 0)
			//if (s.size() != cnt || s.size()==0)
				cout << "Case " << tc << " is a tree." << endl;
			else
				cout << "Case " << tc << " is not a tree." << endl; 
			s = set<int>();
			cnt=0, tc++;
			continue;
		}
		//s를 노드로 칭하고, cnt를 라인노드라칭할때
		//노드의수 = 라인의수+1
		s.insert(a);
		s.insert(b);
		cnt++;
	}
}