package sets;

import java.util.ArrayList;
import java.util.Comparator;

public class Main {

	public static void main(String[] args) {
		/*
		 * SetDir dir = new SetDir(); dir.makeSet(0); dir.makeSet(1);
		 * dir.makeSet(2); dir.makeSet(3); dir.makeSet(4); dir.makeSet(5);
		 * dir.makeSet(6); dir.makeSet(7); dir.makeSet(8); dir.makeSet(9);
		 * dir.union(dir.findSet(0), dir.findSet(1)); dir.union(dir.findSet(2),
		 * dir.findSet(3)); dir.union(dir.findSet(1), dir.findSet(2));
		 * dir.union(dir.findSet(5), dir.findSet(6)); dir.union(dir.findSet(7),
		 * dir.findSet(8)); dir.union(dir.findSet(3), dir.findSet(5));
		 * dir.union(dir.findSet(0), dir.findSet(7)); dir.print();
		 */

		SetDir dir = new SetDir();
		dir.makeSet(0);
		dir.makeSet(1);
		dir.makeSet(2);
		dir.makeSet(3);
		dir.makeSet(4);
		dir.makeSet(5);
		dir.makeSet(6);
		dir.makeSet(7);
		dir.makeSet(8);
		dir.makeSet(9);
		dir.union(dir.compressFindSet(0), dir.compressFindSet(1));
		dir.union(dir.compressFindSet(2), dir.compressFindSet(3));
		dir.union(dir.compressFindSet(1), dir.compressFindSet(2));
		dir.union(dir.compressFindSet(5), dir.compressFindSet(6));
		dir.union(dir.compressFindSet(7), dir.compressFindSet(8));
		dir.union(dir.compressFindSet(3), dir.compressFindSet(5));
		dir.union(dir.compressFindSet(0), dir.compressFindSet(7));
		dir.print();

		System.out.println();
		kruskal();
	}

	public static void kruskal() {
		// Definicja grafu
		ArrayList<Integer> points = new ArrayList<Integer>();
		ArrayList<Edge> edges = new ArrayList<Edge>();
		points.add(0);
		points.add(1);
		points.add(2);
		points.add(3);
		points.add(4);
		points.add(5);

		edges.add(new Edge(1, 1, 5));
		edges.add(new Edge(5, 2, 3));
		edges.add(new Edge(2, 3, 4));
		edges.add(new Edge(6, 5, 3));
		edges.add(new Edge(3, 1, 2));
		edges.add(new Edge(7, 5, 4));
		edges.add(new Edge(4, 2, 5));

		// Algorytm
		ArrayList<Edge> newEdges = new ArrayList<Edge>();
		SetDir dir = new SetDir();
		for (int i : points) {
			dir.makeSet(i);
		}
		edges.sort(new EdgeComparator());
		for (Edge e : edges) {
			SetNode s1 = dir.findSet(e.x);
			SetNode s2 = dir.findSet(e.y);
			if (s1 != s2) {
				newEdges.add(e);
				dir.union(s1, s2);
			}
		}

		System.out.println("Edges:");
		for (Edge e : newEdges) {
			System.out.println(e.toString());
		}

	}
}

class EdgeComparator implements Comparator<Edge> {
	public int compare(Edge arg0, Edge arg1) {
		return Integer.compare(arg0.waga, arg1.waga);
	}
}
