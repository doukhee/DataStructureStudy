#include <stdio.h>
#include "Point.h"

/** 포인터 데이터 정의 */
void SetPointPos(Point *ppos, int xpos, int ypos){
    /** 포인터에 xpos 값 저장 */
    ppos->xpos = xpos;
    /** 포인터에 ypos 값 저장 */
    ppos->ypos = ypos;
}
/** 현재 포인터 위치 보여주기 */
void ShowPointPos(Point *ppos){
    printf("[%d, %d] \r\n", ppos->xpos, ppos->ypos);
}

/** 포인터 데이터 비교 */
int PointComp(Point *pos1, Point *pos2){
    /** xpos, ypos 값 위치가 같을경우 */
    if(pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos){
        /** 0반환 */
        return 0;
    /** xpos값만 같을 경우 */
    }else if(pos1->xpos == pos2->xpos){
        /** 1빈환 */
        return 1;
    /** ypos값만 같을 경우 */
    }else if(pos1->ypos == pos2->ypos){
        /** 2반환 */
        return 2;
    /** 데이터가 같지 않을 경우 */
    }else{
        /** -1 반환 */
        return -1;
    }
}