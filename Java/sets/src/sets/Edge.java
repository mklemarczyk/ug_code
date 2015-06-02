package sets;

public class Edge {
	public int waga;
	public int x;
	public int y;

	public Edge(int waga, int x, int y) {
		this.x = x;
		this.y = y;
	}

	public String toString() {
		return Integer.toString(x) + "-" + Integer.toString(y);
	}
}
