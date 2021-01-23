import java.util.Arrays;
import java.util.Scanner;

public class _15656_N과M_7 {
	static final int MAX = 7;
	
	static int N, M;
	static int ary[];
	static int temp[] = new int[MAX];
	static boolean visit[] = new boolean[MAX];
	
	static StringBuilder sb = new StringBuilder();
	
	static void permutation(int cnt) {
		if (cnt == M ) {
			String input="";
			for(int i=0;i<M;i++) {
				input+= temp[i]+" ";
			}
			sb.append(input+"\n");
			return;
		}
		for(int i=0;i<N;i++) {
			temp[cnt] = ary[i];
			permutation(cnt+1);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N= sc.nextInt();
		M= sc.nextInt();
		ary = new int[N];
		for(int i=0;i<N;i++) {
			ary[i] = sc.nextInt();
		}
		Arrays.sort(ary);
		
		permutation(0);
		System.out.print(sb);
		sc.close();
	}

}
