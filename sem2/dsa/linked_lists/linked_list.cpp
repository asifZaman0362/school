#include <iostream>


struct Node
{
    Node (const int = 0);
    Node* next;
    int data;
};


class LinkedList
{
public:
    LinkedList () : head(NULL), length(0) {}
    bool Push (Node*);
    bool Push (const int);
    bool Pop ();
    bool Remove (Node*);

    Node* operator[] (const size_t);
    Node* Head (); // Returns head

    friend void Display (const LinkedList&);
private:
    struct Node* head;
    size_t length;
};


Node::Node(const int data)
{
    this->data = data;
    this->next = NULL;
}


bool LinkedList::Push (Node* target)
{
    this->head->next = target;
    this->head = target;
    this->length++;
    return true;
}

bool LinkedList::Push (const int data)
{
    Node* target = new Node(data);
    if (this->head == NULL)
        this->head = target;
    else
    {
        this->head->next = target;
        this->head = target;
        this->length++;
    }
    return true;
}

bool LinkedList::Pop ()
{
    if (this->head != NULL)
    {
        Node* next = this->head->next;
        delete this->head;
        this->head = next;
        this->length--;
        return true;
    }
    else return false;
}

bool LinkedList::Remove (Node* target)
{
    Node* iter = this->head;
    while (iter != NULL)
    {
        if (iter->next == target)
        {
            iter->next = target->next;
            delete target;
            target = NULL;
            this->length--;
            return true;
        }
        else iter = iter->next;
    }
    return false;
}

Node* LinkedList::Head()
{
    return this->head;
}

Node* LinkedList::operator[] (const size_t pos)
{
    size_t i = 0;
    Node* iter = this->head;
    while ((iter != NULL) && (i <= pos))
    {
        if (i == pos)
        {
            return iter;
        }
        iter = iter->next;
        i++;
    }
    return NULL;
}

void Display (const LinkedList& list)
{
    Node* iter = list.head;
    size_t i = 0;
    while (iter != NULL)
    {
        std::cout << ++i << "\t: " << iter->data << "\n";
        iter = iter->next;
    }
}


int main ()
{
    LinkedList list;
    int choice = 0;
    while (choice != -1)
    {
        std::cout << "Select an operation:\n";
        std::cout << "1. Insert\n2. Pop\n3. Get Element by position\n4. Display\n5. Quit\n\n: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            std::cout << "Enter data: ";
            std::cin >> data;
            if (list.Push(data)) std::cout << data << " inserted!\n";
            else std::cout << "Failed to insert data!\n";
            break;
        }
        case 2:
        {
            if (list.Pop()) std::cout << "Popped last item!\n";
            else std::cout << "Failed to pop last item!";
            break;
        }
        case 3:
        {
            int pos;
            std::cout << "Enter position of item in the list: ";
            std::cin >> pos;
            std::cout << "Item at " << pos << " = " << list[pos] << "\n";
            break;
        }
        case 4:
        {
            Display(list);
            break;
        }
        case 5:
        {
            std::cout << "Quitting program...\n\n";
            choice = -1;
            break;
        }
        default:
        {
            std::cout << "Invalid option! Try again.\n";
        }
    }
    }

    return 0;
}
