package 브루트포스;

import java.util.Scanner;

class Data_2961 {
	int sin;
	int sen;
	Data_2961(int sin, int sen) {
		this.sin=sin;
		this.sen=sen;
	}
}
public class _2961_도영이가_만든_맛있는_음식 {
	static final int MAX = 11;
	static int N;
	static int Cnt;
	static int Value = Integer.MAX_VALUE;
	
	static Data_2961 dish[] = new Data_2961[MAX];
	static int ary[] = new int[MAX];
	static boolean visit[] = new boolean[MAX];
	static void solve(int cnt) {
		if (Cnt==cnt) {
			int temp = sub();
			Value = Value < temp ? Value:temp;
			return;
		}
		for(int i=0;i<N;i++) {
			if (!visit[i]) {
				visit[i]=true;
				ary[cnt]=i;
				solve(cnt+1);
				visit[i]=false;
			}
		}
	}
	static int sub() {
		int sin_sum=1;
		int sen_sum=0;
		for(int i=0;i<Cnt;i++) {
			sin_sum*= dish[ary[i]].sin;
			sen_sum+= dish[ary[i]].sen;
		}
		return Math.abs(sin_sum-sen_sum);	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for(int i=0;i<N;i++)
			dish[i] = new Data_2961(sc.nextInt(), sc.nextInt());
		for(int i=1;i<=N;i++) {
			Cnt = i;
			solve(0);
		}
		System.out.println(Value);
	}
}
