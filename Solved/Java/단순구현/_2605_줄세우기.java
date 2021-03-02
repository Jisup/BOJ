package 단순구현;

import java.util.ArrayList;
import java.util.Scanner;

public class _2605_줄세우기 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		ArrayList<Integer>ary=new ArrayList<>();
		for(int i=0;i<N;i++) {
			int value = sc.nextInt();
			ary.add(ary.size()-value, i+1);
		}
		for(int item : ary)
			System.out.print(item+" ");
	}
}
