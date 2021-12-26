package first;
import java.util.Scanner;
import java.lang.Math;

class Complex {
    public float real;
    public float imaginary;
    
    public Complex(float pReal, float pImaginary) {
        real = pReal;
        imaginary = pImaginary;
    }

    public Complex Add(Complex other) {
        return new Complex(this.real + other.real, this.imaginary + other.imaginary);
    }

    public Complex Sub(Complex other) {
        return new Complex(this.real - other.real, this.imaginary - other.imaginary);
    }

    public Complex Mul(Complex other) {
        float _real = (real * other.real) - (imaginary * other.imaginary);
        float _imaginary = (imaginary * other.real + real * other.imaginary);
        return new Complex(_real, _imaginary);
    }

    public String toString() {
        return real + (imaginary >= 0 ? " + " : " - ") + Math.abs(imaginary) + "i";
    }
}

public class ComplexArithmetic {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the real part of the first number: ");
        float real1 = scanner.nextFloat();
        System.out.print("Enter the imaginary part of the first number: ");
        float imaginary1 = scanner.nextFloat();
        System.out.print("Enter the real part of the second number: ");
        float real2 = scanner.nextFloat();
        System.out.print("Enter the imaginary part of the second number: ");
        float imaginary2 = scanner.nextFloat();
        Complex n1 = new Complex(real1, imaginary1);
        Complex n2 = new Complex(real2, imaginary2);
        Complex sum = n1.Add(n2);
        Complex diff = n1.Sub(n2);
        Complex prod = n1.Mul(n2);
        System.out.println("( " + n1 + " ) + ( " + n2 + " ) = ( " + sum + " )");
        System.out.println("( " + n1 + " ) - ( " + n2 + " ) = ( " + diff + " )");
        System.out.println("( " + n1 + " ) * ( " + n2 + " ) = ( " + prod + " )");
        scanner.close();
    }
}
