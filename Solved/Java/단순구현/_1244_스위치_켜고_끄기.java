package 단순구현;

import java.util.Scanner;

public class _1244_스위치_켜고_끄기 {
	static final int MAX = 105;
	
	static int sw;
	static int Switch[] = new int[MAX];
	
	static void init() {
		Scanner sc= new Scanner(System.in);
		sw = sc.nextInt();
		for(int i=1;i<=sw;i++)
			Switch[i] = sc.nextInt();
		
		int tc = sc.nextInt();
		for(int i=0;i<tc;i++) {
			int type=sc.nextInt();
			int index = sc.nextInt();
			solve(type, index);
		}
	}
	static void solve(int type, int index) {
		if (type==1) {
			for(int i=1;i*index<=sw;i++)
				Switch[i*index] = Switch[i*index] == 1 ? 0 : 1;
		}
		else {
			Switch[index] = Switch[index] == 1 ? 0 : 1;
			for(int i=1;i<=Math.min(Math.abs(index-1), Math.abs(index-sw));i++) {
				if (Switch[index-i] == Switch[index+i]) {
					Switch[index-i] = Switch[index-i] == 1 ? 0 : 1;
					Switch[index+i] = Switch[index+i] == 1 ? 0 : 1;
				}
				else
					break;
			}
		}
	}
	static void view() {
		for(int i=1;i<=sw;i++) {
			System.out.print(Switch[i]+" ");
			if (i%20==0) System.out.println();
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		init();
		view();
	}
}
