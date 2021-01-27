package BFS_DFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.Vector;

public class _11724_연결요소의_개수 {

	static final int MAX = 1001;
	static int N, M;

	static boolean visit[] = new boolean[MAX];
	static Vector<Integer> v[] = new Vector[MAX];

	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String temp[] = br.readLine().split(" ");
		N = Integer.parseInt(temp[0]);
		M = Integer.parseInt(temp[1]);

		for (int i = 1; i <= N; i++)
			v[i] = new Vector<Integer>(N+1);

		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int fs = Integer.parseInt(st.nextToken());
			int se = Integer.parseInt(st.nextToken());
			v[fs].add(se);
			v[se].add(fs);
		}
	}

	static int solve() {
		Queue<Integer> q = new LinkedList<Integer>();
		int result = 0;
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				visit[i] = true;
				q.add(i);
				result++;
				while (!q.isEmpty()) {
					int out = q.poll();
					for (Integer item : v[out]) {
						if (!visit[item]) {
							visit[item] = true;
							q.add(item);
						}
					}
				}
			}
		}
		return result;
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		init();
		System.out.println(solve());
	}
}
