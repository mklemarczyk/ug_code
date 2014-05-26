#include <stdio.h>

int main(){
	int n;
	int wynik = 0;
	
	printf("Podaj liczbe n: ");
	scanf("%i", &n);
	
	for(int i = 1; i<=n; i++){
		int i2 = i * i;
		wynik = wynik + i2;
		printf("%i", i2);
		if(i < n)
			printf(" + ");
	}
	
	printf(" = %i\n", wynik);
	
	return 0;
}
