package serial;

import serial.Common.State;

public class Controller {
    ViewPanel panel;
    Model model;

    public Controller(ViewFrame frame){
        panel = new ViewPanel();
        panel.addButtonListener(e -> {
            buttonPressed();
        });
        frame.setPanel(panel);
        model = new Model();
        init();
    }

    public void init(){
        updateChanges();
    }

    public void loop(){
        while(true){
            updateChanges();
        }
    }

    public void buttonPressed(){
        System.out.println("bottone premuto " + model.getState());
        switch (model.getState()) {
            case State.REST:
                model.chancheState(State.TAKING_OFF);
                break;
            case State.OPERATING:
                model.chancheState(State.LANDING);
                break;
            default:
        }
        System.out.println(model.getState());
    }

    private void updateChanges(){
        State s = model.getState();
        panel.updateState(fromStateToString(s));
        panel.updateAction(getAction(s));
        panel.updateButtonEnabled(s);
    }

    private String fromStateToString(State state){
        switch(state){
            case State.REST:
                return "REST";
            case State.TAKING_OFF:
                return "TAKING_OFF";
            case State.OPERATING:
                return "OPERATING";
            case State.LANDING:
                return "LANDING";
        }
        return "Errore negli stati";
    } 

    private String getAction(State state){
        switch (state) {
            case State.TAKING_OFF:
            case State.REST:
                return "press to Take Off";
            case State.LANDING:
            case State.OPERATING:
                return "press to Land";
        }
        return "Errore";
    }
}
