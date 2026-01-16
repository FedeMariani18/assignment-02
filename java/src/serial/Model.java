package serial;

import serial.Common.State;

public class Model {
    private State state;

    public Model(){
        state = State.DRONE_INSIDE;
    }

    public void changeState(State s){
        this.state = s;
    }

    public State getState() {
        return this.state;
    }
}
