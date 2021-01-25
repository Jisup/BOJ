package 다이나믹프로그래밍;

import java.util.Arrays;
import java.util.Scanner;

public class _2839_설탕배달 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int sugar = sc.nextInt();
		
		//sugar+1~2일때 런타임에러
		//sugar+3일때 정답처리
		//위 이유는 최소값 3 입력시, dp[5]를 받지 못하기때문
		int dp[] = new int [sugar+3];
		Arrays.fill(dp, 9999);
		
		dp[3]=1; dp[5]=1;
		for(int i=6;i<=sugar;i++)
			dp[i]=(Math.min(dp[i-3], dp[i-5])+1);
		
		if (dp[sugar] >= 9999)
			System.out.println(-1);
		else
			System.out.println(dp[sugar]);
		
		sc.close();
	}
}
