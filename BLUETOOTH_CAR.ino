//Arduino Bluetooth Controlled Car//
// Before uploading the code you have to install the necessary library//
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install //



//initial motors pin
int motorA[] = {4, 5};
int motorB[] = {6, 7};
int kecepatan[] = {9, 10};

char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  for (int i = 0; i < 2; i++)
  {
    pinMode(motorA[i], OUTPUT);
    pinMode(motorB[i], OUTPUT);
    pinMode(kecepatan[i], OUTPUT);
  }
}

void loop(){
  if(Serial1.available() > 0){ 
    command = Serial1.read(); 
    //Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    }
  } 
}

void forward()
{
      digitalWrite(motorA[0], 1);
      digitalWrite(motorA[1], 0);
      digitalWrite(motorB[0], 1);
      digitalWrite(motorB[1], 0);
}

void back()
{
      digitalWrite(motorA[0], 0);
      digitalWrite(motorA[1], 1);
      digitalWrite(motorB[0], 0);
      digitalWrite(motorB[1], 1);
}

void left()
{
      digitalWrite(motorA[0], 1);
      digitalWrite(motorA[1], 0);
      digitalWrite(motorB[0], 0);
      digitalWrite(motorB[1], 1);
}

void right()
{
      digitalWrite(motorA[0], 1);
      digitalWrite(motorA[1], 0);
      digitalWrite(motorB[0], 0);
      digitalWrite(motorB[1], 1);
} 

void Stop()
{
      digitalWrite(motorA[0], 0);
      digitalWrite(motorA[1], 0);
      digitalWrite(motorB[0], 0);
      digitalWrite(motorB[1], 0);
}
