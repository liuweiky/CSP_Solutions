import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		List<Integer> numbers = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			numbers.add(scanner.nextInt());
		}
		String outstr = "";
		for (int i = 0; i < n; i++) {
			int above = 0;
			int below = 0;
			for (int j = 0; j < n; j++) {
				if (numbers.get(i) > numbers.get(j))
					below += 1;
				else if (numbers.get(i) < numbers.get(j))
					above += 1;
			}
			if (above == below && !outstr.contains(String.valueOf(numbers.get(i)))) {
				outstr += (numbers.get(i) + " ");
			}
		}
		
		if (outstr.length() == 0) {
			System.out.println("-1");
		} else {
			System.out.println(outstr.trim());
		}
		
	}
}
