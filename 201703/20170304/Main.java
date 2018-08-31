import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	// static int[][] graph = new int[100000][100000];
	
	static Vertex[] head = new Vertex[100001];
	static int N, M;
	
	static int[] visited = new int[100001];
	static int[] path = new int[100001];
	static int[] dis = new int[100001];
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String line = br.readLine();
		String[] datas = line.split(" ");
		
		N = Integer.parseInt(datas[0]);
		M = Integer.parseInt(datas[1]);
		for (int i = 1; i <= N; i++)
			head[i] = new Vertex(i);
		for (int i = 0; i < M; i++) {
			int a, b, c;
			datas = br.readLine().split(" ");
			a = Integer.parseInt(datas[0]);
			b = Integer.parseInt(datas[1]);
			c = Integer.parseInt(datas[2]);
			Edge edge = new Edge(b, c);
			edge.link = head[a].adjacent;
			head[a].adjacent = edge;
			edge = new Edge(a, c);
			edge.link = head[b].adjacent;
			head[b].adjacent = edge;
		}
		
		dijkstra(1);
		
//		for (int i = 1; i <= N; i++) {
//			System.out.print(path[i] + " ");
//		}
		
		System.out.println(dis[N]);
	}
	
	public static void dijkstra(int v) {
		for (int i = 1; i <= N; i++) {
			visited[i] = 0;
			path[i] = -1;
			dis[i] = Integer.MAX_VALUE;
		}
		
		dis[v] = 0;
		
		for (int i = 0; i < N - 1; i++) {
			visited[v] = 1;
			Vertex vertex = head[v];
			Edge edge = vertex.adjacent;
			while (edge != null) {
				if (visited[edge.verAdj] == 0 &&
					dis[edge.verAdj] > Math.max(edge.cost, dis[v])) {	// 这里的距离应改为路径上最长隧道长度，而不是总长度
					dis[edge.verAdj] = Math.max(edge.cost, dis[v]);
					path[edge.verAdj] = v;
				}
				edge = edge.link;
			}
			
			int minDis = Integer.MAX_VALUE;
			int u = 1;
			
			for (int j = 1; j <= N; j++) {
				if (visited[j] == 0 && minDis > dis[j]) {
					minDis = dis[j];
					u = j;
				}
			}
			
			v = u;
		}
	}
}

class Vertex {
	int verName;
	Edge adjacent;
	public Vertex(int verName) {
		super();
		this.verName = verName;
		adjacent = null;
	}
}

class Edge {
	int verAdj;
	int cost;
	Edge link;
	public Edge(int verAdj, int cost) {
		super();
		this.verAdj = verAdj;
		this.cost = cost;
		link = null;
	}
}