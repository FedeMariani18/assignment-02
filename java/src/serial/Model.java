package serial;

import serial.Common.*;

public class Model {
    private State state;
    private AlarmState alarmState;

    public Model(){
        state = State.DRONE_INSIDE;
        alarmState = AlarmState.NORMAL;
    }

    public void changeState(State s){
        this.state = s;
    }

    public State getState() {
        return this.state;
    }

    public void changeAlarmState(AlarmState as){
        this.alarmState = as;
    }

    public AlarmState getAlarmState() {
        return this.alarmState;
    }
}
