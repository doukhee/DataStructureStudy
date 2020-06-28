#include <stdio.h>

/** 
 * 이진 탐색 알고리즘 재귀적 호출
 * int ar[] = 탐색을 할 배열
 * int first = 시작점 
 * int last = 마지막 지점
 * int target = 찾고자하는 값 
*/
int BSearchRecur(int ar[], int first, int last, int target){
    /** 중간 지점을 구하기 위한 변수 */
    int mid;
    /** 시작지점이 마지막 지점보다 클 경우 값이 없음을 의미 */
    if(first > last){
        return -1;
    }
    /** 중간값을 구하기 */
    mid = (first + last) / 2;
    /** 배열의 중간값이 구하고자 하는 값인 경우 */
    if(ar[mid] == target){
        return mid;
    }
    /** 찾고자하는 값이 중간 값보다 작을 경우 */
    if(target < ar[mid]){
        /** 마지막 지점 변경을 하여 진행 1을 빼주는 이유는 무한 루프에 빠지지 않기 위해서 */
        return BSearchRecur(ar, first, mid - 1, target);
    }else{
        /** 시작 지점 변경을 하여 진행 1을 더하는 이유는 무한 루프에 빠지지 않기 위해서 */
        return BSearchRecur(ar, mid + 1, last, target);
    }
}

int main(void){
    int arr[] = {1,3 , 5, 7, 9};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int) - 1, 7);

    if(idx == -1){
        printf("Search Failed \r\n");
    }else{
        printf("Search Success ! Index is %d \r\n", idx);
    }
    /** 배열의 시작이 0부터 시작이라 1을 빼주는 것 */
    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int) - 1, 4);
    
    if(idx == -1){
        printf("Search Failed \r\n");
    }else{
        printf("Search Success ! Index is %d \r\n", idx);
    }

    return 0;
}