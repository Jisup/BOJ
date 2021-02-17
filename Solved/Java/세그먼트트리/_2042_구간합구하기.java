package 세그먼트트리;

import java.util.Scanner;

class SegmentTree {
	static long ary[];
	static long segment_tree[];
	SegmentTree(int N) {
		ary = new long[N];
		int height = (int) Math.ceil(Math.log(N) / Math.log(2));
		int treeSize = 1 << (height+1);
		segment_tree = new long[treeSize];
	}
	long make(int start, int end, int node) {
		if (start==end) return segment_tree[node] = ary[start];
		int mid = (start+end)/2;
		return segment_tree[node] = make(start, mid, node*2)+make(mid+1, end, node*2+1);
	}
	long query(int start, int end, int node, int left, int right) {
		if (right < start || end < left) return 0; 
		if (left <= start && end <= right) return segment_tree[node];
		int mid = (start+end)/2;
		return query(start, mid, node*2, left, right)+query(mid+1, end, node*2+1, left, right);
	}
	void update(int start, int end, int node, int index, long value) {
		if (index < start || end < index) return;
		segment_tree[node] += value;
		if (start == end) return;
		int mid = (start+end)/2;
		update(start, mid, node*2, index, value);
		update(mid+1, end, node*2+1, index, value);
	}
}
public class _2042_구간합구하기 {
	static int N,M,K;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		
		SegmentTree ST = new SegmentTree(N);
		
		for(int i=0;i<N;i++)
			ST.ary[i] = sc.nextLong();
		
		ST.make(0,N-1,1);
		for(int i=0;i<M+K;i++) {
			int type = sc.nextInt();
			switch(type) {
			case 1:
				int index = sc.nextInt();
				long value = sc.nextLong();
				long temp = ST.ary[index-1];
				ST.ary[index-1] = value;
				value -= temp;
				ST.update(0, N-1, 1, index-1, value);
				break;
			case 2:
				int fs = sc.nextInt();
				int se = sc.nextInt();
				System.out.println(ST.query(0,N-1,1,fs-1,se-1));
				break;
			}
		}
	}
}