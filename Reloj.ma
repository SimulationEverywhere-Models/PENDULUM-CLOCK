[top]
components : agujas
components : controlalarma
components : motor
out : CLOCK_ON CLOCK_OFF ALARM_ON ALARM_OFF SOUND_ALARM CLOCK_HOUR CLOCK_MIN ALARM_HOUR ALARM_MIN
in : TURN_ON TURN_OFF ACTIVATE DEACTIVATE INCREMENT DECREMENT INC_ALARM DEC_ALARM
Link : ACTIVATE ACTIVATE@controlalarma
Link : DEACTIVATE DEACTIVATE@controlalarma
Link : INCREMENT INCREMENT@agujas
Link : DECREMENT DECREMENT@agujas
Link : INC_ALARM INCREMENT@controlalarma
Link : DEC_ALARM DECREMENT@controlalarma
Link : HOUR_VALUE@agujas CLOCK_HOUR@controlalarma
Link : MIN_VALUE@agujas CLOCK_MIN@controlalarma
Link : HOUR_VALUE@agujas CLOCK_HOUR
Link : MIN_VALUE@agujas CLOCK_MIN
Link : SOUND_ALARM@controlalarma SOUND_ALARM
Link : ALARM_ON@controlalarma ALARM_ON
Link : ALARM_OFF@controlalarma ALARM_OFF
Link : ALARM_HOUR@controlalarma ALARM_HOUR
Link : ALARM_MIN@controlalarma ALARM_MIN
Link : TURN_ON TURN_ON@motor
Link : TURN_OFF TURN_OFF@motor
Link : TIC@motor TIC@agujas
Link : CLOCK_ON@motor CLOCK_ON
Link : CLOCK_OFF@motor CLOCK_OFF

[agujas]
components : min@AgujaMin
components : hora@AgujaHour
out : HOUR_VALUE MIN_VALUE
in : TIC INCREMENT DECREMENT
Link : VALUE@hora HOUR_VALUE
Link : VALUE@min MIN_VALUE
Link : TIC TIC@min
Link : INCREMENT IN_INCREMENT@min
Link : DECREMENT IN_DECREMENT@min
Link : OUT_INCREMENT@min INCREMENT@hora
Link : OUT_DECREMENT@min DECREMENT@hora

[motor]
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

[controlalarma]
components : agujasAlarma
components : alarma@Alarma
out : ALARM_ON ALARM_OFF SOUND_ALARM ALARM_MIN ALARM_HOUR
in : ACTIVATE DEACTIVATE CLOCK_HOUR CLOCK_MIN INCREMENT DECREMENT
Link : ALARM_ON@alarma ALARM_ON
Link : ALARM_OFF@alarma ALARM_OFF
Link : SOUND_ALARM@alarma SOUND_ALARM
Link : ACTIVATE ACTIVATE@alarma
Link : DEACTIVATE DEACTIVATE@alarma
Link : CLOCK_HOUR CLOCK_HOUR@alarma
Link : CLOCK_MIN CLOCK_MIN@alarma
Link : HOUR_VALUE@agujasAlarma ALARM_HOUR@alarma
Link : MIN_VALUE@agujasAlarma ALARM_MIN@alarma
Link : HOUR_VALUE@agujasAlarma ALARM_HOUR
Link : MIN_VALUE@agujasAlarma ALARM_MIN
Link : INCREMENT INCREMENT@agujasAlarma
Link : DECREMENT DECREMENT@agujasAlarma

[agujasAlarma]
components : minAlarma@AgujaMin
components : horaAlarma@AgujaHour
out : HOUR_VALUE MIN_VALUE
in : TIC INCREMENT DECREMENT
Link : VALUE@horaAlarma HOUR_VALUE
Link : VALUE@minAlarma MIN_VALUE
Link : TIC TIC@minAlarma
Link : INCREMENT IN_INCREMENT@minAlarma
Link : DECREMENT IN_DECREMENT@minAlarma
Link : OUT_INCREMENT@minAlarma INCREMENT@horaAlarma
Link : OUT_DECREMENT@minAlarma DECREMENT@horaAlarma
