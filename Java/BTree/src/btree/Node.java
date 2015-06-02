package btree;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.LinkedList;

public class Node {
	public String sciezka;
	// Przykład listy w C:
	// https://github.com/mklemarczyk/ug_code/tree/master/C/jezyki_prog/zad-09
	public LinkedList<String> dane;
	public int ilosc;
	public Node parent;

	public Node(String sciezka) {
		this.sciezka = sciezka;
		this.dane = new LinkedList<String>();
		this.ilosc = 0;
	}

	public void save() {
		try (BufferedWriter br = new BufferedWriter(new FileWriter(this.sciezka, false))) {
			for (int licznik = 0, ile = this.dane.size(); licznik < ile; licznik++) {
				br.write(this.dane.get(licznik));
				br.newLine();
			}
			br.flush();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void print(int level) {
		if(this.dane.size() > 0)
			System.out.println(this.sciezka);
		level++;
		String prefix = "";
		for (int i = 0; i < level; i++)
			prefix += '-';
		for (int i = 0, c = this.dane.size(); i < c; i++) {
			if (i % 2 == 0)
				NodeReader.readNode(NodeReader.dajSciezke(this.dane.get(i))).print(level);
			else{
				System.out.print(prefix);
				System.out.println(this.dane.get(i));
			}
		}
	}
}
