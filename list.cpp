#include <iostream>


struct Node {
    Node* next;
    int data;
    Node(int a) : data(a) {}
};


Node* Reverse(Node* head) {
    if (head == NULL) return NULL;
    Node* prev;
    Node* iter = head;
    while (iter->next != NULL) {
        prev = iter;
        iter = iter->next;
        iter->next = prev;
    }
    return iter;
}


void PrintList(Node* head) {
    Node* iter = head;
    while (iter != NULL) {
        std::cout << iter->data << ", ";
        if (iter->next != NULL) iter = iter->next;
        else break;
    }
}


int main() {
    Node* head = new Node(0);
    Node* iter = head;
    for (int i = 1; i < 5; ++i) {
        iter->next = new Node(i);
        iter = iter->next;
    }
    PrintList(head);
    head = Reverse(head);
    PrintList(head);
    
    return 0;
}