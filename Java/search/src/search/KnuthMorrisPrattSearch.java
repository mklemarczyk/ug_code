package search;

import java.util.ArrayList;

public class KnuthMorrisPrattSearch {

	public static ArrayList<Integer> find(String text, String pattern) {
		ArrayList<Integer> found = new ArrayList<Integer>();

		int[] pi = makePrefix(pattern);
		
		int patternLastPos = pattern.length() - 1;
		//TODO: Znaki zapytania
		int q = -1;
		for (int i = 0, c = text.length(); i < c; i++) {
			while (q > -1 && pattern.charAt(q + 1) != text.charAt(i)) {
				q = pi[q];
			}
			if (pattern.charAt(q + 1) == text.charAt(i)) {
				q++;
			}
			if (q == patternLastPos) {
				int startPos = i - patternLastPos;
				found.add(startPos);
				q = pi[q];
			}
		}

		return found;
	}

	private static int[] makePrefix(String pattern) {
		int[] pi = new int[pattern.length()];
		int k = -1;
		pi[0] = k;

		for (int q = 1, c = pattern.length(); q < c; q++) {
			while (k > -1 && pattern.charAt(k + 1) != pattern.charAt(q)) {
				k = pi[k];
			}
			if (pattern.charAt(k + 1) == pattern.charAt(q)) {
				k++;
			}
			pi[q] = k;
		}

		return pi;
	}
}
