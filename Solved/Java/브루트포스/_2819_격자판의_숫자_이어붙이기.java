package 브루트포스;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class _2819_격자판의_숫자_이어붙이기 {
	static int ay[] = {-1,1,0,0};
	static int ax[] = {0,0,-1,1};
	static int map[][] = new int[4][4];
	static boolean visit[][] = new boolean[4][4];
	
	static HashSet<String>hs = new HashSet<String>();
	static void init() {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for(int t=1;t<=tc;t++) {
			hs.clear();
			for(boolean item[] : visit)
				Arrays.fill(item, false);
			
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
					map[i][j] = sc.nextInt();
			solve();
			System.out.println("#"+t+" "+hs.size());
		}
	}
	static void solve() {
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++) {
				visit[i][j] = true;
				dfs(i,j,1,map[i][j]+"");
			}
	}
	static void dfs(int y, int x, int cnt, String value) {
		if (cnt == 7) {
			hs.add(value);
			return;
		}
		for(int i=0;i<4;i++) {
			int ny = y+ay[i];
			int nx = x+ax[i];
			if(range(ny, nx)) continue;
			if(!visit[ny][nx]) {
				visit[ny][nx]=true;
				dfs(ny, nx, cnt+1, value+map[ny][nx]);
				visit[ny][nx]=false;
			}
		}
	}
	static boolean range(int y, int x) {
		return y<0||x<0||y>3||x>3;
	}
	public static void main(String[] args) {
		init();
	}
}
