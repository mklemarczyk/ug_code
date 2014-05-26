//B
#define MAX(A1,B1) (A1 > B1) ? (A1) : (B1)

//C
#define MAX3(A1,B1,C1) ((A1 > B1) && (A1 > C1)) ? (A1) : ((B1 > C1) ? (B1) : (C1))

//D
#define SUM(A1, B1) A1+B1

//E
#define SIZE(TAB) sizeof(TAB) / sizeof(TAB[0])

#define DEBUG

//A
#ifdef DEBUG
int main(){
	
	long tab[13];
	
	int a = SUM(2*5,2*5);
	
	printf("%i\n", a);
	
	printf("%i\n", SIZE(tab));
	
	return 0;
}
#endif

/*
Zad A weź dowolny program i spraw aby część kodu
działała tylko gdy jest zdefiniowane puste makro DEBUG
(użyj komendy #ifdef)
Zad B za pomocą znaku ? zdefiniuj makro MAX(a,b) obliczające
max 2 liczb, bez użycia #if i#elif
Zad C z pomocą #if i #else napisz makro MAKS3(a,b,c), które
oblicza maksimum z 3 liczb
Zad D wywołaj błąd obliczenia dla makra SUM a + b
gdy zostanie wywołane przy mnożeniu, popraw to makro
Zad E Za pomocą funkcji sizeof napisz makro SIZE(tab) które
oblicza długość tablicy mając za argument tylko jej nazwę
*/
