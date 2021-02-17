package BFS_DFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class xy_4963 {
	int y;
	int x;
	xy_4963(int y, int x) {
		this.y=y;
		this.x=x;
	}
}
public class _4963_섬의개수 {
	static final int MAX = 51;
	static int H, W;
	static int ay[] = {-1,1,0,0,-1,-1,1,1};
	static int ax[] = {0,0,-1,1,-1,1,1,-1};
	static int map[][] = new int[MAX][MAX];
	static boolean visit[][] = new boolean[MAX][MAX];
	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			if (W==0 && H==0)
				return;
			for(int i=0;i<H;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<W;j++)
					map[i][j] = Integer.parseInt(st.nextToken());
			}
			System.out.println(solve());
		}
	}
	static int solve() {
		for(boolean[] item : visit)
			Arrays.fill(item, false);
		
		int island=0;
		Queue<xy_4963>q=new LinkedList<>();
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					island++;
					visit[i][j] = true;
					q.add(new xy_4963(i, j));
					while(!q.isEmpty()) {
						xy_4963 item = q.poll();
						for(int k=0;k<8;k++) {
							int ny = item.y+ay[k];
							int nx = item.x+ax[k];
							if (!range(ny, nx)) {
								visit[ny][nx] = true;
								q.add(new xy_4963(ny, nx));
							}
						}
					}
				}
			}
		return island;
		
	}
	static boolean range(int y, int x) {
		return y<0||x<0||y>H-1||x>W-1||map[y][x] == 0||visit[y][x];
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		init();
	}
}