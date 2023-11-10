#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    int rc = fork();
    char *s0 = "/bin/ls";
    char *s1 = "/bin";
    char *s2 = "/";
    if(rc<0){ 
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc==0){
        printf("child:\n");
        execlp(s0,s1,s2,NULL);
    }else{
        printf("father:\n");
        execlp(s0,s1,s2,NULL);
    }
    return 0;
}