package second;
import java.util.Scanner;

interface IntStack {
    public void Push(int x) throws Exception;
    public int Pop() throws Exception;
    public int Back() throws Exception;
}

class Stack implements IntStack {
    int data[];
    int max;
    int top;

    public Stack(int max) {
        this.max = max;
        this.top = -1;
        data = new int[max];
    }

    @Override
    public void Push(int x) throws Exception {
        if (top == max - 1) throw new Exception("Stack overflow!");
        else data[++top] = x;
    }

    @Override
    public int Pop() throws Exception {
        if (top == -1) throw new Exception("Stack underflow!");
        return data[top--];
    }

    public void Display() {
        System.out.println("\nThe stack is: ");
        for (int i = 0; i <= top; i++) {
            System.out.println(data[i]);
        }
    }

    @Override
    public int Back() throws Exception {
        if (top == -1) throw new Exception("Stack is empty!");
        return data[top];
    }
}

public class StackInterface {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the stack size: ");
        Stack stack = new Stack(sc.nextInt());
        int option = 0;
        while (option != 5) {
            System.out.println("\nStack operations: ");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Get top");
            System.out.println("4. Display");
            System.out.println("5. Exit");
            option = sc.nextInt();
            try {
                switch(option) {
                    case 1:
                        System.out.print("Enter the number: ");
                        int x = sc.nextInt();
                        stack.Push(x);
                        break;
                    case 2:
                        System.out.println("Popped: " + stack.Pop());
                        break;
                    case 3:
                        System.out.println("Top item: " + stack.Back());
                        break;
                    case 4:
                        stack.Display();
                        break;
                    default:
                        option = 5;
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        sc.close();
    }
}
