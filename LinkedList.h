struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct LinkedList {
    ListNode *head;
};

typedef struct LinkedList LinkedList;

void llist_init(LinkedList *list);
void llist_add(LinkedList *list, int val);
void llist_print(LinkedList *list);
int llist_insertAt(LinkedList *list, int val, int ith);
void llist_insertEnd(LinkedList *list, int val);
int llist_exists(LinkedList *list, int val);
int llist_getIth(LinkedList *list, int ith, int *val);
int llist_getNumElements(LinkedList *list);
