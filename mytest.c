#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void test1();
void test2();

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("error: not enough input\n");
        printf("       specify either 1 or 2 after command\n");
        printf("example: ./mytest 1\n");
        exit(1);
    }
    if(atoi(argv[1]) == 1) {
        test1();
    } else if (atoi(argv[1]) == 2) {
        test2();
    } else {
        printf("There are only 2 tests right now.\n");
        printf("Please pass either a 1 or a 2.\n");
        exit(1);
    }
    return 0;
}

void test1() {
    LinkedList list;
    llist_init(&list);
    llist_add(&list, 3);
    llist_add(&list, 2);
    llist_add(&list, 1);
    printf("my output after adding and printing:\n");
    llist_print(&list);
    printf("\n");
    printf("output intended:\n");
    printf("0: 1\n1: 2\n2: 3\n");
}

void test2() {
    printf("entered test2\n");

    LinkedList list;
    llist_init(&list);
    llist_add(&list, 3);
    llist_add(&list, 2);
    llist_add(&list, 1);
    llist_print(&list);

    printf("\n\n");

    if(!llist_insertAt(&list, 27, 1000)) {
        printf("added at the 1000th index.\n");
        printf("OH NO! that didn't work!\n");
        printf("Spoiler Alert: it shouldn't.\n");
    }

    printf("\n\n");
    if(!llist_insertAt(&list, 27, 1)) {
         printf("code doesn't work as intended.\n");
         printf("debug.\n");
    } else {
         llist_print(&list);
    }
}
