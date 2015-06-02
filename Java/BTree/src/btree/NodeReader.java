package btree;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class NodeReader {
	public static String nazwaKatalogu = "drzewo";
	public static String nazwaRoot = "root.txt";
	public static String dajSciezkeRoot() {
		// File.separator = "/"	
		return nazwaKatalogu + File.separator + nazwaRoot;
	}

	public static String dajSciezke(String nazwaPliku) {
		return nazwaKatalogu + File.separator + nazwaPliku;
	}

	public static Node readNode(Node node, int pos) {
		Node wezelek = readNode(NodeReader.dajSciezke(node.dane.get(pos)));
		wezelek.parent = node;
		return wezelek;
	}
	
	public static Node readNode(String sciezka) {
		Node wezelek = new Node(sciezka);

		try (BufferedReader br = new BufferedReader(new FileReader(sciezka))) {
			String line = br.readLine();
			int ile = 0;
			while (line != null) {
				wezelek.dane.add(line);
				line = br.readLine();
				ile++;
			}
			wezelek.ilosc = ile / 2;
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return wezelek;
	}

	public static void insertKey(Node wezel, int i, String klucz) {
		if (wezel.ilosc == 0) {
			String node01 = dajNowaDziwneNazwe();
			createFile(dajSciezke(node01));
			wezel.dane.add(node01);
			
			wezel.dane.add(klucz);
			
			String node02 = dajNowaDziwneNazwe();
			createFile(dajSciezke(node02));
			wezel.dane.add(node02);
		} else {
			String node0 = dajNowaDziwneNazwe();
			createFile(dajSciezke(node0));
			wezel.dane.add(i*2, node0);
			wezel.dane.add(i*2 +1, klucz);
		}
		wezel.ilosc++;
		wezel.save();
	}

	protected static String dajNowaDziwneNazwe() {
		String gen = Long.toString(System.currentTimeMillis()) + ".txt";
		while(new File(dajSciezke(gen)).exists()){
			gen = Long.toString(System.currentTimeMillis()) + ".txt";
		}
		return gen;
	}

	protected static void createFile(String sciezka) {
		File plik = new File(sciezka);
		try {
			plik.createNewFile();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
