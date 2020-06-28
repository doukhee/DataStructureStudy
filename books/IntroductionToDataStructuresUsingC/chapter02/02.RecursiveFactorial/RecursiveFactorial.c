#include <stdio.h>

/** 팩토리얼 계산하는 재귀 함수 */
int Factorial(int n){
    /** 탈출 조건 */
    /** 인자 값이 0일 경우 */
    if(n == 0){
        return 1;
    }else{
        /** 재귀 함수 호출 자기 자신에 1을 뺀값을 재귀하고 n값을 곱해준다 */
        return n * Factorial(n - 1);
    }
}

int main(void){
    printf("1! = %d \r\n", Factorial(1));
    printf("2! = %d \r\n", Factorial(2));
    printf("3! = %d \r\n", Factorial(3));
    printf("4! = %d \r\n", Factorial(4));
    printf("9! = %d \r\n", Factorial(9));
    return 0;
}