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
	char buf[MAX_BUF];
	mkfifo("text1" , 0777); 
	int fd = open("text1" , O_RDONLY); 
	read(fd , buf , MAX_BUF); 
	printf("String received in P2: %s\n",buf);
	close(fd);
	int max=0;
	char max_str[3];
	max_str[2]='\0'; 
	max_str[1]=buf[29]; 
	max_str[0]=buf[28]; 
	max = atoi(max_str);  
	mkfifo("text2" , 0777); 
	int fd2 = open("text2" , O_WRONLY); 
	char x[3]; 
	x[0]=(max/10)%10+'0'; 
	x[1]=max%10+'0'; 
	x[2]='\0';
	write(fd2, x , sizeof(x)); 	
	close(fd2);
	return 0; 
}
