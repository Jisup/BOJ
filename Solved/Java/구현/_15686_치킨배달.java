package 구현;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

class pair_15686 {
	int y;
	int x;
	pair_15686(int y, int x){
		this.y=y;
		this.x=x;
	}
}
public class _15686_치킨배달 {
	static final int MAX = 51;
	static int H, select, ret=Integer.MAX_VALUE;
	static List<pair_15686>house = new LinkedList<>();
	static List<pair_15686>chiken = new LinkedList<>();
	static int map[][] = new int[MAX][MAX];
	static boolean visit[] = new boolean[15];
	static void init() {
		Scanner sc = new Scanner(System.in);
		H = sc.nextInt();
		select = sc.nextInt();
		for(int i=0;i<H;i++)
			for(int j=0;j<H;j++) {
				map[i][j] = sc.nextInt();
				if(map[i][j] == 1)
					house.add(new pair_15686(i, j));
				else if(map[i][j] == 2)
					chiken.add(new pair_15686(i, j));
			}
	}
	static void solve() {
		for(int i=0;i<chiken.size();i++) {
			int list[] = new int[select];
			list[0] = i;
			start(i, 1, list);
		}
	}
	static void start(int index, int cnt, int list[]) {
		if(cnt == select) {
			int result = dist(list);
			ret = ret < result ? ret : result;
			return;
		}
		for(int i=index;i<chiken.size();i++) {
			if (!visit[i]) {
				visit[i]=true;
				list[cnt]=i;
				start(i, cnt+1, list);
				visit[i]=false;
			}
		}
	}
	static int dist(int list[]) {
		int distance=0;
		for(int i=0;i<house.size();i++) {
			int Max = Integer.MAX_VALUE;
			for(int k=0;k<select;k++) {
				int y=chiken.get(list[k]).y;
				int x=chiken.get(list[k]).x;
				Max = Math.min(Max, Math.abs(y-house.get(i).y)+Math.abs(x-house.get(i).x));
			}
			distance+=Max;
		}
		return distance;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		init();
		solve();
		System.out.println(ret);
	}
}
