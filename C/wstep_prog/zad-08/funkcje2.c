//Dodawanie
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

//Odejmowanie
void odejmowaie(int tab1[MCOUNT], int tab2[MCOUNT]){
	int i;

	for(i = 0; i<MCOUNT; i++){
		tab1[i] -= tab2[i];
		if(tab1[i] < 0){
			tab1[i+1] -= 1;
			tab1[i] += 10;
		}
	}
}

//Mnozenie
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


//Silnia
void silnia(int tab1[MCOUNT]){
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
