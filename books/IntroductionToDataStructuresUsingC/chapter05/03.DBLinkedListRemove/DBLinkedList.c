#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist){
    plist->head = (Node *)malloc(sizeof(Node));
    plist->tail = (Node *)malloc(sizeof(Node));

    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->next = NULL;
    plist->tail->prev = plist->head;

    plist->numOfData = 0;
}
void LInsert(List *plist, Data data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    /** prev = head */
    newNode->prev = plist->tail->prev;
    /** tail ? */
    plist->tail->prev->next = newNode;

    newNode->next = plist->tail;
    plist->tail->prev = newNode;

    (plist->numOfData)++;
}

int LFirst(List *plist, Data *data){
    if(plist->head->next == NULL){
        return FALSE;
    }

    plist->cur = plist->head->next;
    *data = plist->cur->data;
    return TRUE;
}
int LNext(List *plist, Data *data){
    if(plist->cur->next == plist->tail){
        return FALSE;
    }
    plist->cur = plist->cur->next;
    *data = plist->cur->data;
    return  TRUE;
}

Data LRemove(List *plist){
    Node *rpos = plist->cur;
    Data rmov = rpos->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;

    plist->cur = plist->cur->prev;

    free(rpos);
    (plist->numOfData)--;
    return rmov;

}

int LCount(List *list){
    return list->numOfData;
}