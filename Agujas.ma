[top]
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

