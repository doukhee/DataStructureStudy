#include <stdio.h>
#include "DLinkedList.h"

int main(void){
    /** LinkedList 구조체 선언 */
    List list;
    /** 구조체의 데이터를 출력하기 위한 변수 */
    int data;
    /** 초기화 */
    ListInit(&list);
    /** 데이터 삽입 */
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);
    /** 현재 총 데이터 갯수 출력 */
    printf("현재 데이터 수 : %d \r\n", LCount(&list));
    /** 처음 위치로 이동 */
    if(LFirst(&list, &data)){
        /** 처음 데이터 출력 */
        printf("%d ", data);
        /** 다음 구조체로 이동 */
        while(LNext(&list, &data)){
            /** 데잍 출력 */
            printf("%d ", data);
        }
    }
    printf("\r\n");
    /** 처음 위치로 이동 */
    if(LFirst(&list, &data)){
        /** 데이터가 22면, 삭제 */
        if(data == 22){
            /** 데이터 구조체 삭제 */
            LRemove(&list);
        }
        /** 다음 구조체로 이동하면서 22 데이터 삭제 */
        while(LNext(&list, &data)){
            if(data == 22){
                /** 데이터 구조체 삭제 */
                LRemove(&list);
            }
        }
    }

    printf("\r\n");
    printf("현재 데이터의 수 : %d \r\n", LCount(&list));
    /** 처음 위치로 이동 */
    if(LFirst(&list, &data)){
        /** 처음 데이터 출력 */
        printf("%d ", data);
        /** 다음 데이터로 이동 */
        while(LNext(&list, &data)){
            /** 데이터 출력 */
            printf("%d ", data);
        }
    }
    printf("\r\n");
    return 0;
}