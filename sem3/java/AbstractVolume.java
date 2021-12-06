import java.util.Scanner;

abstract class Volume {
    public abstract float GetVolume();
}

class Cone extends Volume {

    private float height;
    private float radius;

    private final float PI = 3.14159f;

    public Cone(float pRadius, float pHeight) {
        this.height = pHeight;
        this.radius = pRadius;
    }

    @Override
    public float GetVolume() {
        return 0.3333f * PI * radius * radius * height;
    }

}

class Cylinder extends Volume {

    private float radius;
    private float height;
    
    private final float PI = 3.14159f;

    public Cylinder(float pRadius, float pHeight) {
        this.radius = pRadius;
        this.height = pHeight;
    }

    @Override
    public float GetVolume () {
        return PI * radius * radius * height;
    }

}

public class AbstractVolume {
    public static void main(String[] args) {
        float radiusCyl, radiusCone, heightCyl, heightCone;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the radius of the cylinder:");
        radiusCyl = sc.nextFloat();
        System.out.println("Enter the radius of the cone:");
        radiusCone = sc.nextFloat();
        System.out.println("Enter the height of the cylinder:");
        heightCyl = sc.nextFloat();
        System.out.println("Enter the height of the cone:");
        heightCone = sc.nextFloat();
        Cylinder cyl = new Cylinder(radiusCyl, heightCyl);
        System.out.println("Volume of the cylinder = " + cyl.GetVolume() + " m3");
        Cone cone = new Cone(radiusCone, heightCone);
        System.out.println("Volume of the cone = " + cone.GetVolume() + " m3");
        sc.close();
    }
}