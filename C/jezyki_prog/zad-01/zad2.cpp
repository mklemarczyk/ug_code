#include <stdio.h>

const int k = 20;

int main(){
	int wynik = 0;
	int tab[k];

	for(int i = 0; i < k; i++){
		int i2 = i * i;
		wynik = wynik + i2;
		tab[i] = wynik;
	}
	
	return 0;
}
