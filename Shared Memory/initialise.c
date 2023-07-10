#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<limits.h>
#include<pthread.h>
#include <string.h> 


int main(){
	int i = shmget(101 , 1000 , IPC_CREAT|0777); 
	char* ptr = shmat(i , NULL , 0777);
	sprintf(ptr , "-1");
	char *args[] = {NULL , NULL , NULL , NULL};
	for(int i = 0 ; i<10 ; i++){
		printf("ITERATION: %d\n" , i+1);
		int x = fork();
		if(x==0){
	    	execv("./p1" , args);
		}
		else{
			wait(NULL); 
		}
		printf("\n");
	}
	return 0; 
}