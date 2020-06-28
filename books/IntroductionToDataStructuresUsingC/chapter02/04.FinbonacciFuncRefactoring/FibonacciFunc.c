#include <stdio.h>
/** 
 * 피보나치 수열 앞에 두값을 더해서 현재의 수를 만들어가는 수열
*/
/** 피보나치 수열의 n번째 값 반환 */
int Fibo(int n){
    /** 함수의 호출 순서를 보기 위한 코드 */
    printf("func call param %d \r\n", n);
    /** 피보나치 수열의 첫번째 값을 요구하면 0을 반환 */
    if(n == 1){
        return 0;
    /** 피보나치 수열의 두번째 값을 요구하면 1을 반환 */
    }else if(n == 2){
        return 1;
    }else{
        /** 피보나치 수열의 세번째 이후의 값을 요구하면, 이전의 두 값을 구해서 더해주면서 그 값을 반환 */
        return Fibo(n - 1) + Fibo(n - 2);
    }
}

int main(void){
    int i;
    
    Fibo(7);
    return 0;
}