#include <stdio.h>

int dwumian(int n, int k){
	if(n < k) return 0;
	else if(k == 1) return n;
	else if(k == 0) return 1;
	return dwumian(n-1,k-1) + dwumian(n-1,k);
}

int dwumian2(int n, int k){
	int tab[n+1][n+1];
	int i,j;
	tab[0][0] = 1;
	for(i = 1; i <= n; i++){
		for(j = 0; j < i+1; j++){
			if(j == 0)
				tab[i][j] = 1;
			else if(j == i)
				tab[i][j] = 1;
			else
				tab[i][j] = tab[i-1][j] + tab[i-1][j-1];
		}
	}
	return tab[n][k];
}

void main(){
	int i, x,y;
	
	printf("Podaj n: ");
	scanf("%d", &x);
	
	printf("Podaj k: ");
	scanf("%d", &y);
	
	for(i = 0; i <= y; i++){
		int dwu = dwumian(x,i);
		int dwu2 = dwumian2(x,i);
		
		printf("Wynik %d: %d %d\n", i, dwu, dwu2);
	}
}
