#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

RF24 radio(4, 5);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network

const int analog_servo   = 36;
const int analog_pwm     = 39;

const uint16_t Master = 00;      // Address of this node in Octal format ( 04,031, etc)
const uint16_t Slave  = 01;      // Address of the other node in Octal format

int Datos[] = {0, 0};
unsigned long previousMillis = 0;

void setup() 
{
  SPI.begin();
  Serial.begin (115200);
  radio.begin();
  network.begin(90, Master);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS); // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS)
  radio.setPALevel(RF24_PA_MAX); //RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBm, RF24_PA_MAX=0dBm
  analogSetWidth(12);                       // 12 bits de resolucion 
  analogSetAttenuation(ADC_11db);
  analogSetPinAttenuation (analog_servo,ADC_11db); 
  analogSetPinAttenuation (analog_pwm,ADC_11db); 
   
}

void loop() 
{
  network.update();    
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 500) 
  {
    previousMillis = currentMillis;
    Datos[0] = map(analogRead(analog_servo), 0, 4096, 0, 180);   
    Datos[1] = map(analogRead(analog_pwm),   0, 4096, 0, 255);
    
    RF24NetworkHeader header(Slave);     // (Address where the data is going)
    bool ok = network.write(header, &Datos, sizeof(Datos)); // Send the data   
  }
}
