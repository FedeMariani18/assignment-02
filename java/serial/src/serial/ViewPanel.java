package serial;

import javax.swing.JPanel;

import java.awt.Button;
import java.awt.Graphics;

public class ViewPanel extends JPanel{
    
    public ViewPanel(){
        paintButtons();
    }

    public void paintButtons(){
        Button btn = new Button("premi per inviare il messaggio di landing");
        this.add(btn);
    }

    @Override
    public void paintComponent(final Graphics g){
        paintButtons();
    }
}
