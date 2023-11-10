#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    int x=100;
    int rc = fork();
    if(rc<0){ 
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc==0){
        //x=99;
        printf("x in child is:%d and pid is:%d\n",x,getpid());
    }else{
        x=101;
        printf("x in father is:%d and pid is:%d\n",x,getpid());
    }
    return 0;
}