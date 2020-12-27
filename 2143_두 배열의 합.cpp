
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

// List�� ������ �κ����� ���ϴ¹��
// ������ ����� 1, 12, 123, 1234 // 1�ǰ�� 13, 14 (k=i+1������ ���ӵ��� (12, 123) �� �����ϰ� �������� �߰��ջ�)
// upper/lower���� �� �� Ȱ�� ���
// (lower)~ ���� �ߺ� �κ���~(upper) : upper-lower �� ��ü��-1�迭�� ����������� �ߺ��� ���� ������ ��ȯ�ϴ� ��
// upper�� lower�� index�� ��ȯ�ϱ⶧���� �����Ե�
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
		//-Vb.begin()  �� ����ȯ������
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
