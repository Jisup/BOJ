package 단순구현;

import java.util.Scanner;

public class _2491_수열 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int high = 0, low = 0;
		int up = 1, down = 1;
		int item = sc.nextInt();
		for (int i = 1; i < N; i++) {
			int value = sc.nextInt();
			if (item <= value)
				up++;
			else {
				high = Math.max(high, up);
				up = 1;
			}
			if (item >= value)
				down++;
			else {
				low = Math.max(low, down);
				down = 1;
			}
			item = value;
		}
		high = Math.max(high, up);
		low = Math.max(low, down);
		System.out.println(Math.max(high, low));
	}
}
