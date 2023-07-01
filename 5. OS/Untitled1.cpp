#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define m 15
sem_t barberchair;
sem_t barberpillow;
sem_t seatbelt;
sem_t waitingroom;
int nu[m];
int allDone = 0;
void *barber(void *junk){
	while(!allDone){
		printf("Barber is sleeping.");
		sem_wait(&barberpillow);
		if(!allDone){
			printf("barber cutting hair.");
			sleep(3);
			sem_post(&seatbelt);
			printf("Finished cutting hair");
		}else{
			printf("barber going home for today");
		}
	}
}
void *customer(void *num){
	int no = *(int *)num;
	printf("Customer leaving for barber shop.");
	sleep(3);
	printf("Customer arrived at barber shop.");
	sem_wait(&waitingroom);
	printf("Customer arrived in waiting room.");
	sem_wait(&barberchair);
	sem_post(&waitingroom);
	printf("Customer waking the barber.");
	sem_wait(&seatbelt);
	sem_post(&barberpillow);
	sem_post(&barberchair);
	printf("Customer leaving the barber shop.");
}
int main(int argc,char *argv[]){
	pthread_t btid;
	pthread_t tid[m];
    long RandSeed;
	int numch,numcu,i;
	printf("\nEnter no of chairs: ");
	scanf("%d",&numch);
	printf("\nEnter no of cust: ");
	scanf("%d",&numcu);
	if(numcu>m){
		printf("error");
		exit(-1);
	}
	for(i=0;i<m;i++){
		nu[i]=i;
	}
	sem_init(&barberchair,0,1);
	sem_init(&barberpillow,0,0);
	sem_init(&seatbelt,0,0);
	sem_init(&waitingroom,0,numch);
	pthread_create(&btid,NULL,barber,NULL);
	for(i = 0;i<numcu;i++){
		pthread_create(&tid[i],NULL,customer,(void *)&nu[i]);
	}
	for(i = 0;i<numcu;i++){
		pthread_join(tid[i],NULL);
	}
	allDone = 1;
	sem_post(&barberpillow);
	pthread_join(btid,NULL);
	return 0;
}
