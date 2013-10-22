#include <stdio.h>

int dwumian(int n, int k){
	if(n < k) return 0;
	else if(k == 1) return n;
	else if(k == 0) return 1;
	return dwumian(n-1,k-1) + dwumian(n-1,k);
}

void main(){
	int i, x,y;
	
	printf("Podaj n: ");
	scanf("%d", &x);
	
	printf("Podaj k: ");
	scanf("%d", &y);
	
	for(i = 0; i <= y; i++){
		int dwu = dwumian(x,i);
		
		printf("Wynik %d: %d\n", i, dwu);
	}
}
