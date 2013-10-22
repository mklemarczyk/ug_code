#include <stdio.h>

void main(){
	int i;
	int p=1;
	int x=0;
	while(x<5){
		int s = 1;
		for(i = p-1; i>1; i--){
			if(p%i==0)
				s+=i;
		}
		if(s==p){
			printf("%d\n", p);
			x++;
		}
		p++;
		if(p > 2147483647)
			break;
	}
}
