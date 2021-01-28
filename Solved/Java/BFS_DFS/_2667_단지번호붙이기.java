package BFS_DFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

class Coordinates{
	int y;
	int x;
	public Coordinates(int y, int x) {
		this.y=y;
		this.x=x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
}

public class _2667_단지번호붙이기 {
	
	static final int MAX = 30;
	static int N;
	
	static int ay[] = {0,0,-1,1};
	static int ax[] = {-1,1,0,0};
	
	static boolean map[][] = new boolean[MAX][MAX];
	static boolean visit[][] = new boolean[MAX][MAX];
	
	static ArrayList<Integer> result = new ArrayList<Integer>(MAX);
	
	static void init() throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		for(int t=0;t<N;t++) {
			String temp = br.readLine();
			for(int k=0;k<temp.length();k++) {
				char key = temp.charAt(k);
				map[t][k] = key == '0' ? false : true;
			}
		}
	}
	static void solve() {
		for(int y=0;y<N;y++)
			for(int x=0;x<N;x++) {
				if (map[y][x] && !visit[y][x]) {
					bfs(y, x);
				}
			}
	}
	static void bfs(int y, int x) {
		Queue<Coordinates> q = new LinkedList<Coordinates>();
		q.add(new Coordinates(y, x));
		visit[y][x] = true;
		
		int cnt=1;
		
		while(!q.isEmpty()) {
			Coordinates out = q.poll();
			for(int i=0;i<4;i++) {
				int ny = out.getY()+ay[i];
				int nx = out.getX()+ax[i];
				if (!range(ny, nx) && map[ny][nx]) {
					cnt++;
					visit[ny][nx] = true;
					q.add(new Coordinates(ny, nx));
				}
			}
		}
		
		result.add(cnt);
	}
	static boolean range(int y, int x) {
		return y<0||x<0||y>N-1||x>N-1||visit[y][x];
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		init();
		solve();
		
		System.out.println(result.size());
		Collections.sort(result);
		
		for(int item : result)
			System.out.println(item);
	}

}
