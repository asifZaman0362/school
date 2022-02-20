//
// Created by asif on 2/20/22.
//

#include <malloc.h>
#include "utils.h"

static size_t allocated_bytes;
static size_t freed_bytes;

bool contains(list *collection, void *item) {
    struct node_single *iter = collection->tail;
    while (iter != nullptr) {
        if (iter->data == item) return true;
        else iter = iter->next;
    }
    return false;
}

bool contains_dl(list_dl *collection, void *item) {
    struct node_double *iter = collection->tail;
    while (iter != nullptr) {
        if (iter->data == item) return true;
        else iter = iter->next;
    }
    return false;
}

void add(list *collection, void *data) {
    struct node_single *new_node = malloc(sizeof(struct node_single));
    new_node->data = data;
    new_node->next = collection->tail;
    if (collection->head == nullptr) {
        if (collection->tail == nullptr) {
            collection->head = new_node;
        }
    }
    collection->tail = new_node;
}

void add_back(list_dl *collection, void *data) {
    struct node_double *new_node = malloc(sizeof(struct node_double));
    new_node->data = data;
    new_node->next = collection->tail;
    collection->tail->prev = new_node;
    if (collection->head == nullptr) {
        collection->head = new_node;
    }
    collection->tail = new_node;
}

void add_front(list_dl *collection, void *data) {
    struct node_double *new_node = malloc(sizeof(struct node_double));
    new_node->data = data;
    new_node->prev = collection->head;
    collection->head->next = new_node;
    if (collection->tail == nullptr) {
        collection->tail = new_node;
    }
    collection->head = new_node;
}

void remove_item(list *collection, void *item) {
    struct node_single *iter = collection->tail;
    while (iter != nullptr) {
        if (iter->next != nullptr && iter->next->data == item) {
            free(iter->next);
            iter->next = iter->next->next;
            break;
        }
        else iter = iter->next;
    }
}

void remove_last(list *collection) {
    if (collection->tail != nullptr) {
        struct node_single *next = collection->tail->next;
        free(collection->tail);
        collection->tail = next;
    }
}

void remove_item_dl(list_dl *collection, void *item) {
    struct node_double *iter = collection->tail;
    while (iter != nullptr) {
        if (iter->next != nullptr && iter->next->data == item) {
            free(iter->next);
            iter->next = iter->next->next;
            break;
        }
        else iter = iter->next;
    }
}

void remove_back(list_dl *collection) {
    if (collection->tail != nullptr) {
        struct node_double *next = collection->tail->next;
        free(collection->tail);
        collection->tail = next;
    }
}

void remove_front(list_dl *collection) {
    if (collection->head != nullptr) {
        struct node_double *prev = collection->head->prev;
        free(collection->head);
        collection->head = prev;
    }
}

void delete(void *ptr) {
    printf("\nDeleting %d bytes at : %x\n", sizeof(ptr), ptr);
    free(ptr);
    freed_bytes += sizeof(ptr);
}

void *new(size_t size) {
    void *allocated = malloc(size);
    printf("\nAllocating %d bytes of memory at %x\n", size, allocated);
    allocated_bytes += size;
    return allocated;
}

void get_total_memory() {
    printf("\nLeaked memory: %ld\n", (long)allocated_bytes - (long)freed_bytes);
}