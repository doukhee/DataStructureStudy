#include <stdio.h>
#include "ArrayList.h"

int main(void){
    /** 리스트 데이터 구조체 변수 선언 */
    List list;
    /** 데이터를 읽어와 저장한 변수 선언 */
    int data;
    /** 리스트 초기화 */
    ListInit(&list);
    /** 리스트에 11 값 저장 */
    LInsert(&list, 11);
    /** 리스트에 11 값 저장 */
    LInsert(&list, 11);
    /** 리스트에 22 값 저장 */
    LInsert(&list, 22);
    /** 리스트에 22 값 저장 */
    LInsert(&list, 22);
    /** 리스트에 3 값 저장 */
    LInsert(&list, 3);

    printf("현재 데이터의 수 : %d \r\n", LCount(&list));
    /** 리스트에 데이터가 잘 들어 있는지 확인하기 위해 처음에 값을 읽어온다. */
    if(LFirst(&list, &data)){
        /** 리스트의 처음 값 표출 */
        printf("%d ", data);
        /** 리스트의 다음 값을 찾으면서 표출 */
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }
    
    printf("\r\n\r\n");
    /** 스택 포인터를 처음으로 이동 (참조 위치 처음 위치로 변경) */
    if(LFirst(&list, &data)){
        /** 처음 값이 22인경우 데이터 삭제 */
        if(data == 22){
            LRemove(&list);
        }
        /** 리스트에 22의 값이 있으면 삭제 */
        while(LNext(&list, &data)){
            if(data == 22){
                LRemove(&list);
            }
        }
    }
    /** 저장된 데이터 숫자 확인 */
    printf("현재 데이터의 수 %d \r\n", LCount(&list));
    /** 참조위치 처음으로 초기화 */
    if(LFirst(&list, &data)){
        /** 처음에 저장된 값 표출 */
        printf("%d ", data);
        /** 리스트의 값 표출 */
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }
    printf("\r\n\r\n");
    return 0;
}