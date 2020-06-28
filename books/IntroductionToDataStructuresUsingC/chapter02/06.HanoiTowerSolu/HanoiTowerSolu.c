#include <stdio.h>

/** 하노이 타워는 등비 수열 문제이다 */

/** 하노이 타워 문제 풀기 */
/** num = 원반의 갯수 
 * from = 움직이기전 위치
 * by = 거쳐가는 중간 위
 * to = 움직여질 위치
*/
void HanoiTowerMove(int num, char from, char by, char to){
    /** 원반의 갯수가 하나일 경우 바로 이동 */
    if(num == 1){
        printf("원반1을 %c에서%c로 이동 \r\n", from, to);
    }else{
        /** 원반의 갯수가 하나가 아닐 경우 by를 거쳐서 이동 되어야한다 */
        /** 1step */
        HanoiTowerMove(num - 1, from, to, by);
        /** 2step */
        printf("원반%d을(를) %c에서 %c로 이동 \r\n", num, from, to);
        /** 3step */
        HanoiTowerMove(num - 1, by, from, to);
    }
}

int main(void){
    HanoiTowerMove(3, 'A', 'B', 'C');
    return 0;
}