#include <stdio.h>

/**
 * 위치 탐색 알고리즘 순차적 실행으로 검색 
 * 인자값 
 * ar[] = 탐색을 원하는 배열 입력
 * len = 배열의 길이 
 * target = 찾고 싶은 값 
 */
int LSearch(int ar[], int len, int target){
    /** for문의 실행 횟수를 구하기 위한 값 찾고 싶은 값의 위치 값이 된다. */
    int i;
    /** 순차적 검색 */
    for(i = 0; i < len; i++){
        /** 배열의 값 비교 */
        if(ar[i] == target){
            return i;
        }
    }
    return -1;
}

int main(void){
    /** 배열 선언 */
    int arr[] = {3, 5, 2, 4, 9};
    /** 찾고자 하는 값의 위치 값을 위한 변수 */
    int idx;
    /** 위치값 찾기 */
    /** sizeof(arr)/sizeof(int) 배열의 길이를 구하는 법 */
    idx = LSearch(arr, sizeof(arr)/sizeof(int), 4);
    /** 원하는 값을 찾지 못했을 경우 */
    if(idx == -1){
        printf("Search Failed \r\n");
    }else{
        printf("Search Success ! index is %d \r\n", idx);
    }

    return 0;
}