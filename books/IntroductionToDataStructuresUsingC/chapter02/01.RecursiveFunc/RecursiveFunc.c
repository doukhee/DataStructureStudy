#include <stdio.h>

/** 재귀 호출 함수 */
void Recursive(int num){
    /** 인자 값이 0이거나 0보다 작으면 종료 */
    if(num <= 0){
        return;
    }
    /** 호출 횟수 표현하기 */
    printf("Recursive Call ! %d\r\n", num);
    /** 인자의 값을 하나 빼서 다시 자기 자신의 함수 호출 */
    Recursive(num - 1);
}

int main(void){
    Recursive(3);
    return 0;
}