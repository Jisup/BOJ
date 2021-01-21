
import java.util.Scanner;

public class _15652_N°úM_4 {

	static int N;
	static int M;
	static int index = 0;
	static int temp[] = new int[8];

	static StringBuilder sb = new StringBuilder();

	static void permutation(int cnt) {
		if (cnt == M) {
			for (int i = 0; i < M; i++)
				sb.append(temp[i] + " ");
			sb.append("\n");
			return;
		}
		for (int i = cnt == 0 ? 1 : temp[cnt - 1]; i <= N; i++) {
			temp[cnt] = i;
			permutation(cnt + 1);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		permutation(0);
		System.out.print(sb);
	}
}
