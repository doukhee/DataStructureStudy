#include <stdio.h>
#include "DLinkedList.h"


/** 비교 함수 정의 */
int WhoIsPrecade(int d1, int d2){
    if(d1 < d2){
        return 0;
    }else{
        return 1;
    }
}

int main(int argc, char **argv){
    List list;
    int data;
    ListInit(&list);

    SetSortRule(&list, WhoIsPrecade);

    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    printf("All List in data number : %d \r\n", LCount(&list));

    if(LFirst(&list, &data)){
        printf("%d ", data);
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }

    printf("\r\n\r\n");
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
    printf("All List in data number : %d \r\n", LCount(&list));

    if(LFirst(&list, &data)){
        printf("%d ", data);
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }

    printf("\r\n");
    return 0;
}