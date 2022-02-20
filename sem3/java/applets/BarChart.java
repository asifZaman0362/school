import java.applet.Applet;
import java.awt.*;

public class BarChart extends Applet {

    public void DrawBarChart(int interval, int[] data, Graphics g) {
        int max = 0;
        for (int i = 0; i < data.length; i++) {
            if (data[i] > max) max = data[i];
        }
        for (int i = 0; i < data.length; i++) {
            g.setColor(Color.blue);
            g.fillRect(50 + i * interval, 50 + max - data[i], 20, data[i]);
        }
    }

    public void paint(Graphics g) {
        g.setColor(Color.RED);
        g.drawString("Bar Chart", 10, 10);
        int[] data = { 200, 400, 250, 350, 100, 450};
        DrawBarChart(50, data, g);
    }

}

/*
<html>
    <body>
        <applet code="BarChart.class" width="500" height="500"></applet>
    </body>
</html>
*/