int relay = D0; //pin to which relay is connected
int boardLed = D7;
bool vin = LOW; //a virtual boolean variable

// setup() is run only once, it's where we set up GPIO and initialise peripherals
void setup() {
    
  // Setup GPIO
  pinMode(relay,OUTPUT); // relay pin is set as output
  digitalWrite(relay,HIGH);
  // Subscribe to events published by IFTTT using Particle.subscribe
  Particle.subscribe("mylight_assistant_on", myHandler); //turning off function declaration
  Particle.subscribe("mylight_assistant_off", thisHandler); //turning on function declaration
}

// loop() runs continuously, it's our infinite loop.
void loop() {
     if (vin==HIGH)
     {
         digitalWrite(relay,LOW);
     }
else if (vin==LOW)
      {
         digitalWrite(relay,HIGH);
     }

}

//our events are called when IFTTT applets are triggered
void myHandler(const char *event, const char *data)
{
    vin=LOW;
}
void thisHandler(const char *event, const char *data)
{
     vin=HIGH;
}