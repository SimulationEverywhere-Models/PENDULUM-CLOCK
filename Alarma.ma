[top]
components : alarma@Alarma
out : ALARM_ON ALARM_OFF SOUND_ALARM
in : ACTIVATE DEACTIVATE ALARM_HOUR ALARM_MIN CLOCK_HOUR CLOCK_MIN
Link : ALARM_ON@alarma ALARM_ON
Link : ALARM_OFF@alarma ALARM_OFF
Link : SOUND_ALARM@alarma SOUND_ALARM
Link : ACTIVATE ACTIVATE@alarma
Link : DEACTIVATE DEACTIVATE@alarma
Link : ALARM_HOUR ALARM_HOUR@alarma
Link : ALARM_MIN ALARM_MIN@alarma
Link : CLOCK_HOUR CLOCK_HOUR@alarma
Link : CLOCK_MIN CLOCK_MIN@alarma
