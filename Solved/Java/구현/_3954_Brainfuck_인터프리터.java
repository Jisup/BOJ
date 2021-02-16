package 구현;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class _3954_Brainfuck_인터프리터 {
	static int Memory, Code, Input;
	static String code, input;
	
	static int index, idx, loops, i;
	static int ary[];
	static int jump[];
	static void init() throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int tc = Integer.parseInt(br.readLine());
		for(int t=1;t<=tc;t++) {
			st = new StringTokenizer(br.readLine());
			Memory = Integer.parseInt(st.nextToken());
			ary = new int[Memory];
			Code = Integer.parseInt(st.nextToken());
			jump = new int[Code];
			Input = Integer.parseInt(st.nextToken());
			code = br.readLine();
			input = br.readLine();
			Arrays.fill(jump, -1);
			find();
			solve();
		}
	}
	static void find() {
		Stack<Integer>s=new Stack<>();
		for(int i=0;i<code.length();i++) {
			if (code.charAt(i) == '[')
				s.push(i);
			else if (code.charAt(i) == ']') {
				int value = s.pop();
				jump[i] = value;
				jump[value] = i;
			}
		}
	}
	static void solve() {
		index=0;
		idx=0;
		loops=0;
		i=0;
		while(loops<=50000000 && i<Code) {
			process();
			i++;
			loops++;
		}
		if (loops <= 50000000)
			System.out.println("Terminates");
		else {
			int max=i,min=i;
			while(loops-->0) {
				process();
				i++;
				max = Math.max(max, i);
				min = Math.min(min, i);
			}
			System.out.println("Loops "+(min-1)+" "+max);
		}
	}
	static void process() {
		switch(code.charAt(i)) {
		case '+':
			ary[index] = (ary[index]+1)%256;
			break;
		case '-':
			ary[index] = (ary[index]-1+256)%256;
			break;
		case '<':
			index = index-1 >= 0 ? index-1:Memory-1;
			break;
		case '>':
			index = index+1 < Memory ? index+1:0;
			break;
		case '[':
			if (ary[index] == 0)
				i = jump[i];
			break;
		case ']':
			if (ary[index] != 0) {
				i = jump[i];
			}
			break;
		case '.':
			break;
		case ',':
			if (input.length() > idx)
				ary[index] = Integer.valueOf(input.charAt(idx++));
			else
				ary[index]=255;
			break;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		init();
	}
}
