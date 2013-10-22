#include <stdio.h>

void main(){
	int tab[4][4];
	int i;
	int j;

	printf("Podaj dane (4 cyfry, enter): ");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			scanf("%1i", &tab[i][j]);
		}
	}

	printf("Wydruk 1: ");
	for(i=0; i<4; i++){
		if(i>0)printf(", ");
		for(j=0; j<4; j++){
			if(j>0)printf(" ");
			printf("%1i", tab[i][j]);
		}
	}
	
	printf("\nWydruk 2: ");
	for(i=0; i<4; i++){
		if(i>0)printf(", ");
		for(j=0; j<4; j++){
			if(j>0)printf(" ");
			printf("%1i", tab[j][i]);
		}
	}
	printf("\n");
}
