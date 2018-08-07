import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int n, L, t;
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		L = scanner.nextInt();
		t = scanner.nextInt();
		
		List<Ball> balls = new ArrayList<Ball>();
		
		for (int i = 0; i < n; i++) {
			int p = scanner.nextInt();
			balls.add(new Ball(p, Ball.RIGHT));
		}
		
//		Collections.sort(balls);
		
//		for (Ball ball : balls) {
//			System.out.println(ball.pos);
//		}
		
		for (int i = 0; i < t; i++) {
			for (Ball ball : balls) {
				if (ball.pos == 0)
					ball.dir = Ball.RIGHT;
				else if (ball.pos == L)
					ball.dir = Ball.LEFT;
				ball.pos += ball.dir;
			}
			
			for (int j = 0; j <= L; j++) {
				Ball b = null;
				for (Ball ball : balls) {
					if (ball.pos == j) {
						if (b != null) {
							b.dir = -b.dir;
							ball.dir = -ball.dir;
						} else {
							b = ball;
						}
					}
				}
			}
		}
		
		for (Ball ball : balls) {
			System.out.print(ball.pos);
			System.out.print(' ');
		}
	}
}

class Ball implements Comparable<Ball>{
	public static int RIGHT = 1;
	public static int LEFT = -1;

	int pos;
	int dir;
	
	public Ball(int pos, int dir) {
		super();
		this.pos = pos;
		this.dir = dir;
	}

	@Override
	public int compareTo(Ball arg0) {
		// TODO Auto-generated method stub
		return this.pos - arg0.pos;
	}
	
	
}