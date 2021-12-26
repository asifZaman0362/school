package first;
import java.util.Scanner;

class Product {
    public int productId;
    public String productName;
    public float rate;
    public int quantity;

    public Product(int pProductId, String pProductName, float pRate, int pQuantity) {
        this.productId = pProductId;
        this.productName = pProductName;
        this.rate = pRate;
        this.quantity = pQuantity;
    }

    public void Display() {
        System.out.println("Product ID: " + productId);
        System.out.println("Product Name: " + productName);
        System.out.println("Rate: " + rate);
        System.out.println("Quantity: " + quantity);
    }
}

public class ProductDetails {
    public static void main(String[] args) {
        Product[] products = new Product[5];
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            System.out.println("Enter product name: ");
            products[i].productName = sc.nextLine();
            System.out.println("Enter product ID: ");
            products[i].productId = sc.nextInt();
            System.out.println("Enter rate: ");
            products[i].rate = sc.nextFloat();
            System.out.println("Enter quantity: ");
            products[i].quantity = sc.nextInt();
        }
        System.out.println("\nAvailable products:");
        for (int i = 0; i < 5; i++) {
            System.out.println("------------------------------");
            products[i].Display();
        }
        sc.close();
    }
}
