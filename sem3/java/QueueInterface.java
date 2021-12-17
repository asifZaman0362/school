import java.util.Scanner;

interface IntQueue {
    public void Enqueue(int x) throws Exception;
    public int Dequeue() throws Exception;
}

class Queue implements IntQueue {

    int rear;
    int front;
    int data[];
    int size;

    public Queue(int size) {
        this.size = size;
        this.data = new int[size];
        rear = -1;
        front = 0;
    }

    public int Front() throws Exception {
        if (front > rear) throw new Exception("Queue is empty!");
        return data[front];
    }
    public int Rear() throws Exception {
        if (front > rear) throw new Exception("Queue is empty!");
        return data[rear];
    }

    @Override
    public void Enqueue(int x) throws Exception {
        if (rear >= size - 1) throw new Exception("Queue overflow!");
        else data[++rear] = x;
    }

    @Override 
    public int Dequeue() throws Exception {
        if (front > rear) throw new Exception("Queue underflow!");
        return data[front++];
    }

    public void Display() {
        int i = front;
        System.out.println("The queue is" + (rear < front ? " empty" : ":"));
        while (i <= rear) {
            System.out.print(data[i++] + ";");
        }
    }
}

public class QueueInterface {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the queue: ");
        int size = sc.nextInt();
        Queue queue = new Queue(size);
        int option = 0;

        while (option != 4) {
            System.out.println("\nQueue operations: ");
            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            option = sc.nextInt();
            try {
                switch(option) {
                    case 1:
                        System.out.print("Enter the number: ");
                        int x = sc.nextInt();
                        queue.Enqueue(x);
                        break;
                    case 2:
                        System.out.println("Popped: " + queue.Dequeue());
                        break;
                    case 3:
                        queue.Display();
                        break;
                    default:
                        option = 4;
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        sc.close();
    }
}
