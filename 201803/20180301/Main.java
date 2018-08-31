import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int score = 0;
		int last = 0;
		int t = 0;
		while ((t= scanner.nextInt()) != 0) {
			if (t == 1) {
				last = 1;
				score += 1;
			} else if (t== 2) {
				if (last == 0 || last == 1) {
					last = 2;
					score += 2;
				} else {
					last += 2;
					score += last;
				}
			}
		}
		System.out.println(score);
	}
}
