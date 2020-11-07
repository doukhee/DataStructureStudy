#include <stdio.h>
#include "ExpressionTree.h"

int main(){
    char exp[] = "12+7*";
    BTreeNode *eTree = MakeExpTree(exp);

    printf("전위 표기법의 수식 : ");
    ShowPrefixTypeExp(eTree);
    printf("\r\n");

    printf("중위 표기법의 수식 : ");
    ShowInfixTypeExp(eTree);
    printf("\r\n");

    printf("후위 표긱법의 수식 : ");
    ShowPostfixTypeExp(eTree);
    printf("\r\n");

    printf("연산의 결과 : %d \r\n", EvaluateExpTree(eTree));

    return 0;
}