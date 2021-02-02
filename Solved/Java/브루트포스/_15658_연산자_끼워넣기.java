package 브루트포스;

import java.util.Scanner;

public class _15658_연산자_끼워넣기 {
	static int len;
	static int ary[];
	
	static long high = -9876543210L;
	static long low = 9876543210L;
	
	static void init() {
		Scanner sc = new Scanner(System.in);
		len = sc.nextInt();
		ary = new int[len];
		for(int i=0;i<len;i++) 
			ary[i] = sc.nextInt();
		solve(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt(), 1, ary[0]);
	}
	static void solve(int plus, int sub, int mult, int div, int cnt, long value) {
		if (cnt == len) {
			high = high > value ? high : value;
			low = low < value ? low : value;
			return;
		}
		if (plus>0)
			solve(plus-1,sub, mult, div, cnt+1, value+ary[cnt]);
		if (sub>0)
			solve(plus,sub-1, mult, div, cnt+1, value-ary[cnt]);
		if (mult>0)
			solve(plus,sub, mult-1, div, cnt+1, value*ary[cnt]);
		if (div>0)
			solve(plus,sub, mult, div-1, cnt+1, value/ary[cnt]);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		init();
		System.out.println(high);
		System.out.println(low);
	}

}
