package 단순구현;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class _2164_카드2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Queue<Integer>q=new LinkedList<Integer>();
		for(int i=1;i<=N;i++)
			q.add(i);
		if (N==1) {
			System.out.println(1);
			return;
		}
		while(!q.isEmpty()) {
			q.poll();
			if (q.size() == 1)
				break;
			int out = q.poll();
			q.add(out);
		}
		System.out.println(q.poll());
	}
}
