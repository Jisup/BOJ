package 단순구현;

import java.util.Scanner;

public class _2564_경비원 {
	 public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);
	        int C = sc.nextInt();
	        int R = sc.nextInt(); 
	        int around = (C+R) * 2;
	        int N = sc.nextInt();
	        int[] dist = new int[N + 1];
	        for(int i = 0; i < N+1; i++) {
	            int dir = sc.nextInt();
	            int value = sc.nextInt();
	            switch (dir) {
	            case 1:
	                dist[i] = value;
	                break;
	            case 2:
	                dist[i] = C+R+C-value;
	                break;
	            case 3:
	                dist[i] = around - value;
	                break;
	            case 4:
	                dist[i] = C + value;
	                break;
	            }
	        }
	        int myDist = dist[N];
	        int ans = 0;
	        for(int i = 0; i < N; i++) {
	            int result = Math.abs(myDist - dist[i]);
	            ans += Math.min(result ,  around - result);
	        }
	        System.out.println(ans);
	    }
}
