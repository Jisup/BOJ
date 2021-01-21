
import java.util.Scanner;

public class _15651_N°úM_3 {

	static int N;
	static int M;
	static int temp[] = new int[7];
	
	static StringBuilder sb = new StringBuilder();
	
	static void permutation(int cnt) {
		if (cnt == M) {
			for(int i=0;i<M;i++)
				sb.append(temp[i] + " ");
			sb.append("\n");
			return;
		}
		for (int i = 1; i <= N; i++) {
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
