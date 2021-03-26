#ifndef _LIST_H_
#define _LIST_H_

typedef unsigned int uint;

struct Node* {
    struct Employee* data;
    struct Node* next;
    struct Node* prev;
};

struct Node* PushFront(Node* item, Node** head) {
    item->next = *head;
    (*head)->prev = item;
    *head = item;
    return item;
}

struct Node* PushBack(Node* item, Node** tail) {
    item->prev = *tail;
    (*tail)->next = item;
    *tail = item;
    return item;
}

struct Node* PopFront(Node** head) {
    free(*head);
    free((*head)->data);
    *head = (*head)->prev;
    (*head)->prev = NULL;
    return *head;
}

struct Node* PopBack(Node* tail) {
    free(*tail);
    free((*tail)->data);
    *tail = (*tail)->next;
    (*tail)->next = NULL;
    return *tail;
}

struct Node* At(uint index, struct Node* head) {
    uint i = 0;
    struct Node* iter = head;
    while (iter != NULL && i <= index) {
        if (i == index) return iter;
        else iter = iter->next;
    }
    printf("Error: Index out of bounds!\n");
    return NULL;
}

#endif
