package 브루트포스;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Data {
	int value;
	int cnt;
	Data(int value, int cnt) {
		this.value=value;
		this.cnt=cnt;
	}
}
public class _1107_리모컨 {
	static int Channel, N, result;
	
	static boolean Control[] = new boolean[10];
	static boolean visit[] = new boolean[500001];
	
	static void init() {
		Scanner sc = new Scanner(System.in);
		Channel = sc.nextInt();
		result = Math.abs(Channel-100);
		
		N = sc.nextInt();
		for(int i=0;i<N;i++)
			Control[sc.nextInt()]=true;
		solve();
		System.out.println(result);
	}
	static void solve() {
		Queue<Data>q=new LinkedList<>();
		for(int i=0;i<10;i++)
			if(!Control[i]) q.add(new Data(i, 1));
		
		while(!q.isEmpty()) {
			Data out = q.poll();
			result = Math.min(result, out.cnt+Math.abs(Channel-out.value));
			for(int i=0;i<10;i++)
				if(!Control[i] && 
						out.value !=0 && out.value*10+i < Channel*2)
					q.add(new Data(out.value*10+i, out.cnt+1));
		}
	}
	public static void main(String[] args) {
		init();
	}
}
