
int rin1Pin    = 4;
int rin2Pin    = 5;

int lin1Pin    = 2;
int lin2Pin    = 15;

void setupMotorPins(){  
  pinMode(rin1Pin   , OUTPUT);
  pinMode(rin2Pin   , OUTPUT);
  
  pinMode(lin1Pin   , OUTPUT);
  pinMode(lin2Pin   , OUTPUT);
}
void setMotorStop(){
  digitalWrite(rin1Pin, false);
  digitalWrite(rin2Pin, false);
  digitalWrite(lin1Pin, false);
  digitalWrite(lin2Pin, false);
}
void setMotorFoward(){
  digitalWrite(rin1Pin, false);
  digitalWrite(rin2Pin, true);
  digitalWrite(lin1Pin, true);
  digitalWrite(lin2Pin, false);
}
void setMotorReverse(){
  digitalWrite(rin1Pin, true);
  digitalWrite(rin2Pin, false);
  digitalWrite(lin1Pin, false);
  digitalWrite(lin2Pin, true);
}
void setMotorLeft(){
  digitalWrite(rin1Pin, false);
  digitalWrite(rin2Pin, true);
  digitalWrite(lin1Pin, false);
  digitalWrite(lin2Pin, true);
}
void setMotorRight(){
  digitalWrite(rin1Pin, true);
  digitalWrite(rin2Pin, false);
  digitalWrite(lin1Pin, true);
  digitalWrite(lin2Pin, false);
}
