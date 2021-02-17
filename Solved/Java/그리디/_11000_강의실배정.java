package 그리디;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class xy_11000 implements Comparable<xy_11000>{
	int fs;
	int se;
	xy_11000(int fs, int se){
		this.fs=fs;
		this.se=se;
	}
	public int getFs() {
		return fs;
	}
	public void setFs(int fs) {
		this.fs = fs;
	}
	public int getSe() {
		return se;
	}
	public void setSe(int se) {
		this.se = se;
	}
	@Override
	public int compareTo(xy_11000 o) {
		if (this.fs > o.getFs())
			return 1;
		else if (this.fs < o.getFs())
			return -1;
		else {
			if (this.se >= o.getSe())
				return 1;
			else if(this.se < o.getSe())
				return -1;
		}
		return 0;
	}
}
public class _11000_강의실배정 {
	static PriorityQueue<xy_11000>pq = new PriorityQueue<xy_11000>();
	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int tc = Integer.parseInt(st.nextToken());
		for(int t=1;t<=tc;t++) {
			st = new StringTokenizer(br.readLine());
			int fs = Integer.parseInt(st.nextToken());
			int se = Integer.parseInt(st.nextToken());
			pq.add(new xy_11000(fs, se));
		}
	}
	static void solve() {
		PriorityQueue<Integer>q = new PriorityQueue<Integer>();
		while(!pq.isEmpty()) {
			xy_11000 out = pq.poll();
			int fs = out.getFs();
			int se = out.getSe();
			if (q.isEmpty()) {
				q.add(se);
				continue;
			}
			if (q.peek() > fs)
				q.add(se);
			else {
				q.poll();
				q.add(se);
			}
		}
		System.out.println(q.size());
	}
	public static void main(String[] args) throws IOException {
		init();
		solve();
	}

}
