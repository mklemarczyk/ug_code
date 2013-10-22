#include <stdio.h>

void main(){
	int tab[8];

	tab[0] = 5;
	tab[1] = 5;
	tab[2] = 8;
	tab[3] = 7;
	tab[4] = 3;
	tab[5] = 3;
	tab[6] = 9;
	tab[7] = 11;

	int i;
	for(i = 3; i>=0; i--)
		printf("%d\n", tab[i]);
	for(i = 4; i<8; i++)
		printf("%d\n", tab[i]);
}
