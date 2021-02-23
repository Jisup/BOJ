package BFS_DFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class _17070_파이프옮기기 {
	static final int MAX = 20;
	static int N, pipe;
	static int map[][] = new int[MAX][MAX];
	static int visit[][][] = new int[MAX][MAX][3];
	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++)
				map[i][j] = Integer.parseInt(st.nextToken());
		}
	}
	static void solve() {
		//가로0 대각선1 세로2
		visit[0][1][0] = 1;
		for(int i=0;i<N;i++)
			for(int j=2;j<N;j++) {
				//벽이있으면 그냥 넘어가요
				if (map[i][j] == 1) continue;
				//가로로가는거면
				//내 가로의 전칸에서 가로와 대각선으로 올 수 있는 경우를 더해줘요
				visit[i][j][0] = visit[i][j-1][0]+visit[i][j-1][1];
				//첫번째줄 가로르제외하고 첫번째 세로줄은 탐색하지 않기로해요
				if (i==0) continue;
				//세로로가는거면
				//내 세로의 전칸에서 세로와 가로로 올수 있는 경우를 더해줘요
				visit[i][j][2] = visit[i-1][j][1]+visit[i-1][j][2];
				//대각선으로가는거면, 내왼쪽과 위를 확인해요
				if (map[i-1][j] == 1 || map[i][j-1] == 1) continue;
				//내 대각선의 전칸에서, 가로와 세로 그리고 대각선으로 올 수 있는 경우를 더해줘요
				visit[i][j][1] = visit[i-1][j-1][0]+visit[i-1][j-1][1]+visit[i-1][j-1][2];
			}
		view();
	}
	static void view() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++)
				System.out.print((visit[i][j][0]+visit[i][j][1]+visit[i][j][2])+" ");
			System.out.println();
		}
		System.out.println();
	}
	public static void main(String[] args) throws IOException {
		init();
		solve();
		for(int i=0;i<3;i++) pipe+=visit[N-1][N-1][i];
		System.out.println(pipe);
	}
}
//class xy_17070 {
//	int y;
//	int x;
//	int type;
//	xy_17070(int y, int x, int type) {
//		this.y=y;
//		this.x=x;
//		this.type=type;
//	}
//}
//public class _17070_파이프옮기기 {
//	static final int MAX = 20;
//	static int N, pipe;
//	static int ay[] = {0, 1, 1};
//	static int ax[] = {1, 0, 1};
//	static int map[][] = new int[MAX][MAX];
//	static int visit[][] = new int[MAX][MAX];
//	static void init() throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringTokenizer st = new StringTokenizer(br.readLine());
//		N = Integer.parseInt(st.nextToken());
//		for(int i=0;i<N;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<N;j++)
//				map[i][j] = Integer.parseInt(st.nextToken());
//		}
//	}
//	static void solve() {
//		Queue<xy_17070>q=new LinkedList<>();
//		q.add(new xy_17070(0, 1, 0));
//		while(!q.isEmpty()) {
//			xy_17070 out = q.poll();
//			if (out.y==N-1 && out.x==N-1) {
//				pipe++;
//				continue;
//			}
//			int dy = out.y+ay[2];
//			int dx = out.x+ax[2];
//			if (!range(dy, dx))
//				if (map[dy][out.x] == 0 && map[out.y][dx] == 0) 
//					q.add(new xy_17070(dy, dx, 2));
//			
//			if (out.type == 2) {
//				for(int i=0;i<2;i++) {
//					int ny = out.y+ay[i];
//					int nx = out.x+ax[i];
//					if (!range(ny, nx))
//						q.add(new xy_17070(ny, nx, i));
//				}
//				
//			}
//			else {
//				int ny = out.y+ay[out.type];
//				int nx = out.x+ax[out.type];
//				if (!range(ny, nx))
//					q.add(new xy_17070(ny, nx, out.type));
//			}
//		}
//	}	
//	static boolean range(int y, int x) {
//		return y>N-1||x>N-1||map[y][x]==1;
//	}
//	public static void main(String[] args) throws IOException {
//		init();
//		solve();
//		System.out.println(pipe);
//	}
//}
