import java.applet.Applet;
import java.awt.*;

public class Lines extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.red);
        g.drawString("Lines", 10, 10);
        g.setColor(Color.blue);
        g.drawLine(20, 40, 60, 80);
        g.setColor(Color.black);
        g.drawLine(50, 100, 60, 200);
        g.setColor(Color.green);
        g.drawLine(50, 10, 100, 200);
    }
}

/*
<html>
    <body>
        <applet code="Lines.class" width="500" height="500"></applet>
    </body>
</html>
*/