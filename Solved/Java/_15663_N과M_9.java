import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.Scanner;

public class _15663_N과M_9 {

	static int N;
	static int M;
	static int ary[];
	static boolean visit[] = new boolean[9];
	
	static StringBuilder sb = new StringBuilder();
	static LinkedHashSet<String> h = new LinkedHashSet<String>();
	
	static void permutation(int index, int cnt, int temp[]) {
		if (cnt == M) {
			String input="";
			for(int item : temp)
				input+= item+" ";
			h.add(input+"\n");
			return;
		}
		for(int i=0;i<N;i++) {
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
		ary=new int[N];
		for(int i=0;i<N;i++)
			ary[i] = sc.nextInt();
		Arrays.sort(ary);
		
		for(int i=0;i<N;i++) {
			int temp[] = new int[M];
			visit[i]=true;
			temp[0]=ary[i];
			permutation(i, 1, temp);
			visit[i]=false;
		}
		
		Iterator<String> iter = h.iterator();
		while(iter.hasNext()) {
			System.out.print(iter.next());
		}
		sc.close();
	}
}
