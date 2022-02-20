import java.applet.Applet;
import java.awt.*;

public class Circles extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.RED);
        g.drawString("Circles", 10, 10);
        g.setColor(Color.GREEN);
        g.drawOval(150, 150, 100, 100);
        g.setColor(Color.PINK);
        g.drawOval(225, 225, 200, 200);
        g.setColor(Color.BLACK);
        g.drawOval(200, 200, 100, 100);
    }
}

/*
<html>
    <body>
        <applet code="Circles.class" width="500" height="500"></applet>
    </body>
</html>
*/
