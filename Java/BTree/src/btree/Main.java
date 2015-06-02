package btree;

public class Main {

	public static void main(String[] args) {
		Tree drzewo = new Tree(3);

		// F,S,Q,K,C,L,H,T,V,W,M,R,N,P,A,B,X,Y,D,Z,E.
		drzewo.insert("F");
		drzewo.insert("S");
		drzewo.insert("Q");
		drzewo.insert("K");
		drzewo.insert("C");
		drzewo.insert("L");
		drzewo.insert("H");
		drzewo.insert("T");
		drzewo.insert("V");
		drzewo.insert("W");
		drzewo.insert("M");
		drzewo.insert("R");
		drzewo.insert("N");
		drzewo.insert("P");
		drzewo.insert("A");
		drzewo.insert("B");
		drzewo.insert("X");
		drzewo.insert("Y");
		drzewo.insert("D");
		drzewo.insert("Z");
		drzewo.insert("E");
		
		System.out.println(drzewo.find("Z"));
		
		drzewo.print();

	}
}
