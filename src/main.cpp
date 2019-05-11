#include <Arduino.h>

void setup() {
  //pin setup of the ATTiny pins
  int bluePin = 2;
  int redPin = 3;
  int greenPin = 6;
  int MAX6608Out = 5;

  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(MAX6608Out, INPUT);


  //variable setup
  int     tempInVolts = 0;
  float   tempInCelcius = 0;
  char    LEDcolor;
  


  //set up serial 
  Serial.begin(9600);
}


void getTemp()
{
 //read the analog voltage from the temperature IC

  tempInVolts = analogRead(Max6608Out);




  //convert the voltage from the temperature IC and convert it to temperature 
  //temperature is in Celcius because I don't want to do that C -> F math

  tempInCelcius = (tempInVolts - 0.5)/ 0.01;


}



void selectColor()
{
//IF statements depending on temperature to denote a color the LEDs should 
  //light. The order of colors is:
  //Blue -> Cyan -> Green -> Yellow -> Magenta -> Red
  //Each color represents 1 degree Celcius, starting at 35 degrees C. 
  if(tempInCelcius =< 35)
  {
    LEDcolor = "blue";
  }
  elsif(tempInCelcius > 35 && tempInCelcius =< 36)
  {
    LEDcolor = "cyan";
  }
  elsif(tempInCelcius > 36 && tempInCelcius =< 37)
  {
    LEDcolor = "green";
  } 
  elsif(tempInCelcius > 37 && tempInCelcius =< 38)
  {
    LEDcolor = "yellow";
  }
  elsif(tempInCelcius > 38 && tempInCelcius =< 39)
  {
    LEDcolor = "magenta";
  }
  elsif(tempInCelcius >39 && tempInCelcius =< 40)
  {
    LED color = "red";
  }
}



void resetLEDS()
{
 //turn off all the LEDs so there aren't stray colors
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenpin, LOW);
}


void turnOnLEDS()
{
//switch statment to turn on the colors
  switch(LEDcolor)
  {
    case "cyan":
      digitalWrite(greenPin, HIGH);
    case "blue":
      digitalWrite(bluePin, HIGH);
      break;
    case "yellow":
      digitalWrite(redPin, HIGH);
    case "green":
      digitalWrite(greenPin, HIGH);
      break;
    case "magenta":
      digitalWrite(bluePin, HIGH);
    case "red":
      digitalWrite(redPin, HIGH);
      break;
  }
}



void loop() {
 
  getTemp();

              Serial.print("tempInVolts = ");
              Serial.prinln(tempInVolts);
              
              Serial.print("tempInCelcius = ");
              Serial.println(tempInCelcius);


  selectColor();

              Serial.print("LEDcolor = ");
              Serial.println(LEDcolor);


 
  resetLEDS();
  turnOnLEDS();
  

  //delay a little bit
  delay(1000);

}