#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define SIZE 512

char buffer[SIZE];

void *funcT1(void *arg){

}

void *funcT2(void *arg){
    
}

int main(){
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1,NULL,funcT1,NULL);
    pthread_create(&t2,NULL,funcT2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
}