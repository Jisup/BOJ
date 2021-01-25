package 브루트포스;
import java.util.Scanner;

public class _15650_N과M_2 {

	static int N;
	static int M;
	static boolean visit[] = new boolean[9];

	static void permutation(int index, int cnt, int temp[]) {
		if (cnt == M) {
			for (int item : temp)
				System.out.print(item + " ");
			System.out.println();
			return;
		}
		for (int i = index+1; i <= N; i++) {
			if (!visit[i]) {
				visit[i] = true;
				temp[cnt] = i;
				permutation(i, cnt + 1, temp);
				visit[i] = false;
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();

		for (int i = 1; i <= N; i++) {
			int temp[] = new int[M];
			visit[i] = true;
			temp[0] = i;
			permutation(i, 1, temp);
			visit[i] = false;
		}
	}
}
