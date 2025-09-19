#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;



int main() {
    Queue Q;
    Q.front = 0;
    Q.rear = MAX - 1;
}

void enqueueSortedUnique(Queue *Q, int x) {
    if((Q->rear + 2) % MAX != Q->front) {
        Queue temp = *Q;

        int isUnique = 1;

        while((temp.rear + 1) % MAX != temp.front) {
            if(temp.data[temp.front] == x) {
                isUnique = 0;
            } 

            temp.front = (temp.front + 1) % MAX;
        }

        if(isUnique) {
            int size = (Q->rear - Q->front + MAX + 1) % MAX;
            int inserted = 0;
            int i;

            for(i = 0; i < size; i++) {
                int frontElem = Q->data[Q->front];
                Q->front = (Q->front + 1) % MAX;

                if(!inserted && x < frontElem) {
                    Q->rear = (Q->rear + 1) % MAX;
                    Q->data[Q->rear] = x;
                    inserted = 1;
                }

                Q->rear = (Q->rear + 1) % MAX;
                Q->data[Q->rear] = frontElem;
            }

            if(!inserted) {
                Q->rear = (Q->rear + 1) % MAX;
                Q->data[Q->rear] = x;
            }
        }
    }
}