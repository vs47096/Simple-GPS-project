#include <TinyGPS.h>
#include <SoftwareSerial.h>


/*
 UNO/NANO(5V mode)                GPS Neo-6m
    *--------*                      *------*
    | 5V     | <------------------> | VCC  |
    | GND    | <------------------> | GND  |
    | D3(Rx) | <------------------> | Tx   |
    | D4(Tx) | <------------------> | Rx   |
    *--------*                      *------*
*/

float lat = 0.0,lon = 0.0;  
SoftwareSerial gpsSerial(3,4); //Specifying arduino Rx/Tx
TinyGPS gps; // create gps object

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // intialize serial
  gpsSerial.begin(9600); // Initialzie gps sensor
  Serial.println("Setup Done: GPS and Serial Initialized");
}

void loop()
{ 
  while(gpsSerial.available())// check for gps data 
  { 
      if(gps.encode(gpsSerial.read()))// encode gps data 
      {  
          gps.f_get_position(&lat,&lon); // get latitude and longitude 
      } 
  } 
  String latitude = String(lat,6); 
  String longitude = String(lon,6); 
  if(latitude=="0.000000" || longitude=="0.000000")
  {
    Serial.println("Trying to locate..."); 
  }
  else
  {
    Serial.println(latitude+";"+longitude); 
  }
  delay(3000); 
} 
