#include <stdio.h>

void main(){
	//Tablice
	int ilosc = 5;
	double liczby1[ilosc];
	double liczby2[ilosc];
	
	//Liczniki programu
	double liczba = 0;
	int i = 0;
	
	//Dane statystyczne
	double wynik = 0;
	
	printf("Liczby pierwszej tablicy:\n");
	for(i=0;i<ilosc;i++){
		scanf("%lf", &liczba);
		liczby1[i] = liczba;
	}
	
	printf("Liczby drugiej tablicy:\n");
	for(i=0;i<ilosc;i++){
		scanf("%lf", &liczba);
		liczby2[i] = liczba;
	}
	
	for(i=0;i<ilosc;i++){
		wynik += liczby1[i]*liczby2[i];
	}
	printf("Iloczyn skalarny: %lf\n", wynik);
}

//2,3,4,5,6 = 90
