import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	static int[][] graph1 = new int[1001][1001];
	static int[][] graph2 = new int[1001][1001];
	static int N, M;
	static int[] visit1 = new int[1001];
	static int[] visit2 = new int[1001];
	static int[] visit = new int[1001];
	static Set<Integer> record = new HashSet<Integer>();
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		M = scanner.nextInt();
		for (int i = 0; i < M; i++) {
			int s = scanner.nextInt();
			int t = scanner.nextInt();
			graph1[s][t] = 1;
			graph2[t][s] = 1;
		}
		
		for (int i = 1; i <= N; i++) {
			init(1, 1, 1);
			dfs(i, graph1, visit1);
//			System.out.println();
			if (check())
				record.add(i);
			else {
				init(0, 1, 1);
				dfs(i, graph2, visit2);
//				System.out.println();
				if (check())
					record.add(i);
			}
		}
		
		System.out.println(record.size());
	}
	
	public static void dfs(int v, int[][] graph, int[] visited) {
//		System.out.print(v + " ");
		visited[v] = 1;
		for (int i = 1; i <= N; i++)
			if (graph[v][i] == 1 && visited[i] == 0)
				dfs(i, graph, visited);
	}
	
	public static void init(int a, int b, int c) {
		for (int i = 1; i <= N; i++) {
			if (a == 1)
				visit1[i] = 0;
			if (b == 1)
				visit2[i] = 0;
			if (c == 1)
				visit[i] = 0;
		}
	}
	
	public static boolean check() {
		for (int i = 1; i <= N; i++)
		{
			visit[i] = visit1[i] + visit2[i];
		}
		for (int i = 1; i <= N; i++)
			if (visit[i] == 0)
				return false;
		return true;
	}
}
