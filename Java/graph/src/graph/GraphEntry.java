package graph;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class GraphEntry {

	public static void main(String[] args) {
		Graph gL = readGraphList("lista_sasiedztwa.txt");

		for (Node node : gL.nodes) {
			node.resetDfs();
		}

		for (Node node : gL.nodes) {
			if (node.dfsColor != Color.Red) {
				dfs(node);
			}
		}
		
		System.out.println();

		Graph gM = readGraphMatrix("macierz_sasiedztwa.txt");

		for (Node node : gM.nodes) {
			node.resetDfs();
		}

		for (Node node : gM.nodes) {
			if (node.dfsColor != Color.Red) {
				dfs(node);
			}
		}
	}

	private static void dfs(Node u) {
		u.dfsColor = Color.Red;
		for (Node v : u.children) {
			if (v.dfsColor != Color.Red) {
				v.dfsParent = u;
				System.out.println(String.format("%d - %d", u.value, v.value));
				dfs(v);
			}
		}
	}

	/// Odczyt grafu z macierzy sasiedztwa
	private static Graph readGraphMatrix(String fileName) {
		Graph g = null;

		try {
			List<String> lines = Files.readAllLines(Paths.get(fileName), Charset.forName("UTF-8"));

			if (lines.size() > 0) {
				String firstLine = lines.get(0);
				lines.remove(0);
				int count = Integer.parseInt(firstLine);

				g = new Graph();
				for (int i = 1; i <= count; i++) {
					g.addNode(i);
				}
				for (int i = 0, c = lines.size(); i < c; i++) {
					String[] numbers = lines.get(i).split(",");
					for (int j = 0, d = numbers.length; j < d; j++) {
						if ("1".equals(numbers[j])) {
							g.addEdge(i + 1, j + 1, true);
						}
					}
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		return g;
	}

	/// Odczyt grafu z listy sasiedztwa
	private static Graph readGraphList(String fileName) {
		Graph g = null;

		try {
			List<String> lines = Files.readAllLines(Paths.get(fileName), Charset.forName("UTF-8"));

			if (lines.size() > 0) {
				String firstLine = lines.get(0);
				int count = Integer.parseInt(firstLine);
				lines.remove(0);

				g = new Graph();
				for (int i = 1; i <= count; i++) {
					g.addNode(i);
				}
				for (String line : lines) {
					String[] numbers = line.split(",");
					int n = 0;
					for (String number : numbers) {
						int v = Integer.parseInt(number);
						if (n == 0) {
							n = v;
						} else {
							g.addEdge(n, v, false);
						}
					}
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		return g;
	}
}
