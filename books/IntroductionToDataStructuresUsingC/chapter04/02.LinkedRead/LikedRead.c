#include <stdio.h>
#include <stdlib.h>

/** Node 선언 */
typedef struct _node{
    int data;
    struct _node *next;
} Node;

int main(void){
    /** 시작 부분 초기화 */
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;
    /** 새로운 변수 선언 */
    Node *newNode = NULL;
    /** 입력 데이터 임시 저장 */
    int readData;

    while(1){
        printf("자연수 입력 : ");
        scanf("%d", &readData);
        /** 입력 데이터가 1이하일 경우 탈출 */
        if(readData < 1){
            break;
        }
        /** 구조체 메모리 동적 할당 */
        newNode = (Node *)malloc(sizeof(Node));
        /** 입력 데이터 구조체에 저장 */
        newNode->data = readData;
        /** 다음을 초기화 */
        newNode->next = NULL;
        /** Node의 처음 값이 없을경우 처음 값으로 저장 */
        if(head == NULL){
            head = newNode;
        }else{
            /** 마지막에 새로운 구조체 저장 */
            tail->next = newNode;
        }
        /** 처음에는 head부분이 tail부분도 된다. */
        /** 마지막을 구조체 저장 */
        tail = newNode;
    }
    printf("\r\n");

    printf("입력 받은 데이터의 전체 출력 ! \r\n");
    if(head == NULL){
        printf("저장된 자연수가 존재하지 않습니다.\r\n");
    }else{
        /** 현재 위치를 처음 값으로 지정 */
        cur = head;
        /** 처음 값 데이터 표출 */
        printf("%d ", cur->data);
        /** 현재 위치에서 다음 구조체가 없을 때까지 반복 */
        while(cur->next != NULL){
            /** 현재 위치를 다음 위치로 이동 */
            cur = cur->next;
            /** 데이터 값 표출 */
            printf("%d ", cur->data);
        }
    }
    printf("\r\n");
    /** 현재 값이 없을 경우 종료 */
    if(head == NULL){
        return 0;
    }else{
        /** 지울 위치를 처음 위치로 */
        Node *delNode = head;
        /** 지울 위치 다음 구조체 */
        Node *delNextNode = head->next;

        printf("%d을(를) 삭제합니다.\r\n", delNode->data);
        /** 지울 구조체의 메모리 해제 */
        free(delNode);
        /** 지울 구조체가 없을 경우 반복문 종료 */
        while(delNextNode != NULL){
            /** 지울 구조체 다음 구조체로 이동 */
            delNode = delNextNode;
            /** 지울 구조체 다음 위치로 이동 */
            delNextNode = delNextNode->next;

            printf("%d을(를) 삭제합니다.\r\n", delNode->data);
            /** 지운 구조체 메모리 해제 */
            free(delNode);
        }
    }
    return 0;
}