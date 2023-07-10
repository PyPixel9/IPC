#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>


char arr[51][4] = {
            "aell" , 
            "worl" , 
            "cool" , 
            "fool" , 
            "wool" , 
            "dool" ,
            "hell" , 
            "worl" , 
            "cool" , 
            "fool" , 
            "wool" , 
            "dool" ,
            "hell" , 
            "worl" , 
            "cool" , 
            "fool" , 
            "wool" , 
            "dool" ,
            "hell" , 
            "worl" , 
            "cool" , 
            "fool" , 
            "wool" , 
            "dool" ,
            "hell" , 
            "worl" , 
            "cool" , 
            "fool" , 
            "wool" , 
            "dool" ,
            "hell" , 
            "worl" , 
            "cool" , 
            "fool" , 
            "wool" , 
            "dool" ,
            "dool" ,
            "hell" , 
            "worl" , 
            "cool" , 
           	"hell" , 
            "worl" , 
            "cool" , 
            "fool" , 
            "wool" , 
            "dool" ,
            "hell" , 
            "worl" , 
            "cool" , 
            "fool" , 
            "dool" 
        }; 

int c = 0 ; 
int r = 1 ;
int start = -1; 
int iterator=0; 
int super_iterator=0; 
int main(){
	while(1){
		char buffer[500];
		struct sockaddr_un name ; 
		int x  = socket(AF_UNIX , SOCK_STREAM , 0);
		memset(&name, 0, sizeof(struct sockaddr_un));
		name.sun_family = AF_UNIX; 
		strncpy(name.sun_path,"/tmp/S" , sizeof(name.sun_path) - 1);
		int p = connect(x , (const struct sockaddr*)&name , sizeof(struct sockaddr_un));
		int num; 
		while(1){
			if(super_iterator == 212){
				printf("REACHED END!\n");
				break; 
			}
			super_iterator++; 
			if(iterator<20){
				start = 1; 
				iterator++; 
			}
			else{
				start = -1; 
				iterator = 0; 
			}
			for(int i = 0 ; i<100000000 ; i++){
				continue ; 
			} 
			if(c==4){
				r++;
				c = 0 ; 
			}
			if(start ==-1){
				int stop_msg = -1; 
				write(x , &stop_msg , 4);
				break ; 
			}
			int n = arr[r][c];
			write(x , &n , 4);
			c++; 
		}
		memset(buffer , 0 , 500); 
		read(x , buffer , 500); 
		printf("Received from server: %s\n", buffer);
		close(x); 
	}
	return 0;
}



