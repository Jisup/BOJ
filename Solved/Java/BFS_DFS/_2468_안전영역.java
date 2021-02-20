package BFS_DFS;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class xy_2468{
	int y;
	int x;
	xy_2468(int y, int x) {
		this.y=y;
		this.x=x;
	}
}
public class _2468_안전영역 {
	static final int MAX = 105;
	static int N;
	static int ay[] = {-1,1,0,0};
	static int ax[] = {0,0,-1,1};
	static int map[][] = new int[MAX][MAX];
	static boolean visit[][] = new boolean[MAX][MAX];
	static void init() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				map[i][j] = sc.nextInt();
		int result=0;
		for(int i=0;i<=100;i++) {
			int value = rain(i);
			result = result > value ? result : value;
		}
		System.out.println(result);
	}
	static int rain(int water) {
		for(boolean item[] : visit)
			Arrays.fill(item, false);
		
		Queue<xy_2468>q=new LinkedList<>();
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++) {
				if (map[i][j] <=water) {
					q.add(new xy_2468(i, j));
					visit[i][j] = true;
					while(!q.isEmpty()) {
						xy_2468 out = q.poll();
						for(int k=0;k<4;k++) {
							int ny = out.y+ay[k];
							int nx = out.x+ax[k];
							if (!range(ny, nx) && map[ny][nx] <= water) {
								visit[ny][nx] = true;
								q.add(new xy_2468(ny, nx));
							}
						}
					}
				}
			}
		return solve();
	}
	static int solve() {
		int cnt=0;
		Queue<xy_2468>q=new LinkedList<>();
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++) {
				if (!visit[i][j]) {
					visit[i][j] = true;
					q.add(new xy_2468(i,j));
					cnt++;
					while(!q.isEmpty()) {
						xy_2468 out = q.poll();
						for(int k=0;k<4;k++) {
							int ny = out.y+ay[k];
							int nx = out.x+ax[k];
							if (!range(ny, nx)) {
								visit[ny][nx] = true;
								q.add(new xy_2468(ny, nx));
							}
						}
					}
				}
			}
		return cnt;
	}
	static boolean range(int y, int x) {
		return y<0||x<0||y>N-1||x>N-1||visit[y][x];
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		init();
	}
}
