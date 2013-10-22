#include <stdio.h>

void main(){
	//Tablice
	int iliczb = 5;
	int ilosc = 5;
	double liczby[iliczb][ilosc];
	
	//Liczniki programu
	double cyfra = 0;
	int i = 0;
	int j = 0;

	//Dane statystyczne
	int wynik = 0;

	for(i=0;i<iliczb;i++){
		printf("Liczba %d:\n",i);
		for(j=0;j<ilosc;j++){
			scanf("%1lf", &cyfra);
			liczby[i][j] = cyfra;
		}
	}

	for(i=1; i<iliczb; i++){
		for(j=0; j<ilosc && liczby[i][j]==liczby[wynik][j]; j++){
			//printf("%d, %d, %d\n", wynik, i, j);
		}
		if(liczby[i][j]<liczby[wynik][j])
			wynik=i;
		//printf("--------\n", wynik, i, j);
	}

	if(wynik == 0)
		printf("Liczby sa takie same!");
	else
		printf("Pierwsza liczba wg leksygonograficznego: %d\n",wynik);
}
