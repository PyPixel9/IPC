#include<stdio.h>
#include<strings.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main(){
	int iteration; 
	FILE *fptr;
   	fptr = fopen("iteration.txt","r"); 
   	fscanf(fptr,"%d", &iteration);
   	fclose(fptr); 
	iteration+=5; 
	FILE *ptrA ;
	ptrA = fopen("iteration.txt","w");
	fprintf(ptrA, "%d ", iteration);
	fclose(ptrA); 

	int x = fork();
	if(x==0){
		char *args[] = {NULL , NULL , NULL , NULL}; 
		execv("./A", args);
	}
	else{
		char *args[] = {NULL , NULL , NULL , NULL};
		execv("./B", args);
	}
	return 0; 
}
