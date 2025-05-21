#define kpa2atm 0.00986923267  // Conversion factor from kPa to atm

// pin defs
int pressurePin = 0;  // Analog pin connected to MPX4115

// variables
int val;          // Raw analog value from sensor
float voltage;    // Converted analog value to voltage
float pkPa;       // Pressure in kPa
float pAtm;       // Pressure in atm

void setup()
{
  Serial.begin(9600);
  pinMode(pressurePin, INPUT);  // Ensure pressurePin is set to input
}

void loop()
{
  /* Read the analog value from the pressure sensor */
  val = analogRead(pressurePin);  // Read the analog input (0 to 1023)
  
  /* Convert analog value to voltage (5V is the reference voltage) */
  voltage = (val / 1023.0) * 5.0;  // Convert analog reading to voltage (0 to 5V)
  
  /* Convert voltage to pressure in kPa using the MPX4115 transfer function */
  pkPa = (voltage - 0.2) / 0.045;  // Formula from the datasheet: P(kPa) = (Vout - 0.2) / 0.045
  
  /* Convert pressure from kPa to atm */
  pAtm = kpa2atm * pkPa;

  /* Send pressure readings to serial port */
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V, ");
  
  Serial.print("Pressure: ");
  Serial.print(pkPa);
  Serial.print(" kPa, ");
  
  Serial.print(pAtm);
  Serial.println(" atm");

  delay(1000);  // Wait for 1 second
}
