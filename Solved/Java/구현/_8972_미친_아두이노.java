package 구현;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


class xy {
	int y;
	int x;
	xy(int y, int x) {
		this.y=y;
		this.x=x;
	}
}
public class _8972_미친_아두이노 {
	static final int MAX = 101;
	static int H, W;
	
	static int ay[] = {1,1,1,0,0,0,-1,-1,-1};
	static int ax[] = {-1,0,1,-1,0,1,-1,0,1};
	
	static char map[][] = new char[MAX][MAX];
	static int visit[][] = new int[MAX][MAX];
	
	static xy jongsu;
	static int move[];
	static ArrayList<xy>ci = new ArrayList<>();
	
	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		H = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		for(int i=0;i<H;i++) {
			map[i] = br.readLine().toCharArray();
			for(int j=0;j<W;j++) {
				if (map[i][j] == 'I') jongsu = new xy(i, j);
				else if (map[i][j] == 'R') ci.add(new xy(i, j));
			}
		}
		String moving = br.readLine();
		move = new int[moving.length()];
		for(int i=0;i<moving.length();i++)
			move[i] = Integer.parseInt(moving.charAt(i)+"");
	}
	static boolean solve() {
		for(int i=0;i<move.length;i++) {
			int mv = move[i]-1;
			if (mv!=4) {
				int y = jongsu.y+ay[mv];
				int x = jongsu.x+ax[mv];
				if (map[y][x] == 'R') {
					System.out.println("kraj "+(i+1));
					return false;
				}
				map[jongsu.y][jongsu.x] = '.';
				map[y][x] = 'I';
				jongsu.y=y;
				jongsu.x=x;
			}
			if(!bomb()) {
				System.out.println("kraj "+(i+1));
				return false;
			}
			view();
		}
		return true;
	}
	static boolean bomb() {
		for(int item[] :visit)
			Arrays.fill(item, 0);
		//다 움직여주고
		for(int c=0;c<ci.size();c++) {
			int index=0, less=Integer.MAX_VALUE;
			int y = ci.get(c).y;
			int x = ci.get(c).x;
			for(int i=0;i<9;i++) {
				int ny = y+ay[i];
				int nx = x+ax[i];
				if (range(ny, nx)) continue;
				int value = distinct(jongsu.y, jongsu.x, ny, nx);
				if (less > value) {
					less = value;
					index = i;
				}
			}
			int ny = y+ay[index];
			int nx = x+ax[index];
			if (map[ny][nx] == 'I') return false;
			map[y][x] = '.';
			visit[ny][nx]++;
			ci.get(c).y = ny;
			ci.get(c).x = nx;
		}
		//터질거 확인후 삭제, 단 뒤에서부터 검색후 삭제
		for(int c=ci.size()-1;c>=0;c--) {
			int y = ci.get(c).y;
			int x = ci.get(c).x;
			//움직임이 진행될 때 바꿔서 맵상에서 아두이노가 사라진모습이 나옴
			map[y][x] = 'R';
			if (visit[y][x] != 1) {
				map[y][x] = '.';
				ci.remove(c);
			}
		}
		return true;
	}
	static int distinct(int fy, int fx, int sy, int sx) {
		//f : 종수, s : 미친아두이노
		return Math.abs(fy-sy)+Math.abs(fx-sx);
	}
	static boolean range(int y, int x) {
		return y<0||x<0||y>H-1||x>W-1;
	}
	static void view() {
		for(int i=0;i<H;i++) {
			for(int j=0;j<W;j++)
				System.out.print(map[i][j]);
			System.out.println();
		}
		System.out.println();
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		init();
		if(solve()) {
			view();
		}
	}
}
