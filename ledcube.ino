int layer[] = {7, 6, 11, 5};
int red[] = {2, A3, 8, A2, 14, 17, 20, 23, 25, 27, 28, 29, 31, 46, 47, 49 }; //17
int green[] = {4, A0, 10, 13, 16, 19, 24, 26, 30, 32, 33, 34, 35, 41, 44, 53}; //16
int blue[] = {3, A1, 9, 12, 15, 18, 21, 22, 36, 37, 38, 42, 43, 45, 51, A4 }; //16
int touchSensor = 52;
int state = 0;
int shoot = 0;
int temp = 4;
void setup() {
  for (int i = 0; i < 16; i++)
    pinMode(blue[i], OUTPUT);
  for (int i = 0; i < 16; i++)
    pinMode(red[i], OUTPUT);
  for (int i = 0; i < 16; i++)
    pinMode(green[i], OUTPUT);
  for (int i = 0; i < 4; i++)
    pinMode(layer[i], OUTPUT);
}
void loop() {
  int touchValue = digitalRead(touchSensor);

  if (touchValue == HIGH && shoot == 0) {     // 터치됨

    if (state == 0) {
  for (int i = 0; i < 16; i++) {
    digitalWrite(blue[i], LOW);
    digitalWrite(red[i], HIGH  );
    digitalWrite(green[i], HIGH);
  }
  for (int x = 225; x > 0; x--) {
    for (int i = 0; i < 4; i++) {
      analogWrite(layer[i], x);
    } delay(20);
  }
    for (int i = 0; i < 16; i++) {
    digitalWrite(red[i], LOW);
    digitalWrite(blue[i], HIGH);
    digitalWrite(green[i], HIGH);
  }
  for (int x = 225; x > 0; x--) {
    for (int i = 0; i < 4; i++) {
      analogWrite(layer[i], x);
    } delay(20);
  }
    for (int i = 0; i < 16; i++) {
    digitalWrite(green[i], LOW);
    digitalWrite(red[i], HIGH);
    digitalWrite(blue[i], HIGH);
  }
  for (int x = 225; x > 0; x--) {
    for (int i = 0; i < 4; i++) {
      analogWrite(layer[i], x);
    } delay(20);
  }
}
      state = 1;
    }
    else {
      for (int i = 0; i < 4; i++) {
        digitalWrite(layer[i], LOW);
      }
      state = 0;
    }
 
  shoot = touchValue;
}
