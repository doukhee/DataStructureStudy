#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List *plist){
    /** 마지막 주소값 초기화 */
    plist->tail = NULL;
    /** 현재 주소값 초기화 */
    plist->cur = NULL;
    /** 직전의 주소값 초기화 */
    plist->before = NULL;
    /** 현재 데이터 값 초기화 */
    plist->numOfData = 0;
}

/** 첫 부분에 데이터 삽입 */
void LInsertFront(List *plist, Data data){
    /** 삽입을 위한 동적 메모리 생성 */
    Node *newNode = (Node *)malloc(sizeof(Node));
    /** 데이터 새로운 노드에 저장 */
    newNode->data = data;
    /** 첫번째 노드 라면, */
    if(plist->tail == NULL){
        /** tail이 새로운 노드를 가르키게 한다. */
        plist->tail = newNode;
        /** 새 노드 다음을 자신을 가르킨다. */
        newNode->next = newNode;
    /** 두번쩨 이후의 노드라면,  */
    }else{
        /** 처음과 끝이 연결되어 있으므로 끝 주소의 다음 주소는 처음 주소 */
        newNode->next = plist->tail->next;
        /** 처음 부분에 생성한 노드 삽입 */
        plist->tail->next = newNode;
    }
    /** 데이터 수 카운트 */
    (plist->numOfData)++;
}

/** 마지막 부분에 데이터 삽입 */
void LInsert(List* plist, Data data){
    /** 삽입을 위한 동적 메모리 생성 */
    Node *newNode = (Node *)malloc(sizeof(Node));
    /** 데이터 새로운 노드에 저장 */
    newNode->data = data;
    /** 첫번째 노드 라면, */
    if(plist->tail == NULL){
        /** 마지막 부분에 새로운 노드 삽입 */
        plist->tail = newNode;
        /** 새로운 노드의 다음을 자기 자신을 가르키도록 한다. */
        newNode->next = newNode;
    /** 첫번째 노드가 아니라면, */
    }else{
        /** 새로운 노드의 다음을 끝 지점의 다음 지점(시작 지점)을 가르키게 한다. */
        newNode->next = plist->tail->next;
        /** 끝 지점의 다음 지점에 새로운 노드 삽입 */
        plist->tail->next = newNode;
        /** 새로운 노드는 끝 지점에 위치하게 한다. */
        plist->tail = newNode;
    }
    /** 데이터 수 카운트 */
    (plist->numOfData)++;
}

/** 처음의 위치로 이동 */
int LFirst(List *plist, Data *pdata){
    /** 끝 부분이 없으면 데이터 없음 */
    if(plist->tail == NULL){
        return FALSE;
    }
    /** 리스틔 전을 끝 부분을 가르키게 한다. */
    plist->before = plist->tail;
    /** 현재 위치를 처음 위치로 (끝 부분과 시작 부분이 연결되어 있으므로) */
    plist->cur = plist->tail->next;
    /** 시작 지점의 값을 가져와서 pdata의 주소 값에 넣는다. */
    *pdata = plist->cur->data;
    return TRUE;
}

/** 다음 위치로 이동 */
int LNext(List *plist, Data *pdata){
    /** 끝 부분이 없으면 데이터 없음 */
    if(plist->tail == NULL){
        return FALSE;
    }
    /** 전 부분을 현재 위치로 이동시킨다. */
    plist->before = plist->cur;
    /** 현재 부분을 다음 위치로 이동한다. */
    plist->cur = plist->cur->next;
    /** 현재 데이터의 값을 pdata의 주소에 넣는다. */
    *pdata = plist->cur->data;
    return TRUE;
}

/** 데이터 삭제 */
Data LRemove(List *plist){
    /** 임시 주소값ㅇ르 담기 위한 변수 선언 (현재 위치를 임시 저장한다) */
    Node *rpos = plist->cur;
    /** 현재 데이터를 임시 저장한다. */
    Data rdata = rpos->data;
    /** 현재 위치가 마지막 부분일 경우 */
    if(rpos == plist->tail){
        /** 마지막 위치가 시작 부분과 같을 경우 */
        if(plist->tail == plist->tail->next){
            /** 마지막 부분 없앤다. */
            plist->tail = NULL;
        }else{
            /** 마지막 부분을 전 부분으로 이동 시킨다. */
            plist->tail = plist->before;
        }
    }
    /** 마지막 부분을 현재 위치의 다음 부분과 연결 시킨다. */
    plist->before->next = plist->cur->next;
    /** 현재 위치를 전 위치로 이동 시킨다. */
    plist->cur = plist->before;
    /** 임시저장하던 삭제 하기 위한 값 메모리 해제 시킨다. */
    free(rpos);
    /** 현재 데이터 수 줄여 준다. */
    (plist->numOfData)--;
    return rdata;
}

/** 전체 데이터 수 */
int LCount(List *plist){
    /** 데이터 카운트 수를 반환한다. */
    return plist->numOfData;
}


