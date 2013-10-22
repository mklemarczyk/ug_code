#include <stdio.h>

void main(){
	//Tablice
	int ilosc = 5;
	double liczby[ilosc];
	
	//Liczniki programu
	double liczba = 0;
	int i = 0;
	
	//Dane statystyczne
	int iloscd = 0;
	int iloscz = 0;
	int iloscu = 0;
	
	for(i=0;i<ilosc;i++){
		scanf("%lf", &liczba);
		liczby[i] = liczba;
		if(liczba>0)
			iloscd++; //iloscd = iloscd + 1;
		else
			if(liczba<0)
				iloscu++;
			else
				iloscz++;
	}
	printf("Liczb dodatnich: %d, ujemnych: %d, zer: %d\nLiczby:\n",iloscd,iloscu,iloscz);
	for(i=0;i<ilosc;i++){
		printf("%lf\n", liczby[i]);
	}
}
