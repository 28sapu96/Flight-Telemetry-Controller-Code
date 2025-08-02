#include <Servo.h>
//Set up RF channel min & max (Min: 1000 microseconds, Max: 1980 microseconds)
int PWM_MIN = 1000;
int PWM_MAX = 1980; 
//Pin declarations
int ch1 = A0; // RF Channel 1
int ch2 = A1; // RF Channel 2
int ch3 = A2; // RF Channel 3
int ch4 = A3; // RF Channel 4
int S1p = 3;  // PWM Pin (Rudder)
int S2p = 5;  // PWM Pin (Rudder)
int S3p = 6;  // PWM Pin (Rudder)
int S4p = 9;  // PWM Pin (Rudder)
int M1p = 10; // PWM Pin (Engine 1)
int M2p = 11; // PWM Pin (Engine 2)
Servo S1;
Servo S2;
Servo S3;
Servo S4; 
Servo M1;
Servo M2;


void setup()
{
Serial.begin(9600);
pinMode(ch1, INPUT);
pinMode(ch2, INPUT);
pinMode(ch3, INPUT);
pinMode(ch4, INPUT);
S1.attach(S1p);
S2.attach(S2p);
S3.attach(S3p);
S4.attach(S4p);
M1.attach(M1p);
M2.attach(M2p);
// Arm Engine 1
M1.writeMicroseconds(PWM_MAX);
delay(5000);
M1.writeMicroseconds(PWM_MIN);
delay(10000);
// Arm Engine 2
M2.writeMicroseconds(PWM_MAX);
delay(5000);
M2.writeMicroseconds(PWM_MIN);
delay(10000);
                                       
}
void loop()
{
int channel1 = pulseIn(ch1, HIGH); //Yaw stick
int channel2 = pulseIn(ch2, HIGH); //Pitch stick
int channel3 = pulseIn(ch3, HIGH); //Mode switch button
int channel4 = pulseIn(ch4, HIGH); //Engine shutoff/on 
int ch1map = map(channel1, PWM_MIN, PWM_MAX, 50, 130); //Map RF Min/Max to Servo Min/max
int ch2map = map(channel2, PWM_MIN, PWM_MAX, 50, 130); //Map RF Min/Max to Servo MIn/max
Serial.println(channel1);
Serial.println(channel2);
if(channel4 < 1300) //If engine shutoff
{
M1.write(PWM_MIN); //Engine 1 shutoff
M2.write(PWM_MIN); //Engine 2 shutoff
}
else{}
if(channel3 < 1300) //If on ground
{

S1.write(ch1map); //rudder
M1.writeMicroseconds(channel2); //Engine 1 
M2.writeMicroseconds(channel2); //Engine 2

}
else //If in air
   {
S2.write(ch1map); //Left Aileron
S3.write(ch1map); //Right Aileron
S4.write(ch2map); //Elevator
   }
}

