# Arduino-Blucar
int motorA[] = {4, 5};
int motorB[] = {6, 7};
int kecepatan[] = {9, 10};
String data;
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 2; i++)
  {
    pinMode(motorA[i], OUTPUT);
    pinMode(motorB[i], OUTPUT);
    pinMode(kecepatan[i], OUTPUT);
  }
  // put your setup code here, to run once:

}

void loop() {

  while (Serial.available() > 0)
  {
    char a = Serial.read();
    data += String(a);
    delay(2);
  }

  if (data != String())
  {
    String trig, kecep; int cepat;

    kecep = data.substring(1, 4);
    cepat = kecep.toInt();
    trig = data.substring(0, 1);
    analogWrite(kecepatan[0], cepat);
    analogWrite(kecepatan[1], cepat);

    if (trig == "A")
    {
      Serial.println("maju");
      digitalWrite(motorA[0], 1);
      digitalWrite(motorA[1], 0);
      digitalWrite(motorB[0], 1);
      digitalWrite(motorB[1], 0);
    }
    else if (trig == "B")
    {
      Serial.println("Mundur");
      digitalWrite(motorA[0], 0);
      digitalWrite(motorA[1], 1);
      digitalWrite(motorB[0], 0);
      digitalWrite(motorB[1], 1);
    }
    else if (trig == "C")
    {
      Serial.println("belok");
      digitalWrite(motorA[0], 1);
      digitalWrite(motorA[1], 0);
      digitalWrite(motorB[0], 0);
      digitalWrite(motorB[1], 1);
    }
    Serial.print("status : " + trig + "  kec : " + String(cepat));
    data = String();
  }
}
