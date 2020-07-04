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

void SInsert(List *plist, LData data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *pred = plist->head;
    newNode->data = data;
    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0){
        pred = pred->next;
    }
    newNode->next = pred->next;
    pred->next = newNode;
    (plist->numOfData)++;
}

void LInsert(List *plist, LData pdata){
    if(plist->comp == NULL){
        FInsert(plist, pdata);
    }else{
        SInsert(plist, pdata);
    }
}

/** 첫번째 노드로 이동 */
int LFirst(List *plist, LData *pdata){
    /** 더미노드가 NULL을 가르킨다면 false 반환 */
    if(plist->head->next == NULL){
        return FALSE;
    }
    /** */
    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, LData *pdata){
    if(plist->cur->next == NULL){
        return FALSE;
    }
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

/** 데이터 삭제 */
LData LRemove(List *plist){
    /** 소멸 대상의 주소값을 rpos에 저장 */
    Node *rpos = plist->cur;
    /** 소멸 대상의 데이터를 rdata에 저장 */
    LData rdata = rpos->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List *plist){
    return plist->numOfData;
}

void SetSortRule(List *plist, int (* comp)(LData d1, LData d2)){
    plist->comp = comp;
}