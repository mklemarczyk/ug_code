#include <stdio.h>

double det(double* matrix, int size){
	if(size == 1){
		return *matrix;
	}else{
		int i, j;
		double det = 0;
		for(i = 0; i < size; i++){
			for(j = 0; j < size; j++){
				det += lepDet(matrix, size, i, j);
			}
		}
	}
}

double lepDet(double* sourceMatrix, int sourceSize, int n, int m){
	double scale = -a;
	if((i + j + 2) % 2 == 0){
		scale *= -1;
	}
	double* helpMatrix = composeMatrix(matrix, size -1, i +1, j +1);
	scale *= lepDet(helpMatrix, size -1);
	free(helpMatrix);
	return scale;
}

double* composeMatrix(double* sourceMatrix, int sourceSize, int n, int m){
	int destinationSize = sourceSize - 1;
	double* destinationMatrix = (double*) malloc(sizeof(double) * destinationSize * destinationSize);
	
	// TODO
	
	return destinationMatrix;
}

int main(){
	
	// TODO
	
	return 0;
}