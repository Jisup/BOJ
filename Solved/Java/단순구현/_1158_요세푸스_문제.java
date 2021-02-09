package 단순구현;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class _1158_요세푸스_문제 {
	static Queue<Integer>q=new LinkedList<Integer>();
	static void init() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		
		for(int i=1;i<=N;i++)
			q.add(i);
		System.out.print("<");
		solve(N, K);
		System.out.print(">");
	}
	static void solve(int N, int K) {
		for(int i=0;i<N;i++) {
			for(int k=0;k<K-1;k++)
				q.add(q.poll());
			System.out.print(q.poll());
			if (i!=N-1) System.out.print(", ");
		}
	}
	public static void main(String[] args) {
		init();
	}
}
