#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdbool.h>

#define size 5
int buffer[size];

int in = 0;
int out = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void *producer(void *arg){

while(true){
  int item = rand() % 100;
  
  sem_wait(&empty);
  pthread_mutex_lock(&mutex);
  
  buffer[in]=item;
  printf("Produced: %d\n", item);
  in = (in+1) % size;
  
  pthread_mutex_unlock(&mutex);
  sem_post(&full);
  sleep(1);
}
}
void *consumer(void *arg){
while(true){
  sem_wait(&full);
  pthread_mutex_lock(&mutex);
  
  int item = buffer[out];
  printf("Consumed: %d\n", item);
  out = (out+1) % size;
  
  pthread_mutex_unlock(&mutex);
  sem_post(&empty);
  sleep(1);
}
}

int main(){
  pthread_t prodT , consT;
  
  sem_init(&empty , 0 , size);
  sem_init(&full , 0 , 0);
  pthread_mutex_init(&mutex , NULL);
  
  pthread_create(&prodT , NULL , producer , NULL);
  pthread_create(&consT , NULL , consumer , NULL);
  
  pthread_join(prodT , NULL);
  pthread_join(consT , NULL);
  
  return 0;
}
