import java.applet.Applet;
import java.awt.*;

public class Rectangles extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.red);
        g.drawString("Rectangles", 10, 10);
        g.setColor(Color.pink);
        g.drawRect(50, 50, 100, 50);
        g.setColor(Color.blue);
        g.drawRect(150, 50, 40, 80);
        g.setColor(Color.yellow);
        g.drawRect(50, 250, 100, 50);
        g.setColor(Color.orange);
        g.drawRect(150, 250, 40, 80);
    }
}

/*
<html>
    <body>
        <applet code="Rectangles.class" width="500" height="500"></applet>
    </body>
</html>
*/