

void setup() {
  Serial.begin(115200);
  setupWifiConnection();
  setupMotorPins();
  setMotorStop();
}

void loop() {
  // put your main code here, to run repeatedly:
  char response = checkForConection();

  switch(response){
    case '0':
      setMotorStop();
      Serial.println("stop");
      break;
    case 'u':
      setMotorStop();
      setMotorFoward();
      Serial.println("foward");
      break;
    case 'd':
      setMotorStop();
      setMotorReverse();
      Serial.println("reverse");
      break;
    case 'l':
      setMotorStop();
      setMotorLeft();
      Serial.println("left");
      break;
    case 'r':
      setMotorStop();
      setMotorRight();
      Serial.println("right");
      break;
    default:
      break;
  }
}
