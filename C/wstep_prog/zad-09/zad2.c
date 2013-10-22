#include <stdio.h>

void main(){
	int tab[3][3];
	int i;
	int j;
	int stat[3] = {0,};
	int wynik = 1;

	printf("Podaj dane (3 cyfry, enter): \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%i", &tab[i][j]);
		}
	}

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			switch(tab[j][i]){
				case 1: stat[0]++; break;
				case 2: stat[1]++; break;
				case 3: stat[2]++; break;
			}
		}
		if(stat[0] != 1 || stat[1] != 1 || stat[2] != 1) wynik = 0;
		stat[0]=0;stat[1]=0;stat[2]=0;
	}

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			switch(tab[j][i]){
				case 1: stat[0]++; break;
				case 2: stat[1]++; break;
				case 3: stat[2]++; break;
			}
		}
		if(stat[0] != 1 || stat[1] != 1 || stat[2] != 1) wynik = 0;
		stat[0]=0;stat[1]=0;stat[2]=0;
	}
	if(wynik == 1)
		printf("Maciez jest wpozo!\n");
	else
		printf("Maciez nie jest wpozo!\n");
}
