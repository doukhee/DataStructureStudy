#include <stdio.h>


int main(void){
    /** 배열 선언 */
    int arr[10];
    /** 배열 갯수 초기화 */
    int readCount = 0;
    /** 입력 받은 데이터 저장 하기 위한 변수 */
    int readData;
    int i;
    /** 1이하의 값 입력 시 종료 */
    while(1){
        printf("자연수 입력 : ");
        /** 값 읽어오기 */
        scanf("%d", &readData);
        /** 입력값이 1이하의 경우 탈출 */
        if(readData < 1){
            break;
        }
        /** 배열에 저장 */
        arr[readCount++] = readData;
    }
    /** 배열에 저장된 값 표출 */
    for(i = 0; i < readCount; i++){
        printf("%d ", arr[i]);
    }
    printf("\r\n");
    return 0;
}