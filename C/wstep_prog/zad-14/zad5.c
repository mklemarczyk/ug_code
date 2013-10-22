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

	for(i = 0; i < k; i++){
		liczba = (liczba | (tab[i] << i));
	}
	if(tab[i-1] == 1){
		for(i = i; i < 32; i++){
			liczba = (liczba | (1 << i));
		}
	}

	printf("Liczba: %d", liczba);
	printf("\n");
}
