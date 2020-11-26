#include <iostream>


struct Node {
    Node* next;
    int data;
    Node(int a) : data(a) {}
};


Node* Reverse(Node* head) {
    if (head == NULL) return NULL;
    Node* prev = NULL;
    Node* iter = head;
    while (iter->next != NULL) {
        Node* temp = iter->next;
        iter->next = prev;
        prev = iter;
        iter = temp;
    }
    iter->next = prev;
    return iter;
}


void PrintList(Node* head) {
    Node* iter = head;
    while (iter != NULL) {
        std::cout << iter->data << std::endl;
        iter = iter->next;
    }
}


void ClearList(Node* head) {
    Node* iter = head;
    while (iter != NULL) {
        Node* next = iter->next;
        delete iter;
        iter = next;
    }
}


int main() {
    Node* head = new Node(0);
    Node* iter = head;
    for (int i = 0; i < 5; ++i) {
        iter->next = new Node(i+1);
        iter = iter->next;
    }
    std::cout << "The original list :\n";
    PrintList(head);
    std::cout << "The reversed list : \n";
    head = Reverse(head);
    PrintList(head);
    ClearList(head);
    return 0;
}