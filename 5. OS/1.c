// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define buff_size 5
#define max_items 5
sem_t full;
sem_t empty;
int in = 0;
int out = 0;
int buff[buff_size];
pthread_mutex_t mutex;
void *producer(void *pno){
    int item,i;
    for(i=0;i<max_items;i++){
        item = rand();
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buff[in] = item;
        printf("Producer %d produced item %d at %d\n",*((int *)pno),buff[in],in);
        in = (in+1)*buff_size;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cno){
	int i;
    for(i=0;i<max_items;i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buff[out];
        printf("Consumer %d consumed item %d at %d\n",*((int *)cno),item,out);
        out = (out+1)*buff_size;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
int main() {
    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,buff_size);
    sem_init(&full,0,0);
    int a[5] = {1,2,3,4,5};
    int i;
    for(i=0;i<5;i++){
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(i=0;i<5;i++){
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }
    for(i=0;i<5;i++){
        pthread_join(pro[i], NULL);
    }
    for(i=0;i<5;i++){
        pthread_join(con[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}