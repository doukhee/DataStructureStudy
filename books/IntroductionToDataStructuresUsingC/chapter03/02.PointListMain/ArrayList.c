#include <stdio.h>
#include "ArrayList.h"

/** 리스트 초기화 */
void ListInit(List *plist){
    /** 저장된 데이터의 수 초기화 */
    (plist->numOfData) = 0;
    /** 데이터의 참조위치를 -1로 초기화 */
    /** 현재 아무 위치도 가르키지 않는다는 표시 */
    (plist->curPosition) = -1;
}
/** 리스트에 값 넣기 */
void LInsert(List *plist, LData data){
    /** 저장된 데이터의 수 리스트의 최대 크기보다 클 경우 실패 정의 */
    if(plist->numOfData >= LIST_LEN){
        /** 문자열 stdout에 전달 하여 저장 안됨을 표시 */
        puts("not impossible saved \r\n");
        return;
    }
    /** 데이터 저장 현재 위치에 데이터 저장 */
    plist->arr[plist->numOfData] = data;
    /** 배열의 다음 값을 가르키기 위한 1 증가 */
    (plist->numOfData)++;
}
/** 리스트의 처음 값 가져오기 */
int LFirst(List *plist, LData *pdata){
    /** 저장된 값이 없다면 FALSE 반환 */
    if(plist->numOfData == 0){
        return FALSE;
    }
    /** 스택 포인터와 같다. 위치 초기화(참조 위치 초기화) */
    (plist->curPosition) = 0;
    /** pdata의 주소 값에 값을 저장 */
    *pdata = plist->arr[0];
    return TRUE;
}
/** 다음 위치의 데이터 가져오기 */
int LNext(List *plist, LData *pdata){
    /** 참조위치가 데이터의 저장된 숫자 보다 크면 FALSE 반환 */
    if(plist->curPosition >= (plist->numOfData) - 1){
        return FALSE;
    }
    /** 스택 포인터와 같은 역활. 위치 증가(참조 위치 증가) */
    (plist->curPosition)++;
    /** pdata의 주소에 값을 저장 */
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}
/** 값 지우기 */
LData LRemove(List *plist){
    /** 참조위치 임시저장(스택 포인터 위치 임시 저장) */
    int rpos = plist->curPosition;
    /** 데이터 숫자 임시 저장 */
    int num = plist->numOfData;
    int i;
    /** 삭제할 데이터 임시 저장 */
    LData rdata = plist->arr[rpos];
    /** 삭제한 위치 이후 부터 하나씩 앞으로 당기기 */
    for(i = rpos; i < num - 1; i++){
        plist->arr[i] = plist->arr[i+1];
    }
    /** 데이터 숫자 감소 시켜서 삭제 후 데이터 수 일치 시키기 */
    (plist->numOfData)--;
    /** 데이터 삭제 후 참조 위치를 하나 돌려 두기 */
    (plist->curPosition)--;
    return rdata;
}

/** 현재 저장된 데이터의 숫자 반환 */
int LCount(List *plist){
    return plist->numOfData;
}