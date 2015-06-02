package graph;

import java.util.ArrayList;

public class Graph {
	public ArrayList<Node> nodes;

	public Graph() {
		this.nodes = new ArrayList<Node>();
	}

	public void addNode(int i) {
		this.nodes.add(new Node(i));
	}

	public void addEdge(int a, int b) {
		addEdge(a, b, true);
	}

	public void addEdge(int a, int b, boolean undirected) {
		this.nodes.get(a - 1).addChild(this.nodes.get(b - 1));
		if (a != b && undirected) {
			this.nodes.get(b - 1).addChild(this.nodes.get(a - 1));
		}
	}

}
