package BFS_DFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class _1260_DFS와BFS {

	static int N;
	static int M;
	static int V;

	static boolean visit[] = new boolean[1001];
	static Vector<Integer> v[] = new Vector[1001];

	static StringBuilder sb = new StringBuilder();

	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= N; i++)
			v[i] = new Vector<Integer>(N + 1);

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int fs = Integer.parseInt(st.nextToken());
			int se = Integer.parseInt(st.nextToken());
			v[fs].add(se);
			v[se].add(fs);
		}
		
		for (int i = 1; i <= N; i++)
			Collections.sort(v[i]);
	}

	static void dfs_solve(int index) {
		if (visit[index]) return;
		visit[index]=true;
		sb.append(index+" ");
		for (Integer item : v[index]) {
			dfs_solve(item);
		}
	}
	
	static void bfs_solve(int index) {
		Queue<Integer>q = new LinkedList();
		q.add(index);
		visit[index]=true;
		while(!q.isEmpty()) {
			int out = q.poll();
			sb.append(out+" ");
			for (Integer item : v[out]) {
				if (!visit[item]) {
					visit[item]=true;
					q.add(item);
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		init();

		Arrays.fill(visit, false);
		dfs_solve(V);
		sb.append("\n");
		Arrays.fill(visit, false);
		bfs_solve(V);
		
		System.out.println(sb);
	}

}
