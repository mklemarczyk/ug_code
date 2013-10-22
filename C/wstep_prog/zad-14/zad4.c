#include <stdio.h>

void main(){
	int liczba = 0;
	int i;

	int k = 12;
	int tab[k];

	tab[0] = 1;
	tab[1] = 0;
	tab[2] = 1;
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = 1;
	tab[6] = 0;
	tab[7] = 0;
	
	tab[8] = 0;
	tab[9] = 0;
	tab[10] = 0;
	tab[11] = 1;

	for(i = k-1; i >= 0; i--){
		liczba = (liczba * 2 + tab[i]);
		if(i == k-1 && tab[i] == 1)
			liczba = -liczba;
	}

	printf("Liczba: %d", liczba);
	printf("\n");
}
