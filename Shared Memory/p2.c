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

char *strrev(char *str){
    char c, *front, *back;

    if(!str || !*str)
        return str;
    for(front=str,back=str+strlen(str)-1;front < back;front++,back--){
        c=*front;*front=*back;*back=c;
    }
    return str;
}  

int main(int argc , char* argv[]){
	int i = shmget(101 , 1000 , IPC_CREAT|0777); 
	char* ptr = shmat(i , NULL , 0777); 
	printf("STRINGS RECEIVED:");
	int p = 0; 
	for(; ptr[p]!='\0' ; p++){
		printf("%c", ptr[p]);
	}
	printf("\n");
	int largestID; 
	if(p==35){
		largestID = atoi(&ptr[p-2]); 
	}
	else{
		largestID = atoi(&ptr[p-3]);
	} 
	char sendString[50];
	char ID1[3]=""; 
	while(largestID!=0){
		int n = largestID%10; 
		if(n==0){
			strcat(ID1,"0"); 
		}
		if(n==1){
			strcat(ID1,"1"); 
		}
		if(n==2){
			strcat(ID1,"2"); 
		}
		if(n==3){
			strcat(ID1,"3"); 
		}
		if(n==4){
			strcat(ID1,"4"); 
		}
		if(n==5){
			strcat(ID1,"5"); 
		}
		if(n==6){
			strcat(ID1,"6"); 
		}
		if(n==7){
			strcat(ID1,"7"); 
		}
		if(n==8){
			strcat(ID1,"8"); 
		}
		if(n==9){
			strcat(ID1,"9"); 
		}
		largestID/=10; 
	} 
	strrev(ID1);
	strcat(sendString , ID1); 
	printf("LARGEST ID SENT: %s\n",sendString);
	sprintf(ptr , sendString);
	return 0; 
}