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
        //int w = waitpid();
        //printf("wait = %d\n",w);
        exit(0);
    }else{
        int pid = getpid();
        int wstatus;
        printf("father pid:%d\n",pid);
        waitpid(-1,wstatus,0);
        printf("wstatus = %d\n",wstatus);
        
    }
    return 0;
}