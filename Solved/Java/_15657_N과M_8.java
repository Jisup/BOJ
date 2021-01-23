import java.util.Arrays;
import java.util.Scanner;

public class _15657_N과M_8 {
	static final int MAX = 8;
	
	static int N;
	static int M;
	static int ary[];
	static int temp[] = new int[MAX];
	static boolean visit[] = new boolean[MAX];
	
	static StringBuilder sb = new StringBuilder();
	
	static void permutation(int index, int cnt) {
		if (cnt == M ) {
			String input="";
			for(int i=0;i<M;i++) {
				input+= temp[i]+" ";
			}
			sb.append(input+"\n");
			return;
		}
		for(int i = (cnt==0?0:index);i<N;i++) {
			temp[cnt] = ary[i];
			permutation(i, cnt+1);
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
		
		permutation(0, 0);
		System.out.print(sb);
		sc.close();
	}

}
