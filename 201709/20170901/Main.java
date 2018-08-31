import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int N = new Scanner(System.in).nextInt();
		int a = N / (5 * 10);
		int b = (N - a * 5 * 10) / (3 * 10);
		int c = (N - a * 5 * 10 - b * 3 * 10) / 10;
		System.out.println(a * 7 + b * 4 + c);
	}
}
