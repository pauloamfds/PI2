// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include <stdlib.h>
char c[15];
int a = 0;;
int i = 0;
int j = 0;
float g;
char k[15];

int x = 0;
int howMany = 2;
void setup()
{
  Wire.begin(0x0F);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  Serial.println("Ready");
}

void loop()
{
  //Serial.print("Valor de x: ");
  //Serial.println(x);
  if (a==1){
    Serial.println("Ola");
  a = 0;}
    
  if (a==2){
    Serial.println("Mundo");
  a = 0;
  }
  delay(1000);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()


 
 void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    c[i] = Wire.read(); // receive byte as a character
    Serial.print(c[i]);  
      i++;    // print the character
  }
  i = 0;
  for (j = 2; c[j]; j++)
        k[j-2] = c[j];
        
  g = atof(k);
  a = atoi(c);
  Serial.println(a);
  Serial.println(g);
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}

