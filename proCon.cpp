#include<iostream>
#include<thread>
#include<semaphore.h>
using namespace std;

const int buffer_size = 5;
//setting the size of the buffer//

int buffer[buffer_size]={0};
//setting all the elements of buffer to 0//

sem_t mutex,empty,full;
//declaring semaphores//

const int max_items=10;
//declaring the maximum number of items that can be produced or consumed//

int num_produced=0;
//number of items produced//

int num_consumed=0;
//number of items consumed//

//producer function: //
void producer(){
    int item=1;

    while(num_produced<max_items){
        sem_wait(&empty);
        //wait for an empty slot in the buffer//
        
        sem_wait(&mutex);
        //provides mutual exclusion to the bufffer//
        
        buffer[(item-1)%buffer_size]=item;
        //produce an item and add it to the buffer//
        //if you trace it.. it adds the item from top-down//

        cout<<"Producer produced item: "<<item<<endl;
        //mentioning what items has been produced//

        item++;
        //incrementing the value of item//

        num_produced++;
        //incrementing the value of number of items produced//

        sem_post(&mutex);
        //releasing the mutual exclusion//

        sem_post(&full);
        //signanling that the the buffer slot is full//
        
    }


}

void consumer(){

    while(num_consumed<max_items){

        sem_wait(&full);
        //wait for the buffer to have an item i.e be full//
        
        sem_wait(&mutex);
        //provide mutual exclusion to the buffer so that the item can be consumed//

        int item=buffer[0];
        //declare an item from the buffer//

        for(int i=1;i<buffer_size;i++){
            buffer[i-1]=buffer[i];
        }
        //removing the bottom most item from the buffer//
        //assume the buffer to be like a pile of clothes and you take out the bottom-most cloth//

        buffer[buffer_size-1]=0;
        //showing that top most spot in the buffer is now an empty slot since all items shifted one place down//

        cout<<"Item consumed: "<<item<<endl;
        //printing what item has been consumed//

        num_consumed++;
        //updating the number of consumed items//

        sem_post(&mutex);
        //releasing the mutual exclusion//

        sem_post(&empty);
        //signanling that there is am empty slot in the buffer//
        
    }
}

int main(){
    
    sem_init(&mutex,0,1);
    //declaring the semaphore//
    //first parameter is pointer to the semaphore//
    //the second parameter is a flag 0:Cannot be shared between processes non-zero:can be shared between processes//
    
    sem_init(&full,0,0);

    sem_init(&empty,0,buffer_size);

    thread producerThread(producer);
    thread consumerThread(consumer);
    //declaring respective producer and consumer threads//

    producerThread.join();
    consumerThread.join();
    //wait for main thread to execute first so that the other two threads do not start executing without any values//

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    //destroying the semaphores//

    return 0;
}

