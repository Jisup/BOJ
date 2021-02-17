package BFS_DFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class xy_2234 {
	int y;
	int x;
	xy_2234(int y, int x){
		this.y=y;
		this.x=x;
	}
}
public class _2234_성곽 {
	static final int MAX = 51;
	static int W, H;
	static int ay[] = {0, -1, 0, 1};	//서 북 동 남
	static int ax[] = {-1, 0, 1, 0};
	static boolean map[][][] = new boolean[MAX][MAX][4];
	static boolean visit[][] = new boolean[MAX][MAX];
	static int zone[] = new int[MAX*MAX];
	static int castle[][] = new int[MAX][MAX]; 

	static Queue<xy_2234>q=new LinkedList<xy_2234>();
	static StringBuilder sb = new StringBuilder();
	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		for(int i=0;i<H;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<W;j++) {
				int value = Integer.parseInt(st.nextToken());
				for(int k=0;k<4;k++) {
					//오답의이유 2->1로바꿔서 고쳤었는데 롤백되서 안됐었음
					if (((1<<k) & value) != 0) 
						map[i][j][k] = true;
				}
			}
		}
		System.out.println(make());
		System.out.println(solve());
		System.out.println(break_wall());
	}
	static int make() {
		for(boolean item[] : visit)
			Arrays.fill(item, false);
		
		int room=0;
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++) {
				if (!visit[i][j]) {
					int cnt=0;
					q.add(new xy_2234(i, j));
					visit[i][j] = true;
					castle[i][j] = room;
					while(!q.isEmpty()) {
						xy_2234 item = q.poll();
						cnt++;
						for(int k=0;k<4;k++) {
							int ny = item.y+ay[k];
							int nx = item.x+ax[k];
							if (!range(ny, nx) && !visit[ny][nx] && !map[item.y][item.x][k]) {
								visit[ny][nx] = true;
								castle[ny][nx] = room;
								q.add(new xy_2234(ny, nx));
							}
						}
					}
//					System.out.println(room+" "+cnt);
//					view();
					zone[room++]=cnt;
				}
			}
		return room;
	}
	static int solve() {
		int value = 0;
		for(int item : zone)
			value = value > item ? value : item;
		return value;
	}
	static int break_wall() {
		/* 같은 존으로 만들어버리고, 그존에 그값들을 다넣습니다
		 * 방은 최대 50x50개까지 만들어질 수 있습니다
		 * 만들어진 방의 index에는 그방의 최대숫자를 넣습니다
		 * 벽을 허물었을때 같은존이라면 탐색하지않고, 같은존이아니라면 두 존을 더해서 리턴하는방식으로 갑시다
		 */
		int result = 0;
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++) {
				for(int k=0;k<4;k++) {
					int ny = i+ay[k];
					int nx = j+ax[k];
					//허물 수 있는 벽이있을때, 같은존인지 확인
					if (!range(ny, nx) && map[i][j][k]) {
						if (castle[i][j] != castle[ny][nx]) {
							int value = zone[castle[i][j]]+zone[castle[ny][nx]];
							result = result > value ? result : value;
						}
					}
				}
			}
		return result;
	}
	static boolean range(int y, int x) {
		return y<0||x<0||y>H-1||x>W-1;
	}
	static void view() {
		for(int i=0;i<H;i++) {
			for(int j=0;j<W;j++)
				System.out.print(visit[i][j] ? 1 : 0);
			System.out.println();
		}
		System.out.println();
	}
	public static void main(String[] args) throws IOException {
		init();
	}
}