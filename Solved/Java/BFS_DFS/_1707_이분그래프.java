package BFS_DFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Vector;

public class _1707_이분그래프 {
	static final int MAX = 20001;
	static int TC, V, E;

	static int visit[] = new int[MAX];
	static Vector<Integer>[] g = new Vector[MAX];

	static StringBuilder sb = new StringBuilder();
	
	static void init(BufferedReader br) throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= V; i++) {
			//vector 크기사이즈변경이 너무작으면 시간초과발생
			//당시 1이었고 10에서 패스
			g[i] = new Vector<Integer>(1, 10);
		}
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int fs = Integer.parseInt(st.nextToken());
			int se = Integer.parseInt(st.nextToken());
			g[fs].add(se);
			g[se].add(fs);
		}
	}

	static void solve() {
		Arrays.fill(visit, -1);
		for (int i = 1; i <= V; i++) {
			if (visit[i] == -1) {
				dfs(i, 0);
			}
		}
	}

	static void dfs(int index, int flag) {
		visit[index] = flag = flag == 1 ? 0 : 1;
		for(Integer item : g[index]) {
			if (visit[item] == -1)
				dfs(item, flag);
		}
	}
	
	static void find() {
		for(int i=1;i<=V;i++) {
			for(int j=0;j<g[i].size();j++) {
				int next = g[i].get(j);
				if (visit[i] == visit[next]) {
					sb.append("NO\n");
					return;
				}
			}
		}
		sb.append("YES\n");
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		TC = Integer.parseInt(br.readLine());

		for (int t = 1; t <= TC; t++) {
			init(br);
			solve();
			find();
		}
		System.out.println(sb);
	}
}
