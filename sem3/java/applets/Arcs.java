import java.applet.Applet;
import java.awt.*;

public class Arcs extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.RED);
        g.drawString("Arcs", 10, 10);
        g.setColor(Color.GREEN);
        g.drawArc(150, 150, 100, 100, 200, 50);
        g.setColor(Color.PINK);
        g.drawArc(225, 225, 200, 200, 10, 250);
        g.setColor(Color.BLACK);
        g.drawArc(200, 200, 100, 100, 90, 180);
    }
}

/*
<html>
    <body>
        <applet code="Arcs.class" width="500" height="500"></applet>
    </body>
</html>
*/