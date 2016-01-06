#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//Implementation of a singly-linked list.

//Initializes the head of the list to null
void llist_init(LinkedList *list) {
    list->head = NULL;
}

//creates a new ListNode and adds it to the front of the list.
void llist_add(LinkedList *list, int val) {
    ListNode *e = (ListNode*)malloc(sizeof(ListNode));
    e->val = val;
    e->next = list->head;
    list->head=e;
}

void llist_print(LinkedList *list) {
    if(list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int i = 0;
    ListNode *e = list->head;
    while(e != NULL) {
        printf("%d: %d\n", i++, e->val);
        e=e->next;
    }
}

int llist_getNumElements(LinkedList *list) {
    if(list->head == NULL) {
        return 0;
    }

    int length = 0;
    ListNode *e = list->head;
    while(e != NULL) {
        length++;
        e=e->next;
    }

    return length;
}

//return type is int for insertion to let the caller of the
//method check whether insertion was successful.
//valid input is 0 to numElements-1;
//returns 1 if successful and 0 otherwise.
int llist_insertAt(LinkedList *list, int val, int ith) {
    if(ith >= llist_getNumElements(list)) {
        return 0; //equivalent to false in other languages.
    }

    if(ith == 0) {
        llist_add(list, val);
        return 1;
    }

    ListNode *e = (ListNode*)malloc(sizeof(ListNode));
    ListNode *tmpPrev = list->head;
    ListNode *tmpNext;
    e->val = val;
    int i;
    for(i=0; i < (ith-1); i++) {
        tmpPrev=tmpPrev->next;
    }
    tmpNext = tmpPrev->next;
    tmpPrev->next = e;
    e->next = tmpNext;
    return 1;
}

void llist_insertEnd(LinkedList *list, int val) {
    ListNode *e = (ListNode*)malloc(sizeof(ListNode));
    e->val = val;
    e->next = NULL;
    ListNode *tmp = list->head;

    while(tmp->next != NULL) {
        tmp=tmp->next;
    }
    tmp->next = e;
}
