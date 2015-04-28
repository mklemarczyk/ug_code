package btree;

import java.io.File;
import java.io.IOException;

public class Main {

	public static void main(String[] args) {
		Main kod = new Main();

		Node rootWezel = NodeReader.readNode(NodeReader.dajSciezkeRoot());

		// F,S,Q,K,C,L,H,T,V,W,M,R,N,P,A,B,X,Y,D,Z,E.
		kod.wstaw(rootWezel, "F");
		kod.wstaw(rootWezel, "S");
		kod.wstaw(rootWezel, "Q");
		kod.wstaw(rootWezel, "K");
		kod.wstaw(rootWezel, "C");
		kod.wstaw(rootWezel, "L");
		kod.wstaw(rootWezel, "H");
		kod.wstaw(rootWezel, "T");
		kod.wstaw(rootWezel, "V");
		kod.wstaw(rootWezel, "W");
		kod.wstaw(rootWezel, "M");
		kod.wstaw(rootWezel, "R");
		kod.wstaw(rootWezel, "N");
		kod.wstaw(rootWezel, "P");
		kod.wstaw(rootWezel, "A");
		kod.wstaw(rootWezel, "B");
		kod.wstaw(rootWezel, "X");
		kod.wstaw(rootWezel, "Y");
		kod.wstaw(rootWezel, "D");
		kod.wstaw(rootWezel, "Z");
		kod.wstaw(rootWezel, "E");

	}

	public Main() {
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
	}

	int wartoscNormalna = 3;

	private void wstaw(Node wezel, String klucz) {
		Status wstawiono = Status.NieWstawiono;
		if (wezel.ilosc == 0) {
			NodeReader.indertKey(wezel, 0, klucz);
		} else {
			int licznik = 0;
			while (licznik < wezel.ilosc && wstawiono == Status.NieWstawiono) {

				if (wezel.dane.get(licznik * 2 + 1).compareTo(klucz) > 0) {
					if (wezel.ilosc < wartoscNormalna) {
						NodeReader.indertKey(wezel, licznik, klucz);
						wstawiono = Status.Wstawiono;
					} else {
						Node nastepny = NodeReader.readNode(NodeReader
								.dajSciezke(wezel.dane.get(licznik * 2)));
						wstaw(nastepny, klucz);
						wstawiono = Status.WstawionoRekurencyjnie;
					}
				}

				licznik++;
			}

			if (wstawiono == Status.NieWstawiono) { // Nie wstawiono bo musi byc na koncu
				if (wezel.ilosc < wartoscNormalna) {
					NodeReader.indertKey(wezel, wezel.ilosc, klucz);
					wstawiono = Status.Wstawiono;
				} else {
					Node nastepny = NodeReader.readNode(NodeReader
							.dajSciezke(wezel.dane.getLast()));
					wstaw(nastepny, klucz);
					wstawiono = Status.WstawionoRekurencyjnie;
				}
			}
		}

		if (wstawiono == Status.Wstawiono) {
			NodeReader.saveNode(wezel);
		}

	}

}
