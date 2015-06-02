package search;

import java.util.ArrayList;

public class NaiveSearch {

	public static ArrayList<Integer> find(String text, String pattern) {
		ArrayList<Integer> found = new ArrayList<Integer>();

		if (pattern == null || pattern.length() == 0) {
			return found;
		}

		int patternLastPos = pattern.length() - 1;
		MatchState state = MatchState.Not;
		int matchStartPos = 0;
		int patternPos = 0;
		for (int i = 0, c = text.length(); i < c; i++) {
			switch (state) {
				case Begin: {
					if (patternPos <= patternLastPos) {
						char patternChar = pattern.charAt(patternPos);
						if (patternChar != '?' && text.charAt(i) != patternChar) {
							state = MatchState.Break;
						} else {
							patternPos++;
						}
					}
					break;
				}
				case Break: {
					i = matchStartPos;
					state = MatchState.Not;
					break;
				}
				default: {
					if (text.charAt(i) == pattern.charAt(0)) {
						matchStartPos = i;
						patternPos = 1;
						state = MatchState.Begin;
					}
					break;
				}
			}
			if (patternPos > patternLastPos && state != MatchState.Not) {
				state = MatchState.Break;
				found.add(matchStartPos);
			}
		}

		return found;
	}

}
