#include <Arduino.h>
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#include <ESP32Servo.h>

RF24 radio(4, 5);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network

Servo myservo;  // create servo object to control a servo

const int servoPin    = 22;
const int Pin_PMW1    = 14;

const uint16_t   Master   = 00;      // Address of this node in Octal format ( 04,031, etc)
const uint16_t   Slave    = 01;

int              Angulo   = 0;
int              Duty     = 0; 
int              Datos[]  = {0, 0}; 
unsigned long    previousMillis = 0;

#define PWM_Frecuencia1                5000 // Frecuencia del pwm en Hz 
#define PWM_Canal_1                       2    // Canal del pwm
#define PWM_bit_1                         8    // Resolucion del pwm

void setup() 
{ 
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo.attach(servoPin, 1000, 2000);
  myservo.write(150);
  Serial.begin (115200);

  
  SPI.begin();
  radio.begin();
  network.begin(90, Slave);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS); // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS)
  radio.setPALevel(RF24_PA_MAX); //RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBm, RF24_PA_MAX=0dBm 
  ledcAttachPin(Pin_PMW1, PWM_Canal_1);  
  ledcSetup(PWM_Canal_1,  PWM_Frecuencia1, PWM_bit_1);  // configuracion del modulo pwm   
 
}

void loop() 
{
  network.update();
  bool ok;
  //===== Receiving =====//
  while ( network.available() ) 
  {     // Is there any incoming data?
    Serial.println("Llego");
    RF24NetworkHeader header;    
    network.read(header, &Datos, sizeof(Datos)); // Read the incoming data
    Angulo = Datos[0];
    Duty   = Datos[1]; 
    myservo.write(Angulo);
    ledcWrite(PWM_Canal_1, Duty);    
    Serial.print (Angulo) ;
    Serial.println (Duty) ;
  }

  
 
}
