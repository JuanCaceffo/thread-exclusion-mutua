#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define SIZE 512

int shared = 5;
pthread_mutex_t mutex;

void *funcT1(void *arg){
    int i = 0;

    //atomic function
    pthread_mutex_lock(&mutex);
    for(i;i <= 100000;i++){
        shared++;
    }
    printf ("t1:%i\n",shared);
    pthread_mutex_unlock(&mutex);
}

void *funcT2(void *arg){
    int i = 0;
    //atomic function
    pthread_mutex_lock(&mutex);
    for(i;i <= 100000;i++){
        shared--;
    }
    printf ("t2:%i\n",shared);
    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t t1,t2;

    pthread_create(&t1,NULL,funcT1,NULL);
    pthread_create(&t2,NULL,funcT2,NULL);
    //wait for both threads to finish
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("final value: %i\n",shared);
    return(0);
}