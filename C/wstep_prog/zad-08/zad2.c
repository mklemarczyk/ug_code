#include <stdio.h>
#define MCOUNT 32

void dodawanie(int tab1[MCOUNT], int tab2[MCOUNT]){
	int i;
	
	for(i = 0; i<MCOUNT; i++){
		tab1[i] += tab2[i];
		if(tab1[i] / 10 > 0){
			tab1[i+1] += 1;
			tab1[i] = tab1[i] % 10;
		}
	}
}

void mozenie(int tab1[MCOUNT], int tab2[MCOUNT]){
	int i,j,p,tmp,przen;
	int wyn[MCOUNT]={0,};
	
	for(i = 0; i<MCOUNT; i++){
		for(j = 0; j<MCOUNT; j++){
			tmp = tab1[i]*tab2[j];
			przen = 0;
			if(tmp>9){
				przen = tmp/10;
				tmp %= 10;
			}
			p=i+j;
			wyn[p]+=tmp;
			wyn[p+1]+=przen;
			while(wyn[p]>9 && p<MCOUNT){
				wyn[p+1] += wyn[p]/10;
				wyn[p] %= 10;
				p++;
			}
		}
	}
	for(i = 0; i<MCOUNT; i++){
		tab1[i] = wyn[i];
	}
}

void silnia(int tab1[MCOUNT]){
	int i,j;
	int tab[MCOUNT]={1,0,};
	int wyn[MCOUNT]={1,};
	int jeden[MCOUNT]={1,0,};

	while(porownanie(tab, tab1) < 0 ){
		mozenie(wyn, tab);
		dodawanie(tab, jeden);
	}
	mozenie(wyn, tab);
	for(i = 0; i<MCOUNT; i++){
		tab1[i] = wyn[i];
	}
}

int porownanie(int tab1[MCOUNT], int tab2[MCOUNT]){
	int tabt1[MCOUNT] = {0,};
	int tabt2[MCOUNT] = {0,};
	int wyn = 0;
	int i,j,tmpi;

	for(i = 0; i<MCOUNT; i++){
		tabt1[i] = tab1[i];
		tabt2[i] = tab2[i];
	}
	for(j = 0; j<i/2 && j<MCOUNT; j++){
		tmpi = tabt1[j];
		tabt1[j] = tabt1[i-j-1];
		tabt1[i-j-1] = tmpi;

		tmpi = tabt2[j];
		tabt2[j] = tabt2[i-j-1];
		tabt2[i-j-1] = tmpi;
	}

	for(i = 0; i<MCOUNT; i++){
		if(tabt1[i] != tabt2[i]){
			if(tabt1[i] < tabt2[i])
				return -1;
			else if(tabt1[i] > tabt2[i])
				return 1;
		}
	}
}

void main(){
	int tabl[MCOUNT] = {0, };
	int tabr[MCOUNT] = {0, };
	
	int i;
	int j;
	char tmp;
	int tmpi;

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

//mozenie(tabl, tabr);
silnia(tabl);

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
