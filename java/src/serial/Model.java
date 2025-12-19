package serial;

import serial.Common.State;

public class Model {
    private State state;

    public Model(){
        state = State.REST;
    }

    public void chancheState(State s){
        this.state = s;
    }

    public State getState() {
        return this.state;
    }
}
