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

char x[50][6] = {"Hello" , "Bello" , "Mello" , "Yello" , "Tello" , "Fello" , "Gello" ,"Cripe" , "Crepe","Frape" , "Latte" , "Mbape" , "Messi" , "Rondo" , "Rooni" , "Mooni" , "Honey" , "Bunny" ,"Hello" , "Bello" , "Mello" , "Yello", "Mello" , "Yello" , "Tello" , "Fello" , "Gello" , "Hello" , "Bello" , "Mello" , "Yello" , "Tello" , "Fello" , "Gello" ,"Cripe" , "Crepe","Frape" , "Latte" , "Mbape" , "Messi" , "Rondo" , "Rooni" , "Mooni" , "Honey" , "Bunny" ,"Hello" , "Bello" , "Mello" , "Yello", "Mello" , "Yello" , "Tello" , "Fello"}; 
int dex = 0; 
char sendString[50];

char *strrev(char *str){
    char c, *front, *back;

    if(!str || !*str)
        return str; 
    for(front=str,back=str+strlen(str)-1;front < back;front++,back--){
        c=*front;*front=*back;*back=c;
    }
    return str;
}  

void join0(){
	strcpy(sendString , x[dex]) ;
	int ID = dex; 
	char ID1[3]=""; 
	if(ID==0){
		strcat(ID1, "0");
		strcat(sendString , ID1); 
		strcat(sendString , " "); 
	}
	else{
		while(ID!=0){
		int n = ID%10; 
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
		ID/=10; 
	} 
	strrev(ID1);
	strcat(sendString , ID1); 
	strcat(sendString , " "); 
	}
}
void join1(){
	strcat(sendString , x[dex+1]); 
	int ID = dex+1; 
	char ID1[3]=""; 
	while(ID!=0){
		int n = ID%10; 
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
		ID/=10; 
	} 
	strrev(ID1);
	strcat(sendString , ID1); 
	strcat(sendString , " "); 

}
void join2(){
	strcat(sendString , x[dex+2]); 
	int ID = dex+2; 
	char ID1[3]=""; 
	while(ID!=0){
		int n = ID%10; 
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
		ID/=10; 
	} 
	strrev(ID1);
	strcat(sendString , ID1); 
	strcat(sendString , " "); 

}
void join3(){
	strcat(sendString , x[dex+3]);  
	int ID = dex+3; 
	char ID1[3]=""; 
	while(ID!=0){
		int n = ID%10; 
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
		ID/=10; 
	} 
	strrev(ID1);
	strcat(sendString , ID1);
	strcat(sendString , " ");  
}
void join4(){
	strcat(sendString , x[dex+4]);   
	int ID = dex+4; 
	char ID1[3]=""; 
	while(ID!=0){
		int n = ID%10; 
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
		ID/=10; 
	} 
	strrev(ID1);
	strcat(sendString , ID1); 
	strcat(sendString , " "); 
}

int main(int argc , char* argv[]){
	int i = shmget(101 , 1000 , IPC_CREAT|0777); 
	char* ptr = shmat(i , NULL , 0777); 
	dex = atoi(ptr); 
	printf("HIGHEST ID RECEIVED: %d\n", dex);
	dex = dex+1; 
	printf("INDEX TO BEGIN FROM: %d\n" , dex);
	join0();
	join1();  
	join2();  
	join3();  
	join4();   
	printf("STRINGS SENT: %s\n", sendString);
	sprintf(ptr , sendString);
	char *args[] = {NULL , NULL , NULL , NULL}; 
    execv("./p2" , args);
	return 0; 
}
