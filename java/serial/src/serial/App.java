package serial;

public class App {
    
    private App(){}

    public static void main(final String[] args) {
        ViewFrame frame = new ViewFrame();
        frame.setPanel(new ViewPanel());
    }
}
