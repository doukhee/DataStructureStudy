#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE        1
#define FALSE       0

/** int형을 LData로 별칭 선언 */
typedef int LData;

/** 구조체 정의 */
typedef struct _node{
    /** 저장될 데이터 */
    LData data;
    /** 다음 위치를 저장하는 구조체 */
    struct _node *next;
} Node;

/** LinkedList 구조체 정의 */
typedef struct _linkedList{
    /** 첫시작 데이터 */
    Node *head;
    /** 현재 위치 데이터 */
    Node *cur;
    /** 현재 전의 데이터 */
    Node *before;
    /** 저장된 전체 데이터 */
    int numOfData;
    /** 비교 연산 함수 정의 */
    int (*comp)(LData d1, LData d2);
} LinkedList;
/** LinkedList를 List로 별칭 선언 */
typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif
