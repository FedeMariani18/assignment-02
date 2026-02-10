package serial;

public class Common {
    public enum State{
        DRONE_INSIDE,
        TAKE_OFF,
        DRONE_OUT,
        LANDING
    }

    public enum AlarmState{
        NORMAL,
        ALARM
    }
}
