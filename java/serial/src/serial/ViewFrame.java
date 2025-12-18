package serial;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class ViewFrame {
    private JFrame frame;

    static final int WIDTH = 1000;
    static final int HEIGHT = 1000;

    public ViewFrame(){
        frame = new JFrame("DRU");
        frame.setSize(WIDTH, HEIGHT);
        this.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
    }

    public void setPanel(final JPanel panel) {
        this.frame.setContentPane(panel);
        this.frame.revalidate();
        this.frame.repaint();
        panel.requestFocus();
        this.frame.pack();
        this.frame.setVisible(true);
    }
}
