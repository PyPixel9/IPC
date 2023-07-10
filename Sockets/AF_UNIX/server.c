#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int ctr =0; 

int main(){
    int received_data; 
    char buffer[500]; 
	struct sockaddr_un name ; 
    unlink("/tmp/S");
	int connect = socket(AF_UNIX , SOCK_STREAM , 0);
	memset(&name, 0, sizeof(struct sockaddr_un));
	name.sun_family = AF_UNIX; 
	strncpy(name.sun_path, "/tmp/S" , sizeof(name.sun_path) - 1);
	bind(connect , (const struct sockaddr *)&name , sizeof(struct sockaddr_un)); 
    listen(connect , 1);
    printf("Waiting for connection request from client...!!\n");
    while(1){
        int result =0;
        int x = accept(connect , NULL , NULL);
        while(1){
            for(int i = 0 ; i<500 ; i++){
                buffer[i]=0; 
            } 
            int r = read(x , buffer , sizeof(buffer)); 
            memcpy(&received_data , buffer , 4); 
            result=received_data;
            ctr++; 
            printf("%c", (char)received_data);
            if(ctr%4==0){
                printf(" , string ID: %d\n" , ctr/4);
            }
            if(received_data == -1){
                ctr --; 
                break; 
            }
        }
        memset(buffer , 0 , sizeof(buffer)); 
        sprintf(buffer , "Highest ID of the 5 strings= %d" , ctr/4); 
        printf("-> Sent highest ID result back to client!\n");
        write(x , buffer , sizeof(buffer)); 
        close(x); 
    } 
	return 0; 
}



