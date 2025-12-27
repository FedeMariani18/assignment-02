package serial;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.JPanel;

import serial.Common.State;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Component;
import java.awt.TextArea;
import java.awt.event.ActionListener;

public class ViewPanel extends JPanel{
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
        System.out.println("creato bottone");
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

    public void updateButtonEnabled(State s) {
        switch (s) {
            case State.LANDING:
            case State.TAKE_OFF:
                btn.setEnabled(false);
                break;
            case State.DRONE_INSIDE:
            case State.DRONE_OUT:
                btn.setEnabled(true);
                break;
        }
    }
}
