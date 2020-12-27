
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define ll long long
#define MAX 300001

int total, have;
vector <pair<int, int> > jewelry;
vector <int> bag;
bool check[MAX];
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	cin >> total >> have;

	int a, b;
	for (int i = 0; i < total; i++) {
		cin >> a >> b;
		jewelry.push_back({ a, b });
	}
	//, [](pair<int, int> a, pair<int, int>b) {return a.second > b.second; }
	sort(jewelry.begin(), jewelry.end());
	for (int i = 0; i < have; i++) {
		cin >> a;
		bag.push_back(a);
	}
	sort(bag.begin(), bag.end(), less<int>());
	//크기순으로 나열해놓고, 크기에적합하다면 더하고 continue
	//pick and pic 이 아니고 All_pick and pic
	//한개씩 골라가면서 진행하는것이 아니고
	//전체를 넣고, 하나를 골라챙기기
	ll result = 0;
	int cnt = 0;
	priority_queue<int>q;
	for (int item : bag) {
		//cout << item << endl;
		//큐에 가능한 보든부분을 쌓아두고, 가방의 최대치가 허용할 수 있는
		//보석의 무게부터 시작해서~
		while (cnt < total && jewelry[cnt].first <= item) {
			//cout << "idx : " << cnt << tap << "value : " << jewelry[cnt].second << endl;
			q.push(jewelry[cnt++].second);
		}
		//이해가안되는문제
		//가방의무게를 6과 1로 설정하고
		//보석을 2 5 4로 해놓았을경우 답은 99가되어야마땅한데
		//이런 경우가 주어지지 않는가봄

		//위에 생각한것이 가방의 순서를 제일 낮은 가방부터
		//모든 경우를 삽입할때, 배제된다는것을 파악함

		//보석도 제일낮은 보석으로 시작하여야 cnt, index가 맞음
		if (!q.empty()) {
			//cout << q.top() << endl;
			result += q.top();
			q.pop();
		}
	}
	cout << result;
}
