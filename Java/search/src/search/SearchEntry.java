package search;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class SearchEntry {

	public static void main(String[] args) {
		String text, pattern;

		text = readFile("text.txt");
		pattern = readFile("wzorzec.txt");
		
		System.out.println("NaiveSearch");
		startTimer();
		System.out.println(NaiveSearch.find(text, pattern));
		printTimer();

		System.out.println("\nRabinKarpSearch");
		startTimer();
		System.out
				.println(RabinKarpSearch
						.find("ababaababaababaababaababaababaaebabQW[];',./ERTYUIOPASDFGHJKLZXCVBNMaabawseqwertyuiopasdfghjklbadbcaxcvbnmbfghijklmnoprzxcvsdfsbabcatuwyzaabacbcababaabazxcvbadababaababaababaabcabaababaababaababaababaababa",
								"aabab"));
		printTimer();

		System.out.println("\nRabinKarpSearch");
		startTimer();
		System.out.println(RabinKarpSearch.find(text, pattern));
		printTimer();

		System.out.println("\nKnuthMorrisPrattSearch");
		startTimer();
		System.out.println(KnuthMorrisPrattSearch.find(text, pattern));
		printTimer();

		System.out.println("\nAutoSearch");
		startTimer();
		System.out.println(AutoSearch.find(text, pattern));
		printTimer();
	}

	private static long timer;

	private static void startTimer() {
		long time = System.currentTimeMillis();
		timer = time;
	}

	private static void printTimer() {
		long time = System.currentTimeMillis();
		System.out.print("Time: ");
		System.out.print(time - timer);
		System.out.println("ms");
	}

	// / Odczyt grafu z listy sasiedztwa
	private static String readFile(String fileName) {
		String text = "";

		try {
			List<String> lines = Files.readAllLines(Paths.get(fileName), Charset.forName("UTF-8"));

			for (String line : lines) {
				text += line;
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		return text;
	}
}
