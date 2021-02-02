package 소수;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Pair {
	int value;
	int cnt;

	Pair(int value, int cnt) {
		this.value = value;
		this.cnt = cnt;
	}

	public int getValue() {
		return value;
	}

	public void setValue(int value) {
		this.value = value;
	}

	public int getCnt() {
		return cnt;
	}

	public void setCnt(int cnt) {
		this.cnt = cnt;
	}
}

public class _17394_핑거스냅 {

	static boolean check[];

	static void init() {
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		for (int t = 1; t <= TC; t++) {
			int index = sc.nextInt();
			int fs = sc.nextInt();
			int se = sc.nextInt();
			
			if (!result(fs, se))
				System.out.println(-1);
			else if (range(index, fs, se))
				System.out.println(0);
			else
				System.out.println(solve(index, fs, se));
		}
	}

	static boolean result(int fs, int se) {
		for (int i = fs; i <= se; i++) {
			if (!check[i])
				return true;
		}
		return false;
	}

	static int solve(int index, int fs, int se) {
		boolean visit[] = new boolean[3000001];
//		boolean visit[] = new boolean[index*3+1];
//		위와같이 할당하였을때 런타임에러뜸 -> 왤까?
		Arrays.fill(visit, false);
		
		Queue<Pair>q=new LinkedList<Pair>();
		q.add(new Pair(index, 0));
		visit[index]=true;
		while(!q.isEmpty()) {
			Pair out = q.poll();
			if (range(out.getValue(), fs, se))	
				return out.getCnt();
			
			for(int i=0;i<4;i++) {
				int nv = out.getValue();
				int nc = out.getCnt()+1; 
				switch(i) {
				case 0:
					nv/=2;
					break;
				case 1:
					nv/=3;
					break;
				case 2:
					nv+=1;
					break;
				case 3:
					nv-=1;
					break;
				}
				if (nv <= 0 || visit[nv]) continue;
				visit[nv] = true;
				q.add(new Pair(nv, nc));
			}
		}
		return -1;
	}

	static boolean range(int value, int fs, int se) {
		return value >= fs && value <= se && !check[value];
	}
	
	static void eratostenes(int N) {
		check = new boolean[N];
		check[0] = true;
		check[1] = true;
		for (int i = 2; i < N; i++)
			for (int j = i + i; j < N; j += i)
				if (!check[j]) {
					check[j] = true;
				}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		eratostenes(100001);
		init();
	}

}
