#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree2.h"


BTreeNode *MakeExpTree(char exp[]){
    Stack stack;
    BTreeNode *pNode;

    int expLen = strlen(exp);
    int i;
    StackInit(&stack);

    for(i = 0; i < expLen; i++){
        pNode = MakeBTreeNode();
        /** isDigit(thisChar);함수는 숫자로 변경이 가능한지 확인하는 함수이다. <ctype.h>에 정의 되어 있다. */
        if(isdigit(exp[i])){
            SetData(pNode, exp[i] - '0');
        }else{
            MakeRightSubTree(pNode, SPop(&stack));
            MakeLeftSubTree(pNode, SPop(&stack));
            SetData(pNode, exp[i]);
        }
        SPush(&stack, pNode);
    }
    return SPop(&stack);
}

int EvaluateExpTree(BTreeNode *bt){
    int op1, op2;

    op1 = GetData(GetLeftSubTree(bt));
    op2 = GetData(GetRightSubTree(bt));

    switch(GetData(bt)){
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
    }
    return 0;
}

void ShowNodeData(int data){
    if(0 <= data && data <= 9){
        printf("%4d ", data);
    }else{
        printf("%4d ", data);
    }
}

void ShowPrefixTypeExp(BTreeNode *bt){
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode *bt){
    InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode *bt){
    PostorderTraverse(bt, ShowNodeData);
}
