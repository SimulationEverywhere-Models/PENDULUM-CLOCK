Simulacion de Eventos Discretos

Trabajo Practico 1
Antiguo Reloj Despertador

Grupo 1

Julio Kriger
L.U. 207/96
jkriger@dc.uba.ar

----------------------------------------------------------------------

Instrucciones para compilar, linkeditar y probar el simulador de
Antiguo reloj despertador.

Nota: El simulador incluye la libreria "libsimu.a" para Windows.
Se compila y linkedita con CygWin. Para utilizar el simulador bajo
Linux solo basta con reemplazar la libreria "libsimu.a" con la
libreria correspondiente a Linux.

Utilizando tanto CygWin o Linux:

1) Copiar el archivo "cd++.zip" a un directorio de trabajo limpio.

2) Deszippear el archivo "cd++.zip". Atencion que el zip contiene
una estructura de subdirectorios propios del simulador.

3) Una vez dezippeado el archivo deberia quedar la siguiente
extructura de directorio:

cd++ --> archivos fuente necesarios + libsimu.a
cd++\Acoplados --> archivos ".ma" y ".ev" de los modelos acoplados
cd++\Atomicos --> archivos ".ma" y ".ev" de los modelos atomicos
cd++\Reloj --> archivos fuente del antiguo reloj despertador
cd++\TestScripts --> scripts para realizar test de los modelos
cd++\TestsResults --> archivos de resultado de los scripts

3-opcional) Si se esta utilizando Linux, reemplazar la libreria
"libsimu.a" en "cd++" por la correspondiente de Linux.

4) Dentro del directorio "cd++" ejecutar "make".

5) Dentro del directorio "cd++\TestScripts" se pueden ejecutar los
siguientes scripts para testear los modelos atomicos y acoplados
descriptos en el documento "tp1_grupo1_sed.pdf". Los resultados de
la simulacion quedan en el directorio "cd++\TestsResults". Para
modificar los eventos de la simulacion se pueden modificar los
archivos ".ev" de los directorios "cd++\Acoplados" y
"cd++\Atomicos".

