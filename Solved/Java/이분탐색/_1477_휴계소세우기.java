package 이분탐색;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class _1477_휴계소세우기 {
	static int N, M, L;
	static ArrayList<Integer>rest = new ArrayList<>();
	static void init() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		L = sc.nextInt();
		rest.add(0);
		rest.add(L);
		for(int i=0;i<N;i++)
			rest.add(sc.nextInt());
		Collections.sort(rest);
		solve();
	}
	static void solve() {
		int res=0;
		int left=0, right=L;
		while(left<=right) {
			int mid = (left+right)/2;
			int result = build(mid);
			if (result <= M) {
				res=mid;
				right = mid-1;
			}
			else {
				left = mid+1;
			}
		}
		System.out.println(res);
	}
	static int build(int mid) {
		int cnt=0;
//		System.out.println(mid);
		for(int i=0;i<rest.size()-1;i++) {
			int value = rest.get(i+1)-rest.get(i);
			if (value%mid == 0)
				cnt+=value/mid -1;
			else
				cnt+=value/mid;
		}
//		System.out.println(mid+" "+cnt);
		return cnt;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		init();
	}
}