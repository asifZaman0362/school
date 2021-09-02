/******* QUEUE's
 *
 * From (https://en.wikipedia.org/wiki/Queue_(abstract_data_type)):
 *
 * In computer science, a queue is a collection of entities that are maintained in a sequence 
 * and can be modified by the addition of entities at one end of the sequence and the removal 
 * of entities from the other end of the sequence. By convention, the end of the sequence at 
 * which elements are added is called the back, tail, or rear of the queue, and the end at 
 * which elements are removed is called the head or front of the queue, 
 * analogously to the words used when people line up to wait for goods or services.
 *
 * Linear Queue's :
 *
 * A queue has a front index and a rear index.
 * Items are inserted (enqueue'd) into the rear and removed (dequeue'd) from the front.
 *
 * A queue starts with the following configuration:
 * front = 0
 * rear = -1
 *
 * The queue empty state is given by:
 * (rear < front)
 * 
 * The queue full state is given by:
 * rear >= size - 1
 *
*/



#include <iostream>


inline bool isEmpty (int rear, int front)
{
    return rear < front;
}

void enqueue (int queue[], int size, int& rear, int x)
{
    if (rear >= size - 1)
    {
        std::cout << "Queue overflow!" << std::endl;
        exit(-1);
    } 
    else queue[++rear] = x;
}

int dequeue (int queue[], int& front, int rear)
{
    if (isEmpty(rear, front))
    {
        std::cout << "Queue underflow!" << std::endl;
        exit(-1);
    }
    return queue[front++];
}

void print (int queue[], int front, int rear)
{
    for (int i = front; i <= rear; i++)
    {
        std::cout << i << "\t: " << queue[i] << "\n";
    }
}

int main ()
{
    const int size = 100;
    int queue[size];
    int front = 0, rear = -1;
    
    int choice = 0;
    while (choice != -1)
    {
        std::cout << "Select an option:\n";
        std::cout << "1: Enqueue\n2: Dequeue\n3: Print\n4: Quit\n\n:";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int var;
            std::cout << "Value to enqueue: ";
            std::cin >> var;
            enqueue(queue, size, rear, var);
            break;
        }
        case 2:
        {
            int popped = dequeue(queue, front, rear);
            std::cout << "Dequeued " << popped << "\n";
            break;
        }
        case 3:
        {
            print(queue, front, rear);
            break;
        }
        case 4:
        {
            std::cout << "Exiting...\n";
            choice = -1;
            break;
        }
        default:
            std::cout << "Invalid option! Try again...\n";
        }
    }

    return 0;
}
