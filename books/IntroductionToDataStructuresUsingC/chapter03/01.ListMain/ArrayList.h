#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE        1
#define FALSE       0

/** 리스트 최대 크기 */
#define LIST_LEN    100

/** List Data int형의 사용하기 위한 별칭 선언 */
typedef int LData;

/** ArrayList 데이터형 구조체 정의 */
typedef struct _ArrayList{
    /** 데이터 저장을 위한 배열 정의 */
    LData arr[LIST_LEN];
    /** 데이터 갯수 */
    int numOfData;
    /** 마지막 데이터 위치 */
    int curPosition;
} ArrayList;

/** ArrayList를 List로 정의 */
typedef ArrayList List;

/** ArrayList 초기화 */
void ListInit(List *plist);
/** ArrayList 데이터 삽입 */
void LInsert(List *plist, LData data);
/** ArrayList 첫번쨰 데이터가 pdata가 가르키는 메모리에 저장 */
int LFirst(List *plist, LData *pdata);
/** ArrayList 초기화 */
int LNext(List *plist, LData *pdata);
/** ArrayList 초기화 */
LData LRemove(List *plist);
/** ArrayList 초기화 */
int LCount(List *plist);

#endif
