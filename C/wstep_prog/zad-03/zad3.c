/*
* Program powołuje zmienną liczba typu rzeczywistego (tj. float)
* przypisuje jej wartość liczby 0.5 oraz wypisuje wartość zmiennej
* liczba na ekranie. PRZYPOMINAM ŻE
* tekst który teraz czytasz, jest zakomentowany
* i nie bedzie interpretowany jako kod programu. Jest to tzw.
* komentarz blokowy w odróżnieniu od komentarza w jednej linii
* ktory uzyskuje sie przez wpisanie dwókrotnie znaku slash.
*/
#include <stdio.h> 
 /*wywołanie biblioteki*/

void main(){
	float liczba; /* deklaracja zmiennej liczba czyli nazwa typu zmiennej oraz jej nazwa*/
	liczba = 0.5; /* nadanie zmiennej liczba wartości 0.5 */

	printf("To jest pierwszy program\n");
	printf("wypisujacy liczbe rzeczywista.\n");
	printf("zwróć uwage na to jak sie to robi w funkcji printf!");
	printf("oto ona: %f",liczba);
}
/*
* Deklaruje się go za pomocą słowa kluczowego float
* Dopuszcza wpisywanie części po kropce liczby
* Wyświetla i pobiera się go funkcjami
* scanf i printf przy użyciu parametru %f
*/
