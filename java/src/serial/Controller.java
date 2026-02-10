package serial;

import serial.Common.AlarmState;
import serial.Common.State;

public class Controller {
    private ViewPanel panel;
    private Model model;
    private SerialCommChannel commChannel;

    public Controller(ViewFrame frame, String port) throws Exception {
        panel = new ViewPanel();
        panel.addButtonListener(e -> {
            buttonPressed();
        });
        frame.setPanel(panel);
        model = new Model();
        commChannel = new SerialCommChannel(port, 115200);
        init();
    }

    public void init() throws InterruptedException{
        updateChanges();
    }

    public void loop() throws InterruptedException{
        while(true){
            updateChanges();
            Thread.sleep(10);
        }
    }

    public void buttonPressed(){

        System.out.println("bottone premuto " + model.getState());
        switch (model.getState()) {
            case State.DRONE_INSIDE:
                commChannel.sendMsg(fromStateToString(State.TAKE_OFF));
                break;
            case State.DRONE_OUT:
                commChannel.sendMsg(fromStateToString(State.LANDING));
                break;
            default:
        }
        System.out.println(model.getState());
    }

    private void updateChanges() throws InterruptedException{
        updateStateFromMsg();
        // AlarmState as = model.getAlarmState();
        // panel.updateButtonEnabled(as);

        State s = model.getState();
        panel.updateState(fromStateToString(s));
        panel.updateAction(getAction(s));

        boolean enabled = 
        model.getAlarmState() == AlarmState.NORMAL &&
        (s == State.DRONE_INSIDE || s == State.DRONE_OUT);


        panel.updateButtonEnabled(enabled);
    }

    private String fromStateToString(State state){
        switch(state){
            case State.DRONE_INSIDE:
                return "DRONE_INSIDE";
            case State.TAKE_OFF:
                return "TAKE_OFF";
            case State.DRONE_OUT:
                return "DRONE_OUT";
            case State.LANDING:
                return "LANDING";
        }
        return "Errore negli stati";
    } 

    private String getAction(State state){
        switch (state) {
            case State.TAKE_OFF:
            case State.DRONE_INSIDE:
                return "press to Take Off";
            case State.LANDING:
            case State.DRONE_OUT:
                return "press to Land";
        }
        return "Errore";
    }

    private void updateStateFromMsg() throws InterruptedException{
        if(commChannel.isMsgAvailable()){
            String msg = commChannel.receiveMsg();
            panel.clearTextArea();
            panel.writeInTextArea(msg);

            String[] parts = msg.split(";");

            if (parts.length >= 1) {
                // ALARM STATE
                AlarmState alarm = commChannel.transformMsgToAlarmState(parts[0]);
                if (alarm != null) {
                    model.changeAlarmState(alarm);
                }
            }

            if (parts.length >= 2) {
                // DRONE STATE
                State drone = commChannel.transformMsgToState(parts[1]);
                if (drone != null) {
                    model.changeState(drone);
                }
            }
        }
    }
}
