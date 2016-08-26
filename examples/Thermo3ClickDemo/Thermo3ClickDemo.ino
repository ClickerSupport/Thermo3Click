/* Thermo 3 Click Demonstration
 * 
 * Reads the temperature
 * 
 * This assynesassumes the address is set to 0. If you should set the 
 * address to 1 then provide the I2C slave address of 73 to the 
 * thermo.begin() function.
 */

#include <Thermo3Click.h>

Thermo3Click thermo;


void setup() {
    Serial.begin(115200);
    thermo.begin();
}

void loop() {
    delay(1000);
    Serial.printf("Temperature: %6.2f C\r\n", thermo.readTemperature());
    Serial.println();
}
