#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE            1
#define FALSE           0

/** 데이터 타입 별칭 */
typedef int Data;

/** 구조체 정의 */
typedef struct _node{
    /** 구조체의 데이터 */
    Data data;
    /** 다음 구조체 위치 저장 */
    struct _node *next;
    /** 직전 구조체 위치 저장 */
    struct _node *prev;
} Node;

/** 양방향 연결 리스트의 초기화를 담당하는 구조체 */
typedef struct _DLinkedList{
    /** 더미 구조체의 시작 */
    Node *head;
    /** 구조체의 현재 위치 */
    Node *cur;
    /** 전체 데이터 숫자 */
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

/** 양방향 리스트 초기화 */
void ListInit(List *plist);
/** 양방향 리스트 값 삽입 */
void LInsert(List *plist, Data data);
/** 양방향 리스트의 시작 값 반환 및 처음 위치로 이동 */
int LFirst(List *plist, Data *pdata);
/** 다음 노드로 이동 */
int LNext(List *plist, Data *pdata);
/** 전 노드로 이동 */
int LPrevious(List *plist, Data *pdata);
/** 전체 데이터 수 반환 */
int LCount(List *plist);

#endif