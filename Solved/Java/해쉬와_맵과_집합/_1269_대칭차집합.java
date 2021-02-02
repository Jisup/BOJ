package 해쉬와_맵과_집합;

import java.util.HashSet;
import java.util.Scanner;

public class _1269_대칭차집합 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		HashSet<Integer> hs = new HashSet<Integer>();
		int A = sc.nextInt();
		int B = sc.nextInt();
		int duple = 0;
		for(int i=0;i<A+B;i++) {
			if(!hs.add(sc.nextInt())) duple++;
		}
		System.out.println(hs.size()-duple);
	}

}
