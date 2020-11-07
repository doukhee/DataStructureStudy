#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

/** 리스트 초기화 */
void ListInit(List *plist){
    /** 처음 시작을 널로 설정 */
    plist->head = NULL;
    /** 전체 데이터 수 0으로 초기화 */
    plist->numOfData = 0;
}

/** 리스트에 데이터 삽입 */
void LInsert(List *plist, Data data){
    /** 데이터 삽입을 위한 노드 생성 */
    Node *newNode = (Node *)malloc(sizeof(Node));
    /** 노드에 데이터 삽입 */
    newNode->data = data;
    /** 새로 생성한 노드 다음 값을 리스트의 처음으로 설정 */
    newNode->next = plist->head;
    /** 리스트의 처음 값이 널이 아닌 경우 */
    if(plist->head != NULL){
        /** 리스트의 처음 값 전을 새로 생성한 노드 값을 삽입 */
        plist->head->prev = newNode;
    }
    /** 새로운 노드의 전의 값을 널 값으로 설정 */
    newNode->prev = NULL;
    /** 리스트의 처음을 새로 생성한 노드로 설정 */
    plist->head = newNode;
    /** 전체 데이터 수 1 증가 */
    (plist->numOfData)++;
}

/** 리스트의 처음 값을 읽어오는 함수 */
int LFirst(List *plist, Data *pdata){
    /** 리스트의 처음 가르키는 값이 널이면 false 반환 */
    if(plist->head == NULL){
        return FALSE;
    }
    /** 리스트의 현재 위치가 처음 값으로 이동 */
    plist->cur = plist->head;
    /** 현재 위치의 데이터를 입력 받은 포인터 변수에 삽입 */
    *pdata = plist->cur->data;
    return TRUE;
}

/** 리스트의 현재 값의 다음값을 찾는 함수 */
int LNext(List *plist, Data *pdata){
    /** 현재 노드의 다음 값이 널 값인 경우, false 반환 */
    if(plist->cur->next == NULL) {
        return FALSE;
    }
    /** 현재 리스트의 위치를 다음 노드로 이동 */
    plist->cur = plist->cur->next;
    /** 현재 위치의 데이터를 입력 받은 포인터 변수에 삽입 */
    *pdata = plist->cur->data;

    return TRUE;
}

/** 리스트의 전의 노드 값을 찾는 함수 */
int LPrevious(List *plist, Data *pdata){
    /** 현재 노드 전의 값이 널 값인 경우, false 반환 */
    if(plist->cur->prev == NULL){
        return FALSE;
    }
    /** 현재 노드의 위치를 전 위치로 이동 */
    plist->cur = plist->cur->prev;
    /** 현재 위치의 데이터를 입력 받은 포인터 변수에 삽입 */
    *pdata = plist->cur->data;
    
    return TRUE;
}

/** 현재 총 데이터 수 반환 하는 함수 */
int LCount(List *plist){
    /** 리스트의 현재 데이터 수 반환 */
    return plist->numOfData;
}