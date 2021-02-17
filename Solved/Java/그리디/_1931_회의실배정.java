package 그리디;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Data {
	int fs;
	int se;
	Data(int fs, int se) {
		this.fs=fs;
		this.se=se;
	}
}
public class _1931_회의실배정 {
	static int N;
	static ArrayList<Data>ary = new ArrayList<Data>();
	static void solve() {
		int room=0, time=0;
		for(int i=0;i<N;i++) {
			System.out.println(ary.get(i).fs+" "+ary.get(i).se);
			if (time <= ary.get(i).fs) {
				time = ary.get(i).se;
				room++;
			}
		}
		System.out.println(room);
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int fs = Integer.parseInt(st.nextToken());
			int se = Integer.parseInt(st.nextToken());
			ary.add(new Data(fs, se));
		}
//		Collections.sort(ary, (o1, o2)-> o1.se!=o2.se ? o1.se-o2.se : o1.fs-o2.fs);
		Collections.sort(ary, (o1, o2) -> {
			if (o1.se > o2.se)
				return 1;
			else if (o1.se < o2.se)
				return -1;
			else {
				if (o1.fs >= o2.fs)
					return 1;
				else if(o1.fs < o2.fs)
					return -1;
			}
			return 0;
		});
		solve();
	}
}