import java.lang.Math;

class Triangle {
    private float s1;
    private float s2;
    private float s3;

    public Triangle() {
        s1 = 3;
        s2 = 4;
        s3 = 5;
    }

    public float GetArea() {
        float s = (s1 + s2 + s3) / 2.0f;
        float area = (float) Math.sqrt(s * (s - s1) * (s - s2) * (s - s3));
        return area;
    }

    public float GetPerimeter() {
        float perimeter = s1 + s2 + s3;
        return perimeter;
    }
}

public class TrianglePerimeterArea {
    public static void main(String[] args) {
        Triangle tri = new Triangle();
        System.out.println("Area of the triangle = " + tri.GetArea());
        System.out.println("Perimeter of the triangle = " + tri.GetPerimeter());
    }
}
