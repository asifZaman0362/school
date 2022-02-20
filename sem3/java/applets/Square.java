import java.applet.Applet;
import java.awt.*;

public class Square extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.red);
        g.drawString("Square", 10, 10);
        g.setColor(Color.blue);
        g.drawRect(40, 40, 100, 100);
    }
}

/*
<html>
    <body>
        <applet code="Square.class" width="500" height="500"></applet>
    </body>
</html>
*/