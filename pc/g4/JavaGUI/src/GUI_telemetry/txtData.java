package GUI_telemetry;

import java.awt.Dimension;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSeparator;
import javax.swing.SwingConstants;

public class txtData {

    JPanel txtDataPanel;

    // Labels
    private JLabel lblData = new JLabel("Data");

    // Engine
    private JLabel lblSpeed = new JLabel("Speed:");
    private JLabel lblrpm = new JLabel("RPM:");

    // Temperature
    private JLabel lblwatermotor= new JLabel("Water motor:");
    private JLabel lblwaterrad = new JLabel("Water radiator:");


    public txtData()
    {
        //Text data Panel
        txtDataPanel = new JPanel();
        BoxLayout boxLayout1 = new BoxLayout(txtDataPanel, BoxLayout.Y_AXIS);
        txtDataPanel.setLayout(boxLayout1);
        txtDataPanel.setPreferredSize(new Dimension(200,0));
        txtDataPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 0, 0));
        //txtDataPanel.add(Box.createHorizontalGlue());

        // Data labels
        txtDataPanel.add(lblData);
        txtDataPanel.add(Box.createRigidArea(new Dimension(0, 40)));

        txtDataPanel.add(new JLabel("Engine:"));
        txtDataPanel.add(Box.createRigidArea(new Dimension(0, 15)));

        txtDataPanel.add(lblSpeed);
        txtDataPanel.add(Box.createRigidArea(new Dimension(0, 10)));

        txtDataPanel.add(lblrpm);
        txtDataPanel.add(Box.createRigidArea(new Dimension(0, 10)));

        txtDataPanel.add(new JLabel("Temperature:"));
        txtDataPanel.add(Box.createRigidArea(new Dimension(0, 15)));

        txtDataPanel.add(lblwatermotor);
        txtDataPanel.add(Box.createRigidArea(new Dimension(0, 10)));

        txtDataPanel.add(lblwaterrad);
        txtDataPanel.add(Box.createRigidArea(new Dimension(0, 10)));
    }

    public JPanel getTxtDataPanel()
    {
        return txtDataPanel;
    }

    public void setData(int datanr, int data)
    {
        switch(datanr)
        {
            case 1:  lblSpeed.setText("Speed: " + data); lblSpeed.repaint(); break;
            case 2:  lblrpm.setText("RPM: " + data); lblrpm.repaint(); break;
            case 3:  lblwatermotor.setText("Breake: " + data); lblwatermotor.repaint(); break;
            case 4:  lblwaterrad.setText("Clutch: " + data); lblwaterrad.repaint(); break;
        }
    }
    
}
