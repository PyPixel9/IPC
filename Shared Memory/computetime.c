#include<stdio.h>
#include<time.h>

int main(){
	double start;
	FILE *fptr;
	fptr=fopen("initialtimestamp.txt","r");
	fscanf(fptr,"%lf", &start);
	fclose(fptr);

	double end;
	FILE *fptr2;
	fptr2=fopen("finaltimestamp.txt","r");
	fscanf(fptr2,"%lf", &end);
	fclose(fptr2);

    if(end-start<=0){
        printf("%lf" ,-1*(end-start)/1000000 );
    }
    else{
        printf("%lf" , (end-start)/1000000);
    }
	return 0;
}

