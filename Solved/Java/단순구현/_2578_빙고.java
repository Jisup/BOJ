package 단순구현;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class xy_2578 {
	int y;
	int x;
	xy_2578(int y, int x) {
		this.y=y;
		this.x=x;
	}
}
public class _2578_빙고 {
	static int result, cnt;
	static int H[] = new int[5];
	static int W[] = new int[5];
	static int left, right;
	static boolean L, R;
	static xy_2578 bingo[] = new xy_2578[26];
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static void init() throws IOException {
		for(int i=0;i<5;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0;j<5;j++) {
				int value = Integer.parseInt(st.nextToken());
				bingo[value] = new xy_2578(i, j);
			}
		}
	}
	static void solve() throws IOException {
		for(int i=0;i<5;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0;j<5;j++) {
				int value = Integer.parseInt(st.nextToken());
				int y = bingo[value].y;
				int x = bingo[value].x;
				H[y]++;
				if (H[y] == 5) result++;
				W[x]++;
				if (W[x] == 5) result++;
				if (!L && y==x) { 
					left++;
					if (left==5) {
						L=true;
						result++;
					}
				}
				if (!R && y == 4-x) {
					right++;
					if (right==5) {
						R=true;
						result++;
					}
				}
				cnt++;
				if (result >= 3) {
					System.out.println(cnt);
					return;
				}
			}
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		init();
		solve();
	}
}
