#include <stdio.h>

/** 이진 탐색 알고리즘 
 * int ar = 탐색을 할 배열
 * int len = 배열의 길이
 * int target = 찾고자 하는 값
*/
int BSearch(int ar[], int len, int target){
    
    /** 시작 지점 */
    int first = 0;
    /** 마지막 지점 -1을 해주는 이유는 시작이 0부터 이기 때문 */
    int last = len - 1;
    /** 중간 지점 값 저장을 위한 변수 */
    int mid;
    /** 모든 값 비교를 위한 것 <=인 이유는 =를 안할 경우 하나의 값이 빠진다. */
    while(first <= last){
        /** 중간 지점 구하기 */
        mid = (first + last) / 2;
        /** 중간 지점의 값과 구하고자 하는 값 비교 */
        if(target == ar[mid]){
            return mid;
            /** 탐색의 대상이 존재하지 않을경우 무한 루프에 빠지는 것을 방지하기 위해 1을 빼주고 더해준다 */
        }else{
            /** 중간 지점의 값이 구하고자 하는 값보다 큰 경우 */
            if(target < ar[mid]){
                /** 마지막 지점을 중간 값보다 작게 설정 */
                last = mid - 1;
            }else{
                /** 중간 지점의 값이 구하고자 하는 값보다 작은 경우 */
                /** 시작 점을 중간 지점보다 하나 크게 설정 한다. */
                first = mid + 1;
            }
        }
    }
    return -1;
}

int main(void){
    /** 배열의 길이 5 */
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 7);

    if(idx == -1){
        printf("Search Failed \r\n");
    }else{
        printf("Search Success ! index is %d \r\n", idx);
    }

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 4);

    if(idx == -1){
        printf("Search Failed \r\n");
    }else{
        printf("Search Success ! index is %d \r\n", idx);
    }

    return 0;
}