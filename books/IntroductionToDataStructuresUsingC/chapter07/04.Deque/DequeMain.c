#include <stdio.h>
#include "Deque.h"

int main(){
    /** Deque Structor */
    Deque deq;
    /** Deque Init */
    DequeInit(&deq);

    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    while(!DQIsEmpty(&deq)){
        printf("%2d ", DQRemoveFirst(&deq));
    }
    printf("\r\n");

    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    while(!DQIsEmpty(&deq)){
        printf("%2d ", DQRemoveLast(&deq));
    }
    printf("\r\n ");
    return 0;
}