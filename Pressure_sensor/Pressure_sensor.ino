#define kpa2atm 0.00986923267

int pressurePin = 0;
int val;        
float voltage;   
float pkPa;       
float pAtm;       

void setup()
{
  Serial.begin(9600);
  pinMode(pressurePin, INPUT);
}

void loop()
{
  val = analogRead(pressurePin);  // Read the analog input (0 to 1023)
  
  voltage = (val / 1023.0) * 5.0;  // Convert analog reading to voltage (0 to 5V)
  
  pkPa = (voltage - 0.2) / 0.045;

  pAtm = kpa2atm * pkPa;

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V, ");
  
  Serial.print("Pressure: ");
  Serial.print(pkPa);
  Serial.print(" kPa, ");
  
  Serial.print(pAtm);
  Serial.println(" atm");

  delay(1000);
}
