#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "InfixToPostfix.h"


int GetOpPrec(char op){
    switch(op){
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
    }
    return -1;
}

int WhoPrecOp(char op1, char op2){
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec > op2Prec){
        return 1;
    }else if(op1Prec < op2Prec){
        return -1;
    }else{
        return 0;
    }
}

void ConvToRPNExp(char exp[]){
    Stack stack;
    int expLen = strlen(exp);
    char *convExp = (char *)malloc(expLen+1);

    int i, idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char)*expLen+1);
    StackInit(&stack);

    for(i = 0; i < expLen; i++){
        tok = exp[i];

        /** isdigit()함수는 숫자 판별하는 함수 0이 아닌 숫자의 경우 true 반환 0일 경우 false반환 
         * 헤더는 ctpye.h에 정의 되어 있다.
        */
        if(isdigit(tok)){
            convExp[idx++] = tok;
        }else{
            switch (tok)
            {
                case '(':
                    SPush(&stack, tok);
                    break;
                case ')':
                    while(1){
                        popOp = SPop(&stack);
                        if(popOp == '('){
                            break;
                        }
                        convExp[idx++] = popOp;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0){
                        convExp[idx++] = SPop(&stack);
                    }
                    SPush(&stack, tok);
                    break;
            }
        }
    }

    while(!SIsEmpty(&stack)){
        convExp[idx++] = SPop(&stack);
    }
    strcpy(exp, convExp);
    free(convExp);
}