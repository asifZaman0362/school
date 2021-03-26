#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>


typedef unsigned int uint;

struct Node {
    struct Employee* data;
    struct Node* next;
    struct Node* prev;
};

struct Node* PushFront(struct Node* item, struct Node** head) {
    item->next = *head;
    (*head)->prev = item;
    *head = item;
    return item;
}

struct Node* PushBack(struct Node* item, struct Node** tail) {
    item->prev = *tail;
    (*tail)->next = item;
    *tail = item;
    return item;
}

struct Node* PopFront(struct Node** head) {
    free(*head);
    free((*head)->data);
    *head = (*head)->prev;
    (*head)->prev = NULL;
    return *head;
}

struct Node* PopBack(struct Node** tail) {
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
