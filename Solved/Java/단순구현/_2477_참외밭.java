package 단순구현;

import java.util.Scanner;

public class _2477_참외밭 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * 육각형 직사각형에서, 면체의 넓이는
		 * 모든 인접한 변을 곱한값 = 사각형 직사각형의너비*3 + 지워진 직사각형의너비*2 이다.
		 */
		Scanner sc = new Scanner(System.in);
//	    // 한 변을 기준으로 앞 뒤 변의 길이의 합이 길이와 같다면 파인 지점
		int N = sc.nextInt();
		int H=0, W=0;
		int h=0, w=0;
		int ary[] = new int[6];
		for(int i=0;i<6;i++) {
			sc.nextInt();
			ary[i] = sc.nextInt();
		}
		for(int i=0;i<6;i++) {
			if (i%2==0) 
				W = W > ary[i] ? W : ary[i];
			else
				H = H > ary[i] ? H : ary[i];
		}
		for(int i=0;i<6;i++) {
			if (i%2==0) { 
				if (H == ary[(i+5)%6] + ary[(i+1)%6])
					w = ary[i];
			}
			else {
				if (W == ary[(i+5)%6] + ary[(i+1)%6])
					h = ary[i];
			}
		}
		System.out.println(N*(H*W-h*w));
	}
}
