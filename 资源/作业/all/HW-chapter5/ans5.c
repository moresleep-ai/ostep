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
        int w = wait();
        printf("wait = %d\n",w);
    
    }else{
        int pid = getpid();
        printf("father pid:%d\n",pid);
        int w = wait();
        printf("wait = %d\n",w);
    }
    return 0;
}