#include <stdio.h>

int fibo(int a){
	if(a<1)
		return 0;
	if(a<=2)
		return 1;
	else
		return fibo(a-1)+fibo(a-2);
}

void main(){
	int a;
	
	printf("Podaj liczbe: ");
	scanf("%i", &a);
	
	printf("Wynik to: %i\n", fibo(a));
}
