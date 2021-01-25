package 브루트포스;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.Scanner;

public class _15665_N과M_11 {
	static final int MAX = 7;
	
	static int N;
	static int M;
	static int ary[];
	static int temp[];
	
	static StringBuilder sb = new StringBuilder();
	static LinkedHashSet<String> h = new LinkedHashSet<String>();
	
	static void permutation(int cnt) {
		if (cnt == M) {
			String input="";
			for(int item : temp)
				input+= item+" ";
			if(h.add(input+"\n"))
				sb.append(input+"\n");
			return;
		}
		for (int i = 0; i < N; i++) {
			temp[cnt] = ary[i];
			permutation(cnt + 1);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();

		ary=new int[N];
		temp=new int[M];
		
		for(int i=0;i<N;i++)
			ary[i] = sc.nextInt();
		Arrays.sort(ary);
		
		permutation(0);
		System.out.print(sb);
		sc.close();
	}
}
