#ifndef _LED_H_
#define _LED_H_

class LedSM
{
public:
    enum Event
    {
        TURN_ON,
        TURN_OFF,
        BURN_OUT
    };

    enum State
    {
        OFF,
        ON,
        FINAL
    };

    // Constructor
    LedSM(State initialState = OFF);

    // Accessor method
    State getState(void) const;
    
    // Handle an event based on the current state of the LED
    void handleEvent(Event event);

private:
    // Current state of the LED
    State _state;
    
    // Handle methods for each state
    void handleOff(Event event);
    void handleOn(Event event);
    void handleFinal(Event event);

    // Methods to simulate the current flow through the LED
    void currentOn(void);
    void currentOff(void);
    void printEvent(Event event);
};

#endif /* _LED_H_ */
