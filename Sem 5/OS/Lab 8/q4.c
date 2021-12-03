#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
 
sem_t customer,barber;
pthread_mutex_t seat;
int free1 = 10;

void *barber_(void *args)
{
    while(1)
    {
        // Sleeping
        sem_wait(&customer);
        // customer is here, so locking the seat
        pthread_mutex_lock(&seat);

        if(free1<10)
            free1++;
        sleep(2);

        printf("Cutting completed: free seats: %d\n",free1);
        // Barber is cutting hair
        sem_post(&barber);
        // release the chair
        pthread_mutex_unlock(&seat);
    }
}
 
void *customer_(void *args)
{
    while(1)
    {
        // Locking seat for customer
        pthread_mutex_lock(&seat);

        if(free1 > 0)
        {
            free1--;
            
            printf("Customer waiting: free seats: %d\n",free1);
            // Telling barber a seat is free
            sem_post(&customer);
            // Unlock seat
            pthread_mutex_unlock(&seat);
            // Waiting if barber is busy
            sem_wait(&barber);
        }
        else // no seat empty, customer leaves
            pthread_mutex_unlock(&seat);
    }
}
 
int main()
{
    pthread_t threads[2];
    sem_init(&barber,0,1);
    sem_init(&customer,0,1);
    pthread_mutex_init(&seat,0);
    pthread_create(&threads[0],NULL,barber_,NULL);
    pthread_create(&threads[1],NULL,customer_,NULL);
    pthread_join(threads[0],NULL);
    pthread_join(threads[1],NULL);
    sem_destroy(&barber);
    sem_destroy(&customer);
    pthread_mutex_destroy(&seat);
}

