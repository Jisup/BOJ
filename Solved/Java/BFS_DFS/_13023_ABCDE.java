package BFS_DFS;

import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;

class load {
	int index;
	int cnt;
}
public class _13023_ABCDE {

	static int friend;
	static int relation;
	static boolean visit[] = new boolean[2005];
	static Vector<Integer> v[] = new Vector[2005];
	
	static boolean result = false;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		friend = sc.nextInt();
		relation = sc.nextInt();
		
		init();
		
		for (int i = 0; i < relation; i++) {
			int fs = sc.nextInt();
			int se = sc.nextInt();
			v[fs].add(se);
			v[se].add(fs);
		}
		
		for(int i=0;i<friend;i++) {
			if (result) {
				System.out.println(1);
				return;
			}
			Arrays.fill(visit,false);
			visit[i]=true;
			solve(i, 0);
		}
		System.out.println(0);
		sc.close();
	}
	static void init() {
		for(int i=0;i<friend;i++)
			v[i] = new Vector<Integer>(2005);
	}
	
	static void solve(int index, int cnt) {
		if (result) return;
		if (cnt==4) {
			result=true;
			return;
		}
		for(Integer item : v[index]) {
			if (!visit[item]) {
				visit[item]=true;
				solve(item, cnt+1);
				visit[item]=false;
			}
		}
	}
	
}
