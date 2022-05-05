[top]
components : controlencendido@ControlEncendido
out : CLOCK_ON CLOCK_OFF
in : TURN_ON TURN_OFF
Link : TURN_ON TURN_ON@controlencendido
Link : TURN_OFF TURN_OFF@controlencendido
Link : CLOCK_ON@controlencendido CLOCK_ON
Link : CLOCK_OFF@controlencendido CLOCK_OFF
