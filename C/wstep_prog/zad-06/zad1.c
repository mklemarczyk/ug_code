#include <stdio.h>

void main(){
	int max;
	int num;
	int i = 1;
	
	printf("Podaj liczbe: ");
	scanf("%d", &num);
	max = num;
	
	while(i<3){
		
		printf("Podaj liczbe: ");
		scanf("%d", &num);
		if(num>max)
			max=num;

		i++;
	}
	printf("Najwieksza to: %d\n", max);
}
