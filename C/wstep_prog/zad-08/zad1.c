#include <stdio.h>
#define MCOUNT 32

void dodawanie(int tab1[MCOUNT], int tab2[MCOUNT]){
	int i;
	
	for(i = 0; i<32; i++){
		tab1[i] += tab2[i];
		if(tab1[i] / 10 > 0){
			tab1[i+1] += 1;
			tab1[i] = tab1[i] % 10;
		}
	}
}

void main(){
	int tabl[MCOUNT];
	int tabr[MCOUNT];
	
	int i;
	int j;
	char tmp;
	int tmpi;

//Wyczyszczenie tablic cyfr
	for(i = 0; i<MCOUNT; i++){
		tabl[i] = 0;
		tabr[i] = 0;
	}
	
//Wczytanie cyfr liczby 1
	tmp = ' ';
	i = 0;
	printf("Podaj piersza liczbe: ");
	while((int)tmp != 10 && i<MCOUNT){
		scanf("%c", &tmp);
		if((int)tmp != 10){
			tabl[i] = (int)tmp-48;
			i++;
		}
	}
//Odwrucenie liczby 1
	for(j = 0; j<i/2; j++){
		tmpi = tabl[j];
		tabl[j] = tabl[i-j-1];
		tabl[i-j-1] = tmpi;
	}

//Wczytanie cyfr liczby 2
	tmp = ' ';
	i = 0;
	printf("Podaj druga liczbe: ");
	while((int)tmp != 10 && i<MCOUNT){
		scanf("%c", &tmp);
		if((int)tmp != 10){
			tabr[i] = (int)tmp-48;
			i++;
		}
	}
//Odwrucenie liczby 2
	for(j = 0; j<i/2 && j<MCOUNT; j++){
		tmpi = tabr[j];
		tabr[j] = tabr[i-j-1];
		tabr[i-j-1] = tmpi;
	}

dodawanie(tabl, tabr);

//Oblicznie długości wyniku
	for(i = MCOUNT -1; i>=0 && tabl[i] == 0; i--);
	i++;

//Odwracanie kolejności liczb
	for(j = 0; j<i/2; j++){
		tmpi = tabl[j];
		tabl[j] = tabl[i-j-1];
		tabl[i-j-1] = tmpi;
	}

//Wyświetlenie wyniku
printf("Wynik: ");
	j = 0;
	while(j<i){
		printf("%d", tabl[j]);
		j++;
	}
printf("\n");
}
