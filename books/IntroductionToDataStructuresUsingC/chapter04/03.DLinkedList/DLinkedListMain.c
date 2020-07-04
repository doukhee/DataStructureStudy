#include <stdio.h>
#include "DLinkedList.h"

int main(void){
    List list;
    int data;
    ListInit(&list);

    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    printf("현재 데이터 수 : %d \r\n", LCount(&list));

    if(LFirst(&list, &data)){
        printf("%d ", data);
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }
    printf("\r\n");

    if(LFirst(&list, &data)){
        if(data == 22){
            LRemove(&list);
        }
        while(LNext(&list, &data)){
            if(data == 22){
                LRemove(&list);
            }
        }
    }

    printf("\r\n");
    printf("현재 데이터의 수 : %d \r\n", LCount(&list));

    if(LFirst(&list, &data)){
        printf("%d ", data);
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }
    printf("\r\n");
    return 0;
}