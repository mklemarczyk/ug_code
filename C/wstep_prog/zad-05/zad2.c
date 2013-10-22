#include <stdio.h>

void main(){
	int h;
	int a;
	printf("Podaj dlugość podstawy górnej:");
	scanf("%d", &a);
	printf("Podaj wyskość:");
	scanf("%d", &h);

	int i;
	for(i=0; i<h; i++){
		int j;
		for(j=0; j<i+a; j++){
			printf("*");
		}
		printf("\n");
	}
}

/*
 a) napisz program który drukuje trapez prostokatny:

******
*******
********

o parametrach h - wysokość oraz a - długość górnej podstawy.

Wskazówka: podziel trapez na prostokąt h x (a-1) i trójkąt

równoramienny, prostokatny o boku h.

W przykładzie, h = 3, zas a = 6. 
*/
