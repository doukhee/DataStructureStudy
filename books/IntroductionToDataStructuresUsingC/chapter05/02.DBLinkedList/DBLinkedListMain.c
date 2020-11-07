/**
 * 양방향 연결 리스트 구현
 * 
 */

#include <stdio.h>
#include "DBLinkedList.h"


int main(void){
    List list;
    int data;
    /** 리스트 초기화 */
    ListInit(&list);
    /** 리스트에 데이터 삽입 */
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);

    /** 마지막에 넣은 것 부터 나온다 */
    if(LFirst(&list, &data)){
        printf("%d ", data);
        /** 다음 노드로 이동 */
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
        printf("\r\n");
        /** 전 노드로 이동 */
        while(LPrevious(&list, &data)){
            printf("%d ", data);
        }
        printf("\r\n");
    }
    
    return 0;
}