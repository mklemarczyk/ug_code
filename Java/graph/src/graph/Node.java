package graph;

import java.util.ArrayList;

public class Node {
	public Node dfsParent;
	public Color dfsColor;

	public int value;
	public ArrayList<Node> children;

	public Node(int i) {
		this.children = new ArrayList<Node>();
		this.value = i;
		this.resetDfs();
	}

	public void addChild(Node node) {
		this.children.add(node);
	}

	public void resetDfs() {
		this.dfsParent = null;
		this.dfsColor = Color.Black;
	}
}
