import java.applet.Applet;
import java.awt.*;

public class LineChart extends Applet {

    public void DrawLineChart(int interval, int[] data, Graphics g) {
        for (int i = 0; i < data.length - 1; i++) {
            g.setColor(Color.blue);
            g.fillOval(interval * (i + 1), data[i + 1], 5, 5);
            g.drawLine(interval * i, data[i], interval * (i + 1), data[i + 1]);
        }
    }

    public void paint(Graphics g) {
        g.setColor(Color.RED);
        g.drawString("Line Graph", 10, 10);
        int[] data = { 200, 400, 250, 350, 100, 450};
        DrawLineChart(50, data, g);
    }

}

/*
<html>
    <body>
        <applet code="LineChart.class" width="500" height="500"></applet>
    </body>
</html>
*/
