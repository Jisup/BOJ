import java.util.Arrays;
import java.util.Scanner;

public class _15653_N°úM_5 {

	static int N;
	static int M;
	static int ary[];
	static boolean visit[] = new boolean[9];
	static void permutation(int index, int cnt, int temp[]) {
		if (cnt == M) {
			for(int item : temp)
				System.out.print(item+" ");
			System.out.println();
			return;
		}
		for(int i=1;i<=N;i++) {
			if (!visit[i]) {
				visit[i]=true;
				temp[cnt]=ary[i];
				permutation(i, cnt+1, temp);
				visit[i]=false;
			}
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		ary = new int[N+1];
		for(int i=1;i<=N;i++)
			ary[i]=sc.nextInt();
		Arrays.sort(ary);
		
		for(int i=1;i<=N;i++) {
			int temp[] = new int[M];
			visit[i]=true;
			temp[0]=ary[i];
			permutation(i, 1, temp);
			visit[i]=false;
		}
	}
}
