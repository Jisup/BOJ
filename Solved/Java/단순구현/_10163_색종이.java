package 단순구현;

import java.util.ArrayList;
import java.util.Scanner;

class Data_10163 {
	int h;
	int w;
	int hl;
	int wl;
	Data_10163(int h, int w, int hl, int wl) {
		this.h=h;
		this.w=w;
		this.hl=hl;
		this.wl=wl;
	}
}
public class _10163_색종이 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int answer[];
		boolean visit[][] = new boolean[105][105];
		ArrayList<Data_10163>ary = new ArrayList<>();
		int N = sc.nextInt();
		answer = new int[N];
		int h,w,hl,wl;
		for(int t=0;t<N;t++) {
			h = sc.nextInt();
			w = sc.nextInt();
			hl = sc.nextInt();
			wl = sc.nextInt();
			ary.add(new Data_10163(h, w, hl, wl));
		}
		for(int k = ary.size()-1;k>=0;k--) {
			int cnt=0;
			Data_10163 item = ary.get(k);
			for(int i=item.h;i<item.h+item.hl;i++)
				for(int j=item.w;j<item.w+item.wl;j++) {
					if (!visit[i][j]) {
						cnt++;
						visit[i][j] = true;
					}
				}
			answer[k]=cnt;
		}
		for(int item : answer)
			System.out.println(item);
	}
}
