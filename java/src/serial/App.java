package serial;

public class App {

    public static void main(final String[] args) throws Exception {
        String portName = "COM3";
        ViewFrame frame = new ViewFrame();
        Controller controller = new Controller(frame, portName);
        controller.loop();
    }
}
