#include <stdio.h>

int silnia(int a){
	if(a<=1)
		return 1;
	else
		return a * silnia(a-1);
}

int main(){
	int a;
	
	printf("Podaj liczbe: ");
	scanf("%i", &a);
	
	printf("Wynik to: %i\n", silnia(a));
	return 0;
}
