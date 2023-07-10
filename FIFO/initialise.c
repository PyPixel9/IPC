#include<stdio.h>

int main(){
	FILE *ptrA ;
	ptrA = fopen("iteration.txt","w");
	fprintf(ptrA, "%d", -5);
	fclose(ptrA); 
	return 0; 
}
