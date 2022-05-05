[top]
components : control@ControlEncendido
components : pendulo@Pendulo
out : TIC CLOCK_ON CLOCK_OFF
in : TURN_ON TURN_OFF
Link : TURN_ON TURN_ON@control
Link : TURN_OFF TURN_OFF@control
Link : TIC@pendulo TIC
Link : CLOCK_ON@control TURN_ON@pendulo
Link : CLOCK_OFF@control TURN_OFF@pendulo
Link : CLOCK_ON@control CLOCK_ON
Link : CLOCK_OFF@control CLOCK_OFF
