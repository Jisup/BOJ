
#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0
#define INF 2147483647
//중간값을 찾기위한 방법중 하나
//두개의 큐에 index가 1개씩들어올때 아래조건에맞춰 큐에삽입
//이후 큐의 top을 비교하여 작은값이 중간값이됨
//위를위해 1개의 top은 최대값을 가지는 오름차순
//다른 1개의 top은 최소값을 가지는 내림차순으로 구현해야함


priority_queue<int, vector<int>, less<int> > q_max;
priority_queue<int, vector<int>, greater<int> > q_min;
//priority_queue <int, vector<int>, less<int> > q_max;
//priority_queue <int, vector<int>, greater<int> > q_min;
int total, input;
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> total;
	for (int i = 0; i < total; i++) {
		cin >> input;		
		//최대힙 size = 최소힙 size or +1
		//최소힙 top >= 최대힙 top
		if (q_max.size() > q_min.size()) 
			q_min.push(input);
		else
			q_max.push(input);
		if (!q_max.empty() && !q_min.empty()) {
			if (q_max.top() > q_min.top()) {
				int high = q_max.top();
				int low = q_min.top();
				q_max.pop();
				q_min.pop();
				q_max.push(low);
				q_min.push(high);
			}
		}
		cout << q_max.top() << endl;
	}
}