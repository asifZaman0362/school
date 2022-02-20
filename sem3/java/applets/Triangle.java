import java.applet.Applet;
import java.awt.*;

public class Triangle extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.red);
        g.drawString("Triangle", 10, 10);
        g.setColor(Color.blue);
        g.drawLine(20, 150, 100, 50);
        g.drawLine(100, 50, 200, 150);
        g.drawLine(200, 150, 20, 150);
    }
}

/*
<html>
    <body>
        <applet code="Triangle.class" width="500" height="500"></applet>
    </body>
</html>
*/