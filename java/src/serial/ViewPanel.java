package serial;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.JPanel;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Component;
import java.awt.TextArea;
import java.awt.event.ActionListener;
import java.awt.Font;

public class ViewPanel extends JPanel{
    private int baseFontSize = 18;
    
    private Button btn;
    private TextArea textArea;
    private JLabel label;

    public ViewPanel(){
        setLayout(new BorderLayout());
    

        paintTextArea();
        paintRightPanel();
    }

    public void paintRightPanel(){
        JPanel rightPanel = new JPanel();
        rightPanel.setLayout(new BoxLayout(rightPanel, BoxLayout.Y_AXIS));

        label = new JLabel("");
        label.setForeground(Color.GREEN);
        label.setAlignmentX(Component.CENTER_ALIGNMENT);

        btn = new Button("");
        rightPanel.add(label);
        rightPanel.add(Box.createVerticalStrut(10)); // spazio
        rightPanel.add(btn);

        add(rightPanel, BorderLayout.EAST);
    }

    public void addButtonListener(ActionListener l) {
        btn.addActionListener(l);
    }

    public void paintTextArea(){
        textArea = new TextArea();
        textArea.setEnabled(false);
        this.add(textArea, BorderLayout.CENTER); 
        textArea.setFont(new Font(Font.MONOSPACED, Font.PLAIN, baseFontSize));
    }

    public void clearTextArea(){
        textArea.setText("");
    }

    public void writeInTextArea(String s){
        textArea.append(s);
    }

    public void updateState(String s){
        label.setText(s);
    }

    public void updateAction(String s){
        btn.setLabel(s);
    }

    public void updateButtonEnabled(boolean enabled) {
        btn.setEnabled(enabled);
    }


    public void setFontSize(int size){
        if(size <= 0) return;
        baseFontSize = size;
        Font labelFont = new Font(Font.SANS_SERIF, Font.PLAIN, baseFontSize);
        Font btnFont = new Font(Font.SANS_SERIF, Font.PLAIN, baseFontSize);
        Font taFont = new Font(Font.MONOSPACED, Font.PLAIN, baseFontSize);

        if(label != null) label.setFont(labelFont);
        if(btn != null) btn.setFont(btnFont);
        if(textArea != null) textArea.setFont(taFont);
        revalidate();
        repaint();
    }
}
