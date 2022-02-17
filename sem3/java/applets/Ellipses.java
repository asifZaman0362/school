import java.applet.Applet;
import java.awt.*;

public class Ellipses extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.red);
        g.drawString("Ellipses", 10, 10);
        g.setColor(Color.pink);
        g.drawOval(50, 50, 100, 50);
        g.setColor(Color.blue);
        g.drawOval(150, 50, 40, 80);
        g.setColor(Color.yellow);
        g.drawOval(50, 250, 100, 50);
        g.setColor(Color.orange);
        g.drawOval(150, 250, 40, 80);
    }
}

/*
<html>
    <body>
        <applet code="Ellipses.class" width="500" height="500"></applet>
    </body>
</html>
*/