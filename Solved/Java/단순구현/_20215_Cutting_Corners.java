package 단순구현;

import java.util.Scanner;

public class _20215_Cutting_Corners {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int w = sc.nextInt();
		int h = sc.nextInt();
		
		double square = w+h;
		double diagonal = Math.sqrt(w*w+h*h);
		if ((square-diagonal)%1 == 0)
			System.out.println((int)(square-diagonal));
		else 
			System.out.printf("%.9f", square-diagonal);
	}
}
