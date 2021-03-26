#include <iostream>


struct Node {
    int data;
    Node* next;
    Node(int d) : data(d) {}
};

Node* AddNode(Node* head) {
    Node* _new = new Node(0);
    std::cout << "Data: ";
    std::cin >> _new->data;
    _new->next = head;
    return _new;
}

int main() {
    Node* head = new Node(0);
    for (int i = 0; i < 3; i++) {
       head = AddNode(head);
    }
    Node* iter = head;
    while(iter != nullptr) {
        std::cout << "Data: " << iter->data << std::endl;
        iter = iter->next;
    }
    return 0;
}
