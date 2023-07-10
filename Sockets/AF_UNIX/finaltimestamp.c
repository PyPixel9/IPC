#include<stdio.h>
#include<time.h>

int main(){
	FILE *fptr;
	fptr = fopen("finaltimestamp.txt","w");
	fprintf(fptr, "%lu" ,clock());
    fclose(fptr);
	return 0; 
}
