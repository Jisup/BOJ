package _16928_뱀과사다리게임;

import java.io.*;
import java.util.*;

class Pair {
	int index;
	int count;

	public Pair(int index, int count) {
		this.index = index;
		this.count = count;
	}
}

public class Main {

	final static int MAX = 101;
	final static int INF = 2147483647;

	static int answer = INF;
	static HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
	static boolean visit[] = new boolean[MAX];

	public static void solve() {
		Queue<Pair> q = new LinkedList<>();
		Pair start = new Pair(1, 0);
		q.add(start);
		visit[1] = true;

		while (!q.isEmpty()) {
			Pair out = q.poll();
			if (out.index == 100) {
				answer = answer < out.count ? answer : out.count;
				continue;
			}
			for (int i = 1; i <= 6; i++) {
				Integer next = out.index + i;
				Integer nc = out.count + 1;

				if (next <= 100 && !visit[next]) {
					visit[next] = true;
					if (m.containsKey(next)) {
						next = m.get(next);
					}
					q.add(new Pair(next, nc));
				}
			}
		}

		System.out.println(answer);
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int s = sc.nextInt(), b = sc.nextInt();
		
		for (int i = 0; i < s; i++) {
			int temp1 = sc.nextInt();
			int temp2 = sc.nextInt();
			m.put(temp1, temp2);
		}

		for (int i = 0; i < b; i++) {
			int temp1 = sc.nextInt();
			int temp2 = sc.nextInt();
			m.put(temp1, temp2);
		}
		Arrays.fill(visit, false);
		solve();

		sc.close();
	}
}
