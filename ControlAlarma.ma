[top]
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

