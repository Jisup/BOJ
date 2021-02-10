package 단순구현;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class _16926_배열돌리기_1 {
	static int N, M, R;
	static int ary[][];

	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		ary = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++)
				ary[i][j] = Integer.parseInt(st.nextToken());
		}
	}
	/*첫번재오류 : 가로 < 세로 v 부분에서는 idx(첫시작좌표위치) 신경써줫지만, 가로 > 세로 ^부분에서 신경안쒀줫기에 잘안돌아감
	 *두번째오류 : 가로 세로 N M 이라 정해놧음 N=세로, M=가로
	 */
	static void solve() {
		// idx = startpoint
		for (int cycle = 0; cycle < R; cycle++) {
			for (int idx = 0; idx < Math.min(N, M) / 2; idx++) {
				int temp = ary[idx][idx];
				int i = idx, j = idx;
				// 가로 <
				for (; j < M - idx - 1; j++)
					ary[i][j] = ary[i][j + 1];
				// 세로 v
				for (; i < N - idx - 1; i++)
					ary[i][j] = ary[i + 1][j];
				// 가로 >
				for (; j > 0 + idx; j--)
					ary[i][j] = ary[i][j - 1];
				// 세로 ^
				for (; i > 1 + idx; i--)
					ary[i][j] = ary[i - 1][j];
				ary[i][j] = temp;
				view();
			}
		}
	}

	static void view() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				System.out.print(ary[i][j] + " ");
			System.out.println();
		}
		System.out.println();
	}

	public static void main(String[] args) throws IOException {
		init();
		solve();
		view();
	}
}
