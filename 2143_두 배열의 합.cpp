
#define _CRT_SECUORE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define INF 2147483647
#define ll long long
#define fs first
#define se second
#define MAX 1005

// List를 가지고 부분합을 구하는방법
// 순차적 모든합 1, 12, 123, 1234 // 1의경우 13, 14 (k=i+1을통해 연속된합 (12, 123) 을 배제하고 나머지를 추가합산)
// upper/lower개념 및 주 활용 방식
// (lower)~ 여러 중복 부분합~(upper) : upper-lower 은 전체값-1배열의 결과값에대한 중복된 값의 개수를 반환하는 식
// upper와 lower은 index를 반환하기때문에 저렇게됨
ll alen, blen, res, result;
ll A[MAX], B[MAX];


void partition(vector <ll> &v, ll temp[], int len) {
	ll sum = 0;
	for (int i = 0; i < len; i++) {
		sum = temp[i];
		v.push_back(sum);
		for (int j = i + 1; j < len; j++) {
			sum += temp[j];
			v.push_back(sum);
		}
	}
}
void solve() {
	vector <ll> Va;
	vector <ll> Vb;

	partition(Va, A, alen);
	partition(Vb, B, blen);

	sort(Va.begin(), Va.end());//
	sort(Vb.begin(), Vb.end());
	for (int i = 0; i < Va.size(); i++) {
		//-Vb.begin()  은 형변환을위해
		int low = lower_bound(Vb.begin(), Vb.end(), res - Va[i]) - Vb.begin();
		int high = upper_bound(Vb.begin(), Vb.end(), res - Va[i]) - Vb.begin();
		//cout << i << tap << "lower : " << low << tap << "upper : " << high << endl;
		result += high - low;
	}
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%lld", &res);
	scanf("%d", &alen);
	for (int i = 0; i < alen; i++)
		scanf("%lld", &A[i]);
	scanf("%d", &blen);
	for (int i = 0; i < blen; i++)
		scanf("%lld", &B[i]);
	solve();
	cout << result;
}
