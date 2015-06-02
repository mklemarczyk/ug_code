package btree;

import java.io.File;
import java.io.IOException;

public class Tree {
	private Node rootWezel;
	private int wartoscNormalna;

	public Tree(int wartoscNormalna) {
		if (wartoscNormalna < 3) {
			System.out.println("This tree will not work properly");
		}
		this.wartoscNormalna = wartoscNormalna;
		String sciezka = NodeReader.dajSciezkeRoot();
		File plik = new File(sciezka);
		if (!plik.isFile()) {
			plik.getParentFile().mkdirs();
			try {
				plik.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		rootWezel = NodeReader.readNode(NodeReader.dajSciezkeRoot());
	}

	public String find(String klucz) {
		return find(rootWezel, klucz);
	}

	private String find(Node wezel, String klucz) {
		String nodeName = null;
		Status wstawiono = Status.NieWstawiono;
		if (wezel.ilosc != 0) {
			int licznik = 0;
			while (licznik < wezel.ilosc && wstawiono == Status.NieWstawiono) {
				if (wezel.dane.get(licznik * 2 + 1).compareTo(klucz) > 0) {
					Node nastepny = NodeReader.readNode(wezel, licznik * 2);
					nodeName = find(nastepny, klucz);
					wstawiono = Status.WstawionoRekurencyjnie;
				} else if (wezel.dane.get(licznik * 2 + 1).equals(klucz)) {
					nodeName = wezel.sciezka;
					wstawiono = Status.Wstawiono;
				}

				licznik++;
			}

			// Nie wstawiono bo musi byc na koncu
			if (wstawiono == Status.NieWstawiono) {
				Node nastepny = NodeReader.readNode(wezel, wezel.ilosc * 2);
				nodeName = find(nastepny, klucz);
				wstawiono = Status.WstawionoRekurencyjnie;
			}
		}
		return nodeName;
	}

	public void split(Node wezel) {
		if (wezel.ilosc > wartoscNormalna) {
			int splitPos = wezel.ilosc / 2;
			Node n = new Node(NodeReader.dajNowaDziwneNazwe());
			while (wezel.ilosc > splitPos) {
				String data = wezel.dane.get(splitPos * 2);
				wezel.dane.remove(splitPos * 2);
				n.dane.add(data);
			}
		}
	}

	public void join(Node wezelA, Node wezelB) {

	}

	public void insert(String klucz) {
		insert(rootWezel, klucz);
	}

	private void insert(Node wezel, String klucz) {
		Status wstawiono = Status.NieWstawiono;
		if (wezel.ilosc == 0) {
			NodeReader.insertKey(wezel, 0, klucz);
		} else { // TODO: Zaimplementowac balansowanie trzewa poprzez podzial
					// wezla
			int licznik = 0;
			while (licznik < wezel.ilosc && wstawiono == Status.NieWstawiono) {

				if (wezel.dane.get(licznik * 2 + 1).compareTo(klucz) > 0) {
					if (wezel.ilosc < wartoscNormalna) {
						NodeReader.insertKey(wezel, licznik, klucz);
						wstawiono = Status.Wstawiono;
					} else {
						Node nastepny = NodeReader.readNode(wezel, licznik * 2);
						insert(nastepny, klucz);
						wstawiono = Status.WstawionoRekurencyjnie;
					}
				}

				licznik++;
			}

			if (wstawiono == Status.NieWstawiono) { // Nie wstawiono bo musi byc
													// na koncu
				if (wezel.ilosc < wartoscNormalna) {
					NodeReader.insertKey(wezel, wezel.ilosc, klucz);
					wstawiono = Status.Wstawiono;
				} else {
					Node nastepny = NodeReader.readNode(wezel, wezel.ilosc * 2);
					insert(nastepny, klucz);
					wstawiono = Status.WstawionoRekurencyjnie;
				}
			}
		}
	}

	public void delete(String klucz) {
		delete(this.rootWezel, klucz);
	}

	private void delete(Node wezel, String klucz) {

	}

	public void print() {
		this.rootWezel.print(0);
	}
}
