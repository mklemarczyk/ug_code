#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

/****************************************************************/
// DEFINICJA TYPU LICZB ZESPOLONYCH:

typedef struct {
  double rea, ima;
}  zespol;

/****************************************************************/
// POMOCNICZE:

void  err(char s[]) {  // -- sygnalizacja bledu wejscia
  printf("\n !!! FUNKCJA zesp_get: %s !!!\n\n", s);
  exit(1);
}

/****************************************************************/
// INICJALIZACJE oraz WEJSCIE-WYJSCIE:

zespol  zesp_zestawic (double r, double i) {
    // zestawienie liczby zespolonej z dwoch rzeczywistych
  zespol z;
  z.rea = r;  z.ima = i;
  return z;
}

zespol  zesp_get (void) {
    /* wczytanie liczby zespolonej; powinna skladac sie z dwoch
       rzeczywistych, oraz plusa lub minusa miedzy nimi, zaczynac sie od
       nawiasu otwierajacego, konczyc sie litera i oraz nawiasem
       zamykajacym;
       np.  (123.45 + 67.89j)
    */
	char ch;
	zespol z;  int znak_im;
	do { ch = getchar(); } while (isspace(ch));
	if (ch == '(') {
		if (scanf("%lf", &(z.rea)) == 1) {
			do { ch = getchar(); } while (isspace(ch));
			if (ch == '+' || ch == '-') {
				if (ch == '+')  znak_im = 1;
				else  znak_im = -1;
				if (scanf("%lf", &(z.ima)) == 1) {
					do { ch = getchar(); } while (isspace(ch));
					if (ch == 'j') {
						do { ch = getchar(); } while (isspace(ch));
						if (ch == ')') {
							if (znak_im == -1)  z.ima = -z.ima;
						} else err("brak koncowego nawiasu");
					} else err("brak 'j' na koncu czesci urojonej");
				} else err("niepoprawna czesc urojona");
			} else err("po czesci rzeczywistej brak znaku '+' lub '-'");
		} else err("niepoprawna czesc rzeczywista");
	} else err("brak rozpoczynajacego nawiasu");
	return z;
}

void  zesp_print (zespol z) { // drukowanie liczby zespolonej
	if (z.ima >= 0)
		printf("(%.2lf+%.2lfj)", z.rea, z.ima);
	else
		printf("(%.2lf-%.2lfj)", z.rea, -z.ima);
}

/****************************************************************/
// DZIALANIA:

// dodawanie liczb zespolonych
zespol  zesp_dodac (zespol z1, zespol z2){
	zespol result;
	result.rea = z1.rea + z2.rea;
	result.ima = z1.ima + z2.ima;
	return result;
}

// odejmowanie liczb zespolonych
zespol  zesp_odjac (zespol z1, zespol z2){
	zespol result;
	result.rea = z1.rea - z2.rea;
	result.ima = z1.ima - z2.ima;
	return result;
}

// mnozenie liczb zespolonych
zespol  zesp_razy (zespol z1, zespol z2){
	zespol result;
	result.rea = z1.rea * z2.rea - z1.ima * z2.ima;
	result.ima = z1.ima * z2.rea + z1.rea * z2.ima;
	return result;
}

// liczba sprzezona do danej zespolonej
zespol  zesp_sprzez (zespol z){
	zespol result;
	result.rea = z.rea;
	result.ima = -z.ima;
	return result;
}

// modul liczby zespolonej
double  zesp_abs (zespol z){
	double result;
	result = sqrt(z.rea * z.rea + z.ima * z.ima);
	return result;
}

zespol zesp_e(double r){
	zespol result;
	result.rea = cos(r);
	result.ima = sin(r);
	return result;
}

/****************************************************************/


int main () {
	zespol jedynka = {1, 0};
	zespol  z1, z2;
	double r;

	printf("\n z1 == "); z1 = zesp_get();
	printf(" z2 == "); z2 = zesp_get();
	printf(" r == "); scanf("%lf", &r);

	printf("\n z1+z2 == "); zesp_print(zesp_dodac(z1, z2));
	printf("\n z1-z2 == "); zesp_print(zesp_odjac(z1, z2));
	printf("\n z1*z2 == "); zesp_print(zesp_razy(z1, z2));
	printf("\n |z1+z2| == %.4lf", zesp_abs(zesp_dodac(z1, z2)));

	zespol te = zesp_dodac(zesp_e(r), jedynka);
	if(te.rea == 1 && te.ima == 1)
		printf("\n Tożsamość Eulera jest prawdziwa.");
	else
		printf("\n Tożsamość Eulera nie jest prawdziwa.");
	printf("\n\n");

	return 0;
}
