#include <stdio.h>

int bit_liczby(int numer, int liczba){
	int poz = 1;
	int n = numer -1;
	int i;
	if(numer > 0){
		poz = poz << n;
		if((liczba & poz) == poz)
			return 1;
		else
			return 0;
	}else
		return 0;
}

void main(){
	int liczba = 5;
	int i;

	printf("Liczba %d = ", liczba);

	for(i = sizeof(liczba) * 8; i > 0; i--){
		printf("%d", bit_liczby(i, liczba));
		if((i-1) % 8 == 0)
			printf(" ");
	}
	printf("\n");
}
