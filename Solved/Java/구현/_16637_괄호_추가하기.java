package 구현;

import java.util.LinkedList;
import java.util.Scanner;

public class _16637_괄호_추가하기 {
	static int N, ret = -Integer.MAX_VALUE;
	static char formula[] = new char[20];
	static boolean visit[] = new boolean[20];
	static void init() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		formula = sc.next().toCharArray();
	}
	static void solve(int index) {
		if (index >= N) {
			int result = calc();
			 ret = ret > result ? ret : result;
			 return;
		}
		for(int i=index;i<  N;i+=2) {
			if (i+2<N) {
				if (!visit[i] && !visit[i+2]) {
					visit[i]=true;
					visit[i+2]=true;
					solve(index+2);
					visit[i]=false;
					visit[i+2]=false;
				}
			}
			else
				solve(i+1);
		}
	}
	static int calc() {
		LinkedList<Character>oper = new LinkedList<>();
		LinkedList<Integer>num = new LinkedList<>();
		for(int i=0;i<N;) {
			if(!visit[i]) {
				if ('0'<=formula[i] && formula[i] <='9')
					num.add(formula[i]-'0');
				else
					oper.add(formula[i]);
				i++;
			}
			else {
				int fs = formula[i]-'0';
				int se = formula[i+2]-'0';
				int temp = 0;
				switch(formula[i+1]) {
				case '*':
					temp = fs*se;
					break;
				case '-':
					temp = fs-se;
					break;
				case '+':
					temp = fs+se;
					break;
				}
				num.add(temp);
				i+=3;
			}
		}
		int total = num.get(0);
		int index = 0;
		for(int i=1;i<num.size();i++) {
			switch(oper.get(index++)) {
			case '*':
				total=total*(num.get(i));
				break;
			case '-':
				total=total-(num.get(i));
				break;
			case '+':
				total=total+(num.get(i));
				break;
			}
		}
		return total;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		init();
		solve(0);
		System.out.println(ret);
	}

}
