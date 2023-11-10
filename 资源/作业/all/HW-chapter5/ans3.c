#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    int rc = vfork();
    if(rc<0){ 
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc==0){
       printf("hello\n");
       exit(0);
    }else{
        printf("goodbye\n");
    }
    return 0;
}