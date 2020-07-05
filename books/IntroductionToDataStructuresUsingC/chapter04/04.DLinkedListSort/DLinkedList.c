#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"


/** Linked List 초기화 */
void ListInit(List *plist){
    /** 첫번째에 노드 생성 */
    plist->head = (Node *)malloc(sizeof(Node));
    /** 다음 노드 NULL로 초기화 */
    plist->head->next = NULL;
    
    plist->comp = NULL;
    /** 현재 데이터 수 0으로 초기화 */
    plist->numOfData = 0;
}

/** 첫번째 데이터 삽입 */
void FInsert(List *plist, LData data){
    /** 새로운 노드 만들기 */
    Node *newNode = (Node *)malloc(sizeof(Node));
    /** 구조체 노드에 데이터 저장 */
    newNode->data = data;
    /** 새로운 노드의 다음을 다른 노드를 가르키게 설정 */
    newNode->next = plist->head->next;
    /** 더미노드가 새 노드를 가르키게 설정 */
    plist->head->next = newNode;
    /** 저장된 노드의 수를 하나 증가시킴 */
    (plist->numOfData)++;
}

/** 두번째 부터 데이터 삽입 */
void SInsert(List *plist, LData data){
    /** 새로운 노드 생성 */
    Node *newNode = (Node *)malloc(sizeof(Node));
    /** 노드의 첫 부분 가져오기 */
    Node *pred = plist->head;
    /** 새로운 노드에 데이터 저장 */
    newNode->data = data;
    /** 새로운 구조체 노드를 삽입할 지점 찾기 */
    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0){
        pred = pred->next;
    }
    /** 새로운 노드 삽입 하기 전에 기존에 있던 다음 위치를 새로운 노드에 연결을 해준다 */
    newNode->next = pred->next;
    /** 노드를 삽입할 부분에 전에 있는 구조체애 새로운 노드를 연결 해준다 */
    pred->next = newNode;
    /** 전체 데이터 숫자를 증가 시켜준다 */
    (plist->numOfData)++;
}

/** 데이터 삽입 함수 */
void LInsert(List *plist, LData pdata){
    /** 비교 연삽이 없을 경우 FInsert() 실행*/
    if(plist->comp == NULL){
        FInsert(plist, pdata);
    }else{
        /** 비교 연삽이 있을 경우  SInsert() 실행*/
        SInsert(plist, pdata);
    }
}



/** 첫번째 노드로 이동 */
int LFirst(List *plist, LData *pdata){
    /** 더미노드가 NULL을 가르킨다면 false 반환 */
    if(plist->head->next == NULL){
        return FALSE;
    }
    /** 삭제를 위한 참조 값 첫번째 위치로 이동 */
    plist->before = plist->head;
    /** 현재 위치를 가르키는 참조 값 저장된 위치로 이동 */
    plist->cur = plist->head->next;
    /** 현재 데이터를 인자로 받은 주소 값에 값을 저장하여 반환 */
    *pdata = plist->cur->data;
    return TRUE;
}

/** 다음 구조체로 이동 하는 함수 */
int LNext(List *plist, LData *pdata){
    /** 다음 데이터가 없을 경우 FALSE를 반환 */
    if(plist->cur->next == NULL){
        return FALSE;
    }
    /** 현재 위치를 다음 위치로 저장 */
    plist->before = plist->cur;
    /** 현재 위치 하나 이동 */
    plist->cur = plist->cur->next;
    /** 현재 위치의 데이터를 인자로 받은 주소 값에 저장하여 반환 */
    *pdata = plist->cur->data;
    return TRUE;
}


/** 데이터 삭제 */
LData LRemove(List *plist){
    /** 소멸 대상의 주소값을 rpos에 저장 */
    Node *rpos = plist->cur;
    /** 소멸 대상의 데이터를 rdata에 저장 */
    LData rdata = rpos->data;
    /** 현재 위치를 현재의 다음 위치로 저장 */
    plist->before->next = plist->cur->next;
    /** 현재 위치를 전 위치 저장 */
    plist->cur = plist->before;
    /** 삭제한 노드의 메모리 해제 */
    free(rpos);
    /** 전체 데이터 갯수 변경 해주기 */
    (plist->numOfData)--;
    /** 삭제 된 데이터 반환 */
    return rdata;
}

/** 현재 데이터 갯수 반환 함수 */
int LCount(List *plist){
    /** 현재 리스트에 저장된 데이터 수 */
    return plist->numOfData;
}

/** 정렬 함수  */
void SetSortRule(List *plist, int (* comp)(LData d1, LData d2)){
    /** 정렬를 위한 함수 저장 */
    plist->comp = comp;
}