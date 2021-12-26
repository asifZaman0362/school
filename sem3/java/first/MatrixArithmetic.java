package first;
import java.util.Scanner;

class Matrix {
    private int[][] entries;
    private int m, n;

    public Matrix(int x, int y) {
        m = x;
        n = y;
        entries = new int[x][y];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                entries[i][j] = 0;
    }

    public int GetRowCount() {
        return m;
    }

    public int GetColumnCount() {
        return n;
    }

    public void SetElementAt(int x, int y, int value) {
        if (x > m || y > n) {
            System.out.println("Invalid position!");
            return;
        }
        entries[x][y] = value;
    }

    public int GetElementAt(int x, int y) {
        return entries[x][y];
    }

    public Matrix Mul(Matrix other) {
        if (n != other.m) {
            System.out.println("Matrices cannot be multiplied!");
            return null;
        }
        Matrix prod = new Matrix(m, other.n);
        for (int i = 0; i < prod.m; i++) {
            for (int j = 0; j < prod.n; j++) {
                for (int k = 0; k < n; k++) {
                    prod.entries[i][j] +=  entries[i][k] * other.entries[k][j];
                }
            }
        }
        return prod;
    }

    public Matrix Add(Matrix other) {
        if (m != other.m || n != other.n) {
            System.out.println("Cannot add matrices!");
            return null;
        }
        Matrix sum = new Matrix(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum.entries[i][j] = entries[i][j] + other.entries[i][j];
            }
        }
        return sum;
    }

    public void Print() {
        for (int i = 0; i < m; i++) {
            System.out.print("|\t");
            for (int j = 0; j < n; j++) {
                System.out.print(entries[i][j] + "\t");
            }
            System.out.print("|\n");
        }
    }
}

public class MatrixArithmetic {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of rows of the first matrix: ");
        int m = scanner.nextInt();
        System.out.print("Enter the number of columns of the first matrix: ");
        int n = scanner.nextInt();
        Matrix A = new Matrix(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("Enter the element[" + i + "][" + j + "]: ");
                A.SetElementAt(i, j, scanner.nextInt());
            }
        }
        System.out.print("Enter the number of rows of the second matrix: ");
        int o = scanner.nextInt();
        System.out.print("Enter the number of columns of the second matrix: ");
        int p = scanner.nextInt();
        Matrix B = new Matrix(o, p);
        for (int i = 0; i < o; i++) {
            for (int j = 0; j < p; j++) {
                System.out.print("Enter the element[" + i + "][" + j + "]: ");
                B.SetElementAt(i, j, scanner.nextInt());
            }
        }
        Matrix prod = A.Mul(B);
        Matrix sum = A.Add(B);
        System.out.println("The sum of the matrices:\n");
        prod.Print();
        System.out.println("The product of the matrices:\n");
        sum.Print();
        scanner.close();
    }
}
