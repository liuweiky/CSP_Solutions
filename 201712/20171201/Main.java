import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		List<Integer> ls = new ArrayList<>();
		
		for (int i = 0; i < n; i++) {
			ls.add(sc.nextInt());
		}
		
		int min = Integer.MAX_VALUE;
		
		for (int i = 0; i < ls.size(); i++) {
			for (int j = i + 1; j < ls.size(); j++) {
				min = Math.abs(ls.get(i) - ls.get(j)) < min ? Math.abs(ls.get(i) - ls.get(j)) : min;
			}
		}
		
		System.out.println(min);
	}
}
