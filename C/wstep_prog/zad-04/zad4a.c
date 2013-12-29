#include <stdio.h> 

void main(){
	float x; /* deklaracja zmiennej i czyli nazwa typu zmiennej oraz jej nazwa*/
	float y;
	y = 17;
	x = 6.5;   /*przypisanie, inaczej nadanie wartosci 6 zmiennej x */
	printf("poczatkowa wartosc x: %f\n",x);
	printf("poczatkowa wartosc y: %f\n",y);
	x = x + 1;  /* zwiekszenie, inaczej inkrementacja (o 1) zmiennej x */
	y -= 2;
	printf("po inkrementacji x o 1: %f\n",x);
	printf("po odjęciu od y 2: %f\n",y);
	x = 2*x; /*mnozenie przez 2 */
	y /= 3;
	printf("po pomnożeniu x przez 2: %f\n",x);
	printf("po podzieleniu y przez 3: %f\n",y);
	x = x/3;
	y += 1;
	printf("po podzieleniu x przez 3: %f\n",x);
	printf("po zawiększeniu y o 1: %f\n",y);
	y *= 2;
	printf("po pomnożeniu y przez 2: %f\n",y);
}
