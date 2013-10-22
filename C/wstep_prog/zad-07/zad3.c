#include <stdio.h>

void main(){
	//Tablice
	int ilosc = 5;
	double liczba1[ilosc];
	double liczba2[ilosc];
	
	//Liczniki programu
	double cyfra = 0;
	int i = 0;
	
	//Dane statystyczne
	int wynik = 0;
	
	printf("Liczba piersza:\n");
	for(i=0;i<ilosc;i++){
		scanf("%1lf", &cyfra);
		liczba1[i] = cyfra;
	}
	
	printf("Liczba druga:\n");
	for(i=0;i<ilosc;i++){
		scanf("%1lf", &cyfra);
		liczba2[i] = cyfra;
	}
	
	for(i=0;i<ilosc&&wynik==0;i++){
		if(liczba1[i]!=liczba2[i])
			if(liczba1[i]<liczba2[i])
				wynik=1;
			else
				wynik=2;
	}

	if(wynik == 0)
		printf("Liczby sa takie same!");
	else
		printf("Pierwsza liczba wg leksygonograficznego: %d\n",wynik);
}
