import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int[] keys = new int[1001];
	static int N;
	
	static List<TimeInOut>[] time = new ArrayList[10101];
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		
		for (int i = 0; i < 10101; i++) {
			time[i] = new ArrayList<TimeInOut>();
		}
		
		for (int i = 0; i <= 1000; i++) {
			keys[i] = i <= N && i != 0 ? i : -1;
		}
		
		int k = scanner.nextInt();
		
		int maxTime = 0;
		
		for (int i = 0; i < k; i++) {
			int num = scanner.nextInt();
			int s = scanner.nextInt();
			int c = scanner.nextInt();
			
			time[s].add(new TimeInOut(TimeInOut.OUT, num));
			time[s + c].add(new TimeInOut(TimeInOut.IN, num));
			maxTime = s + c > maxTime ? s + c : maxTime;
		}
		
		for (int i = 1; i <= maxTime; i++) {
			List<TimeInOut> list = time[i];
			
			List<TimeInOut> a = new ArrayList<TimeInOut>();
			List<TimeInOut> b = new ArrayList<TimeInOut>();
			
			
			
			for (TimeInOut tio : list) {
				if (tio.type == TimeInOut.IN)
					a.add(tio);
				else
					b.add(tio);
			}
			
			Collections.sort(a);
			a.addAll(b);
			
			for (TimeInOut tio : a) {
				if (tio.type == TimeInOut.IN)
					for (int j = 1; j <= N; j++) {
						if (keys[j] == -1) {
							keys[j] = tio.num;
							break;
						}
					}
				else
					for (int j = 1; j <= N; j++) {
						if (keys[j] == tio.num) {
							keys[j] = -1;
							break;
						}
					}
			}
		}
		
		for (int i = 1; i <= N; i++) {
			System.out.print(keys[i]);
			if (i != N)
				System.out.print(" ");
		}
	}
}

class TimeInOut implements Comparable<TimeInOut>{
	static final int IN = 1;
	static final int OUT = 0;
	int type;
	int num;
	public TimeInOut(int type, int num) {
		super();
		this.type = type;
		this.num = num;
	}
	@Override
	public int compareTo(TimeInOut arg0) {
		// TODO Auto-generated method stub
		return num - arg0.num;
	}
	
}