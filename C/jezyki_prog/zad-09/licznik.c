#include "licznik.h"

void policz(int drukowac){
	static int ilosc;
	if(drukowac == 0){
		ilosc++;
	}else{
		printf("Liczba wywolan: %i\n", ilosc);
	}
}
