package 브루트포스;
import java.util.Arrays;
import java.util.Scanner;

public class _15654_N과M_6{

	static int N;
	static int M;
	static int ary[];
	static int temp[] = new int[8];

	static StringBuilder sb = new StringBuilder();

	static void permutation(int index, int cnt) {
		if (cnt == M) {
			for (int i = 0; i < M; i++)
				sb.append(temp[i] + " ");
			sb.append("\n");
			return;
		}
		for (int i = index+1; i <= N; i++) {
			temp[cnt] = ary[i];
			permutation(i, cnt + 1);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		ary=new int[N+1];
		for(int i=1;i<=N;i++)
			ary[i]=sc.nextInt();
		Arrays.sort(ary);
		permutation(0, 0);
		System.out.print(sb);
	}
}
