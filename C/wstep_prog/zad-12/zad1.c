#include<stdio.h>
#define M 5

void funkcja(int tab[M], int w, int n){
	int pom;
	int i;

	for(n=n; n>0; n--){
		for(w=0; w+1<n; w++){
			if (tab[w]< tab[w+1]){
				pom = tab[w+1];
				tab[w+1] = tab[w];
				tab[w]=pom;
			}
		}
	}
	/*if (n>0){
		if (tab[w]< tab[w+1]){
			pom = tab[w+1];
			tab[w+1] = tab[w];
			tab[w]=pom;
		}

		if (w+2 < n)
			funkcja(tab, w+1, n); 
		else{
			funkcja(tab, 0, n-1);
        }
	}*/
}



int main(){
	int tab[M];
	int i;
	int n;
 
	for(i=0; i< M; i=i+1){
		tab[i]=0;
	}

	printf("podaj 5 liczb naturalnych\n");

	for(i=0; i< M; i=i+1){
		scanf("%d",&tab[i]);
	}   

	funkcja(tab,0,M);

	printf("teraz tablica wygląda tak:\n");

	for(i=0; i< M; i=i+1){
		printf("%d ",tab[i]);
	}    

    return 0;
}
