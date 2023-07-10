#include<stdio.h>
#include<strings.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main(){
	for(int i = 0 ; i<10 ; i++){
		int x = fork();
		if(x==0){
			char *args[] = {NULL , NULL , NULL , NULL}; 
			execv("./testfile", args);
		}
		else{

		}
	}
	return 0;
}
