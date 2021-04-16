
void setup() {
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(4,1);
  digitalWrite(7,1);
}


void loop(){
  analogWrite(5,0);
  analogWrite(9,0);
  analogWrite(3,0);
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(6, fadeValue);
    delay(30);
  }
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(6, fadeValue);
    delay(30);
  }

  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(3,0);
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(5, fadeValue);
    delay(30);
  }
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(5, fadeValue);
    delay(30);
  }

  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(3,0);
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(9, fadeValue);
    delay(30);
  }
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(9, fadeValue);
    delay(30);
  }

  analogWrite(5,0);
  analogWrite(9,0);
  analogWrite(6,0);
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(3, fadeValue);
    delay(30);
  }
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(3, fadeValue);
    delay(30);
  }
}
