package 플로이드와샬;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class _1719_택배 {
	static final int MAX = 205;
	static int N;

	static int map[][] = new int[MAX][MAX];
	static int floyd[][] = new int[MAX][MAX];

	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		for (int item[] : floyd)
			Arrays.fill(item, 10000*1000-1);

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int fs = Integer.parseInt(st.nextToken());
			int se = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			map[fs][se] = se;
			map[se][fs] = fs;
			floyd[fs][se] = cost;
			floyd[se][fs] = cost;
		}
	}

	static void floyd() {
		for (int k = 1; k <= N; k++)
			for (int i = 1; i <= N; i++) {
				if (k == i)
					continue;
				for (int j = 1; j <= N; j++)
					if (floyd[i][j] > floyd[i][k] + floyd[k][j]) {
						floyd[i][j] = floyd[i][k] + floyd[k][j];
						map[i][j] = map[i][k];
					}
			}
	}

	static void view() {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)
					System.out.print("- ");
				else
					System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		init();
		floyd();
		view();
	}
}
