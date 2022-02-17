import java.applet.Applet;
import java.awt.*;

public class Face extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.RED);
        g.drawString("Human Face", 10, 10);
        g.setColor(Color.YELLOW);
        g.fillOval(150, 150, 150, 200);
        g.setColor(Color.white);
        g.fillOval(170, 200, 50, 50);
        g.fillOval(230, 200, 50, 50);
        g.setColor(Color.black);
        g.fillOval(180, 210, 30, 30);
        g.fillOval(240, 210, 30, 30);
        g.setColor(Color.pink);
        g.fillOval(190, 280, 70, 30);
    }
}

/*
<html>
    <body>
        <applet code="Face.class" width="500" height="500"></applet>
    </body>
</html>
*/