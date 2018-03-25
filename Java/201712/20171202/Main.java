import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n, k;
		n = sc.nextInt();
		k = sc.nextInt();
		
		List<Integer> ls= new ArrayList<>();
		for (int i = 0; i < n; i++)
			ls.add(i + 1);
		
		int index = 0;
		int num = 1;
		
		while (ls.size() != 1) {
			if (num % k == 0 || num % 10 == k) {
				ls.remove(index);
				index -= 1;
			}
			index = (index + 1) % (ls.size());
			num++;
		}
		
		System.out.println(ls.get(0));
	}
}
