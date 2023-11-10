#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
    int fd=open("temp",O_RDWR);
    int rc = fork();
    char c[6];
    if(rc<0){ 
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc==0){   
        write(STDOUT_FILENO,"now is child:",14);
        //read(fd,c,4);
        write(fd,"child\n",5);
        printf("\n");
    }else{
        write(STDOUT_FILENO,"now is father:",14);
        //read(fd,c,4);
        write(fd,"father\n",6);
        printf("\n");
    }
    return 0;
}