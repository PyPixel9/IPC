#include<stdio.h>
#include<strings.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

#define MAX_BUF 1024

int main(int argc , char* argv[]){
		int iteration; 
		FILE *fptr;
	   	fptr = fopen("iteration.txt","r"); 
	   	fscanf(fptr,"%d", &iteration);
	   	fclose(fptr); 
		char arr[51][4] = {
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
		}; 
		mkfifo("text1" , 0777); 
		int fd = open("text1" , O_WRONLY);  
		for(int i = 0+iteration ; i < 5+iteration ; i++){
			char x[3];  
			x[0]=(i/10)%10+'0';
			x[1]=i%10+'0'; 
			x[2]='\0';
			char str[6];
			str[0]=arr[i][0];str[1]=arr[i][1];str[2]=arr[i][2];str[3]=arr[i][3];
			str[4]=x[0]; 
			str[5]=x[1];  		
			write(fd, str , sizeof(str)); 
		}
		close(fd);

		char buf[MAX_BUF];
		mkfifo("text2" , 0777); 
		int fd2 = open("text2" , O_RDONLY); 	
		read(fd2 , buf , MAX_BUF); 
		printf("Max index integer received in P1: %d\n", atoi(buf));
		close(fd2);
	return 0; 
}

