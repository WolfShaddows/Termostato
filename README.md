### Conexiónes
### Sensor de Temperatura DS18B20:

Conecta el pin de datos (patita del medio) al pin digital 2 del Arduino.
Conecta el pin de alimentación (patita derecha) al 5V del Arduino.
Conecta el pin de tierra (patita izquierda) al GND del Arduino.
### Servo Motor:

Conecta el cable de control del servo al pin digital 9 del Arduino.
Conecta el cable de alimentación del servo al 5V del Arduino.
Conecta el cable de tierra del servo al GND del Arduino.
### LCD I2C (pantalla):

Conecta el pin SDA de la pantalla al pin A4 del Arduino.
Conecta el pin SCL de la pantalla al pin A5 del Arduino.
Conecta el pin VCC de la pantalla al 5V del Arduino.
Conecta el pin GND de la pantalla al GND del Arduino.
### Potenciómetro (simula la temperatura deseada):

Conecta el pin central del potenciómetro al pin analógico A0 del Arduino.
Conecta los extremos del potenciómetro a 5V y GND del Arduino.

Las funciones específicas del dispositivo son las siguientes:

### Obtener Temperatura:

Utiliza el sensor DS18B20 para medir la temperatura ambiente.
La función obtenerTemperatura() solicita la temperatura al sensor y la devuelve.
### Mostrar Temperatura en el LCD:

Utiliza la pantalla LCD I2C para mostrar la temperatura actual y la temperatura deseada.
La función mostrarTemperaturaLCD(float temp) muestra la temperatura actual y la deseada en la pantalla.
Controlar la Calefacción con el Servo Motor:

Si la temperatura actual es mayor que la deseada, simula activar la calefacción girando el servo a 90 grados.
Si la temperatura actual es menor o igual que la deseada, simula desactivar la calefacción girando el servo a 0 grados.
Las funciones `activarCalefaccion()` y `desactivarCalefaccion()` controlan el movimiento del servo.

Estamos utilizando un potenciómetro para simular el sensor de temperatura. En un entorno real, este sensor detectaría la temperatura ambiente. El código simula el control de una calefacción basada en la temperatura detectada por el potenciómetro.

En el código, la función `activarCalefaccion()` se llama si la temperatura detectada es mayor que la temperatura deseada (tempDeseada), y la función `desactivarCalefaccion()` se llama si la temperatura detectada es igual o menor que la temperatura deseada.

En la simulación, este comportamiento se emula para mostrar cómo se podría controlar una calefacción basándote en la temperatura detectada por el sensor. En un entorno real, se podría reemplazar la simulación con un sensor de temperatura real que envíe datos a tu Arduino.
