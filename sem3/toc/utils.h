//
// Created by asif on 2/20/22.
//

#ifndef AUTOMATA_UTILS_H
#define AUTOMATA_UTILS_H

#define nullptr 0
#define true 1
#define false 0

typedef unsigned char bool;

struct node_single {
    struct node_single *next;
    void *data;
};

struct node_double {
    struct node_double *next;
    struct node_double *prev;
    void *data;
};

typedef struct singly_linked_list {
    struct node_single *head;
    struct node_single *tail;
} list;

typedef struct doubly_linked_list {
    struct node_double *head;
    struct node_double *tail;
} list_dl;

bool contains(list*, void*);
bool contains_dl(list_dl*, void*);

void add(list*, void*);
void add_back(list_dl*, void*);
void add_front(list_dl*, void*);

void remove_item(list*, void*);
void remove_last(list*);
void remove_item_dl(list_dl*, void*);
void remove_back(list_dl*);
void remove_front(list_dl*);

void delete(void*);
void *new(size_t);
void get_total_memory();

#endif //AUTOMATA_UTILS_H