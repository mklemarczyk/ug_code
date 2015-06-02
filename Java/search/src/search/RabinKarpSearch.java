package search;

import java.util.ArrayList;

public class RabinKarpSearch {

	public static ArrayList<Integer> find(String text, String pattern) {
		ArrayList<Integer> found = new ArrayList<Integer>();

		if (text == null || pattern == null) {
			return found;
		}

		int textLength = text.length();
		int patternLength = pattern.length();

		if (pattern.length() == 0 || textLength < patternLength) {
			return found;
		}

		int patternHash = pattern.hashCode();
		String foundBuffer = text.substring(0, patternLength);
		int foundBufferHash = foundBuffer.hashCode();

		int base = 31;

		int i, c = textLength - patternLength + 1;
		for (i = 0; i < c; i++) {
			// foundBuffer = text.substring(i, i + patternLength);//TODO:
			// Skorygować o róźnicę w hashCode między dodanym i usuniętym
			// znakiem
			// foundBufferHash = foundBuffer.hashCode();
			if (foundBufferHash == patternHash) {
				foundBuffer = text.substring(i, i + patternLength);
				//ArrayList<Integer> naiveResult = NaiveSearch.find(foundBuffer, pattern);
				//if (naiveResult != null && naiveResult.size() > 0) {
				//	found.add(i);
				//}
				if(foundBuffer.equals(pattern)){
					found.add(i);
				}
				// int bufferLastPos = buffer.length() - 1;
				// for (int i = 0, c = buffer.length(); i < c && state !=
				// MatchState.Match; i++) {
				// if (buffer.charAt(i) != pattern.charAt(i)) {
				// state = MatchState.Not;
				// } else if (i == bufferLastPos) {
				// state = MatchState.Match;
				// }
				// }
			}
			if (i+1 < c) {
				foundBufferHash = (int)(base * (foundBufferHash - Math.pow(base, patternLength - 1) * text.charAt(i))
						+ text.charAt(i + patternLength));
			}
		}

		return found;
	}
}
