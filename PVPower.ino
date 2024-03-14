#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>


// Electrical resistance of the solar panel's load
#define RESISTANCE 56

// Number of values to use for calculating the moving average
#define WINDOW 500

// Digital value of the measured voltage
int measure;

// Variables for the calculated voltage, the average voltage an the calculated power produced
float voltage, voltage_avg, power, display;

// Table used to save and calculate the moving average
float voltage_tab[WINDOW];

void setup() {
  // Initialize the analog input pin to be read
  pinMode(A0, INPUT);

  // Set uo serial communication to send data to the computer through USB
  Serial.begin(9600); // open the serial port at 9600 bps:

  // Initialize Circuit Playground library.
  CircuitPlayground.begin();
}

void loop() {
  // Read the input pin
  measure = analogRead(A0);

  // Calculate an analog voltage value from a 10-bit digital number
  voltage = 3.3*(float(measure))/1024;

  // Save the last measured value in a table in the first position, all preceeding values are shifted backward one step
  for(int i = 0; i < WINDOW-1; i++)
  {
    voltage_tab[i+1] = voltage_tab[i]; 
  }
  voltage_tab[0] = voltage;
  
  // Calculate the average of all the voltage values in the table.
  for(int i = 0; i < WINDOW; i++)
  {
    voltage_avg = voltage_avg + voltage_tab[i]; 
  }
  voltage_avg = voltage_avg/WINDOW;

  // Calculate the power produced based on the measured voltage an the load's resistance
  power = voltage_avg * voltage_avg * 1000/RESISTANCE;

  display = 100*voltage_avg / 2.0;

  // Format and send the information through USB to the computer
  Serial.print("Measured voltage [V]: ");
  Serial.print(voltage_avg, 3);
  Serial.print(", Calculated power [mW]: ");
  Serial.print(power, 3);
  Serial.print(", Yield [%]: ");
  Serial.print(display, 3);
  Serial.println();
  
  CircuitPlayground.clearPixels();

  if(display >= 90)
  {
    CircuitPlayground.strip.setPixelColor(0, 0, 100, 0);
    CircuitPlayground.strip.setPixelColor(9, 0, 100, 0);
  }
  if(display >= 100)
  {
    CircuitPlayground.strip.setPixelColor(0, 0, 200, 0);
    CircuitPlayground.strip.setPixelColor(9, 0, 200, 0);
  }


  if(display >= 70)
  {
    CircuitPlayground.strip.setPixelColor(1, 100, 100, 0);
    CircuitPlayground.strip.setPixelColor(8, 100, 100, 0);
  }
  if(display >= 80)
  {
    CircuitPlayground.strip.setPixelColor(1, 200, 200, 0);
    CircuitPlayground.strip.setPixelColor(8, 200, 200, 0);
  }  


  if(display >= 50)
  {
    CircuitPlayground.strip.setPixelColor(2, 100, 50, 0);
    CircuitPlayground.strip.setPixelColor(7, 100, 50, 0);
  }
  if(display >= 60)
  {
    CircuitPlayground.strip.setPixelColor(2, 200, 100, 0);
    CircuitPlayground.strip.setPixelColor(7, 200, 100, 0);
  }


  if(display >= 30)
  {
    CircuitPlayground.strip.setPixelColor(3, 100, 0, 0);
    CircuitPlayground.strip.setPixelColor(6, 100, 0, 0);
  }
  if(display >= 40)
  {
    CircuitPlayground.strip.setPixelColor(3, 200, 0, 0);
    CircuitPlayground.strip.setPixelColor(6, 200, 0, 0);
  }
  

  if(display >= 0)
  {
    CircuitPlayground.strip.setPixelColor(4, 0, 0, 25);
    CircuitPlayground.strip.setPixelColor(5, 0, 0, 25);
  }
  if(display >= 5)
  {
    CircuitPlayground.strip.setPixelColor(4, 0, 0, 100);
    CircuitPlayground.strip.setPixelColor(5, 0, 0, 100);
  }
  if(display >= 10)
  {
    CircuitPlayground.strip.setPixelColor(4, 100, 0, 100);
    CircuitPlayground.strip.setPixelColor(5, 100, 0, 100);
  }
  if(display >= 20)
  {
    CircuitPlayground.strip.setPixelColor(4, 200, 0, 200);
    CircuitPlayground.strip.setPixelColor(5, 200, 0, 200);
  }
  CircuitPlayground.strip.show();
  delay(100);
}
