#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    int rc = fork();
    
    if(rc<0){ 
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc==0){
        int pid = getpid();
        printf("child pid:%d\n",pid);
        close(STDOUT_FILENO);
        printf("fc,child\n");
    }else{
        int pid = getpid();
        printf("father pid:%d\n",pid);
    }
    return 0;
}