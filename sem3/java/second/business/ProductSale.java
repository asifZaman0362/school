package business;
import java.util.Scanner;

interface Discount {
    public static final float discount = 0.2f;
    public float CalculatePrice();
}

class Product implements Discount {
    String name;
    float costPrice;
    float sellingPrice;
    public int sales;

    public Product(String name, float costPrice, float sellingPrice) {
        this.name = name;
        this.costPrice = costPrice;
        this.sellingPrice = sellingPrice;
    }
    
    @Override
    public float CalculatePrice() {
        return sellingPrice - sellingPrice * discount;
    }
}

class Store {
    Product[] products;

    public Store() {
        products = new Product[] {
            new Product("Toothbrush", 10, 30), 
            new Product("Toothpaste", 5, 25),
            new Product("Soap", 5, 30)
        };
    }

    public void DisplayProducts() {
        for (int i = 0; i < products.length; i++) {
            System.out.println(i + 1 + ": " + products[i].name + " \t---- Rs." + products[i].sellingPrice);
        }
    }

    public void BuyProduct(int id) throws Exception {
        if (id < 0 || id > products.length) throw new Exception("Invalid product code!");
        else products[id].sales++;
    }

    public void CalculateSales() {
        float grossProfit = 0;
        for (int i = 0; i < products.length; i++) {
            float productProfit = products[i].sales * (products[i].CalculatePrice() - products[i].costPrice);
            System.out.println("Product: " + products[i].name);
            System.out.println("Sales: " + products[i].sales);
            System.out.println("Product profit: " + productProfit);
            grossProfit += productProfit;
        }
        System.out.println("Total store profit: " + grossProfit);
    }

}

public class ProductSale {
    public static void main(String[] args) {
        Store store = new Store();
        while (true) {
            System.out.println("Choose a product: ");
            store.DisplayProducts();
            Scanner sc = new Scanner(System.in);
            try {
                store.BuyProduct(sc.nextInt() - 1);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
            System.out.print("Would you like to continue shopping ? (y/n): ");
            sc.nextLine();
            String response = sc.nextLine();
            if (response.toLowerCase().equals("yes") || response.toLowerCase().equals("y")) continue;
            else break;
        }
        store.CalculateSales();
    }
}
