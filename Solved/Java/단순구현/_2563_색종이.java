package 단순구현;

import java.util.Scanner;

public class _2563_색종이 {
	static boolean paper[][] = new boolean[101][101];
	static void init() {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for(int t=1;t<=tc;t++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			solve(y, x);
		}
		result();
	}
	static void solve(int y, int x) {
		for(int i=y;i<y+10;i++)
			for(int j=x;j<x+10;j++)
				paper[i][j] = true;
	}
	static void result() {
		int ret = 0;
		for(int i=0;i<101;i++)
			for(int j=0;j<101;j++)
				if (paper[i][j]) ret++;
		System.out.println(ret);
	}
	public static void main(String[] args) {
		init();
	}
}