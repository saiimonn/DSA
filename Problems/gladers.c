#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int id;
    char name[20];
    int priority;
}Person;

typedef struct {
    Person* person;
    int last;
    int front;
}Queue;

//Functions to be implemented
void initQueue(Queue* q);
void heapify(Queue* q, int n, int i);
void buildHeap(Queue* q, int n);
void delete(Queue* q);
void insert(Queue* q, Person person);
bool isMember(Queue q, int id);
void heapSort(Queue* q, int n);

//Helper
void printHeap(Queue q);

int main(){
    Queue myQueue;
    initQueue(&myQueue);

    Person person[10] = {
        {1001, "Thomas", 1},
        {1002, "Brenda", 2},
        {1003, "Teresa", 5},
        {1004, "Minho", 6},
        {1005, "Harriet", 4},
        {1006, "Aris", 8},
        {1007, "Newt", 9},
        {1008, "Gally", 3},
        {1009, "Alby", 10},
        {1010, "Sonya", 7}
    };

    for(int i = 0; i < MAX; i++){
        insert(&myQueue, person[i]);
    }

    printf("\nOld Queue:\n");
    buildHeap(&myQueue, MAX);
    printHeap(myQueue);

    delete(&myQueue);
    delete(&myQueue);
    delete(&myQueue);

    printf("\nNew Queue:\n");
    printHeap(myQueue);

    int findId = 1005;
    bool state = isMember(myQueue, findId);
    printf("ID %d %s of the queue\n", findId, (state) ? "is part" : "is not part");
    printf("\nAfter Sorting Heap:\n");
    heapSort(&myQueue, myQueue.last + 1);
    printHeap(myQueue);

    free(myQueue.person);
    return 0;
}

void initQueue(Queue* q){
    /*TO BE IMPLEMENTED*/
    q->front = 0;
    q->last = MAX - 1;
    q->person = (Person*)malloc(sizeof(Person) * MAX);
}
void heapify(Queue* q, int n, int i){
    /*TO BE IMPLEMENTED*/
    int largest = i;
    int left = largest * 2 + 1;
    int right = left + 1;

    
}

void buildHeap(Queue* q, int n){
    /*TO BE IMPLEMENTED*/

}

void heapSort(Queue* q, int n) {
    /*TO BE IMPLEMENTED*/
}
void insert(Queue* q, Person person){
    /*TO BE IMPLEMENTED*/
    if((q->last + 2) % MAX != q->front) {
        q->last = (q->last + 1) % MAX;
        q->person[q->last] = person;
    }
}

void delete(Queue* q){
    /*TO BE IMPLEMENTED*/
    if((q->last + 1) % MAX != q->front) {
        q->front = (q->front + 1) % MAX;
    }
}

bool isMember(Queue q, int id){
    bool flag = false;
    int size = (q.last - q.front + MAX + 1) % MAX;
    for(int i = 0; i < size; i++) {
        if(q.person[q.front].id == id) {
            flag = true;
        }
        
        Person deq = q.person[q.front];
        delete(&q);
        insert(&q, deq);
    }
    return flag;
}

void printHeap(Queue q){
    for(int i = 0; i <= q.last; i++){
        printf("Name: %s, ID: %d, Priority: %d\n", q.person[i].name, q.person[i].id, q.person[i].priority);
    }
}