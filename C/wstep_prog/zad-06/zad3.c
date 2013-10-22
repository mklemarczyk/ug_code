#include <stdio.h>

void main(){
	int tab[50];
	int i = 0;
	int liczba = 1;
	while(liczba > 0){
		printf("Podaj liczbe: ");
		scanf("%d",&liczba);
		if (liczba > 0){
			tab[i]=liczba;
			i++;
		}
	}
	printf("Twoje liczby to: \n");
	for(i = i-1; i>=0; i--){
		printf("%d\n", tab[i]);
	}
}
