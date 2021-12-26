import java.util.Scanner;

interface inface1 {
    public void Withdraw(int amount);
}

interface inface2 extends inface1 {
    public void Deposit(int amount);
}

interface inface3 extends inface2 {
    public void Display();
}

class Account implements inface3 {

    int accountNo;
    String name;
    String address;
    int balance;

    public Account(int ac, String nm, String ad, int bal) {
        accountNo = ac;
        name = nm;
        address = ad;
        balance = bal;
    }

    @Override
    public void Deposit(int amount) {
        balance += amount;
        System.out.println("Amount deposited!");
    }

    @Override
    public void Withdraw(int amount) {
        if (amount > balance) {
            System.out.println("Insufficient balance!");
            return;
        }
        else {
            balance -= amount;
            System.out.println("Amount withdrawn!");
        }
    }

    @Override
    public void Display() {
        System.out.println("Name: " + name);
        System.out.println("Account number: " + accountNo);
        System.out.println("Address: " + address);
        System.out.println("Balance: Rs." + balance);
    }
    
}

public class Interfaces {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the account holder's name: ");
        String name = sc.nextLine();
        System.out.print("Enter address: ");
        String add = sc.nextLine();
        System.out.print("Enter account number: ");
        int ac = sc.nextInt();
        System.out.print("Enter balance: ");
        int bal = sc.nextInt();
        Account acc = new Account(ac, name, add, bal);
        Boolean loop = true;
        while(loop) {
            System.out.println("Available options: ");
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Display");
            System.out.println("4. Quit");
            int opt = sc.nextInt();
            switch(opt) {
                case 1:
                    System.out.print("Enter amount to deposit: ");
                    int amnt = sc.nextInt();
                    acc.Deposit(amnt);
                    break;
                case 2:
                    System.out.print("Enter amount to withdraw: ");
                    int amt = sc.nextInt();
                    acc.Withdraw(amt);
                    break;
                case 3:
                    acc.Display();
                    break;
                default:
                    loop = false;
            }
        }
        sc.close();
    }
}
