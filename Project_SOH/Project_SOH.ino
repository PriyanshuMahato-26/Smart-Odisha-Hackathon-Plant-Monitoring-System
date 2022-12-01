/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/65a6448b-1f9f-4f8c-9a50-e8c64e53b813 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  CloudLight relay_motor;
  int sm_sensor;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
int relay1 = D4;
int soil_moisture = A0;
int sensor_pin = A0;
int output_value ;


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
pinMode(relay1,OUTPUT);
 Serial.println("Reading From the Sensor ...");
  delay(2000);
 pinMode(D3,OUTPUT);
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
sm_sensor = analogRead(soil_moisture);
delay(500);
output_value = analogRead(sensor_pin); 
 output_value = map(output_value,750,180,0,100);
    Serial.print("Moisture : "); 
 Serial.print(output_value);
  Serial.print("%\n");   
 delay(1000);
 if(output_value > 20 && output_value<50)
 {
    digitalWrite(D4,LOW);
 }
 else {
  digitalWrite(D4,HIGH);
 }
 delay(1000);
  
//if (sm_sensor>30 )
{//\
  digitalWrite(relay1,HIGH);
}
//else
{
  //digitalWrite(relay1,LOW);
}
}


/*
  Since Switch1 is READ_WRITE variable, onSwitch1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onSwitch1Change()  {
  // Add your code here to act upon Switch1 change
  if(relay_motor == 1)
  {
    digitalWrite(relay1,HIGH);
  }
  else
  {
    digitalWrite(relay1,LOW);
  }
}




/*
  Since RelayMotor is READ_WRITE variable, onRelayMotorChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onRelayMotorChange()  {
  // Add your code here to act upon RelayMotor change
  if(relay_motor == 1)
  {
    digitalWrite(relay1,HIGH);
  }
  else
  {
    digitalWrite(relay1,LOW);
  }
}





/*
  Since Message is READ_WRITE variable, onMessageChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMessageChange()  {
  // Add your code here to act upon Message change
 
}