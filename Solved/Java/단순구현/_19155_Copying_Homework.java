package 단순구현;

import java.util.Scanner;

public class _19155_Copying_Homework {
	static int N;

	static void init() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		int ary[] = new int[N+1];
		for (int i = 0; i < N; i++) {
			ary[i+1] = N-i;
		}
		for(int i=0;i<N;i++) {
			int temp = sc.nextInt();
			System.out.print(ary[temp]+" ");
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		init();
	}
}
