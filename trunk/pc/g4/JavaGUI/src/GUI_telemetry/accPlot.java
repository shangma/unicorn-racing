package GUI_telemetry;

import javax.swing.*;
import java.awt.*;

public class accPlot extends JPanel{

    private static Color bgcolor = Color.darkGray;

    public void paintComponent(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        // Antialiasing for glatte kurver
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                            RenderingHints.VALUE_ANTIALIAS_ON);

        g2.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING,
                            RenderingHints.VALUE_TEXT_ANTIALIAS_LCD_HRGB);

        // Baggrund
        int h = getHeight();  // Panelets højde
        int w = getWidth();   // Panelets bredde

        g2.setColor(bgcolor);
        g2.fill(new Rectangle(0, 0, w, h));
    }
}