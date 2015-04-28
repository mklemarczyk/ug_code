package btree;

import java.util.LinkedList;

public class Node {
	public String sciezka;
	// Przykład listy w C: 
	// https://github.com/mklemarczyk/ug_code/tree/master/C/jezyki_prog/zad-09
	public LinkedList<String> dane;
	public int ilosc;

	public Node(String sciezka) {
		this.sciezka = sciezka;
		this.dane = new LinkedList<String>();
		this.ilosc = 0;
	}
}
