package 브루트포스;

//import java.util.Arrays;
//import java.util.Scanner;
//
//public class _2309_일곱난쟁이 {
//	static final int MAX = 9;
//	
//	static int sum;
//	static int Dwarf[] = new int[MAX];
//	static int kin[] = new int[7];
//	static int cor[] = new int[7];
//	static boolean check[] = new boolean[MAX];
//	static void init() {
//		Scanner sc = new Scanner(System.in);
//		for(int i=0;i<9;i++)
//			Dwarf[i] = sc.nextInt();
//		for(int i=0;i<9;i++)
//			solve(0, i, Dwarf[i]);
//		
//		Arrays.sort(cor);
//		
//		for(int item : cor)
//			System.out.println(item);
//	}
//	static void solve(int cnt, int index, int daf) {
//	    check[index] = true;
//		kin[cnt] = daf;
//		if (cnt == 6) {
//			sum = 0;
//			for (int i = 0;i < 7;i++)
//				sum = sum + kin[i];
//			if (sum == 100)
//				for (int i = 0; i < 7;i++)
//					cor[i] = kin[i];
//			return;
//		}
//		for (int i = index+1;i < 9;i++)
//			if (!check[i]) {
//				solve(cnt + 1, i, Dwarf[i]);
//				check[i] = false;
//			}
//	}
//	public static void main(String[] args) {
//		// TODO Auto-generated method stub
//		init();
//	}
//
//}

import java.io.*;
import java.util.*;

public class _2309_일곱난쟁이 {
   static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
   static StringTokenizer st;

   static int[] arr;
   static boolean[] selected;
   static int n=9;

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      arr = new int[n];
      selected = new boolean[n];
      
      for(int i=0;i<n;i++)
         arr[i] = Integer.valueOf(br.readLine());
      
      Arrays.sort(arr);
      
      powerset(0,0);

      bw.flush();
      bw.close();
   }
   
   public static void powerset(int idx,int cnt) {
      if(cnt==7) {
         for(int i=0;i<arr.length;i++) {
            if(selected[i])
               System.out.print(i);
         }
         System.out.println();
         int sum=0;
         for(int i=0;i<arr.length;i++) {
            if(selected[i])
               sum+=arr[i];
         }
         if(sum==100) {
            for(int i=0;i<arr.length;i++) {
               if(selected[i])
                  System.out.println(arr[i]);
            }
            System.exit(0);
         }
         return;
      }
      if(idx==n)return;
      selected[idx] = true;
      powerset(idx+1,cnt+1);
      selected[idx] = false;
      powerset(idx+1,cnt);
   }
}