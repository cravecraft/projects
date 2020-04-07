
  int red_button=2;
  int green_button=4;
  int blue_button=7;
  int yellow_button=8;
  int white_button=9;
  int dim_Button=10; // analog input pin to use as a digital input
  int red=6;
  int green=5;
  int blue=3;
  unsigned int value=255;
  unsigned int state=1;
  unsigned int old=1;
  unsigned int buttonPoll=0;
  int color=0;
  
void setup() {
  // put your setup code here, to run once:

  pinMode(dim_Button, INPUT_PULLUP);
  pinMode(red_button, INPUT_PULLUP);
  pinMode(green_button, INPUT_PULLUP);
  pinMode(blue_button, INPUT_PULLUP);
  pinMode(yellow_button, INPUT_PULLUP);
  pinMode(white_button, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);     // To begin the serial communication protocol
  }

void loop() {
  if (digitalRead(red_button)==LOW){
  color=1;
  Serial.print("RED");}
  if (digitalRead(green_button)==LOW){
  color=2;
  Serial.print("GREEN");}
  if (digitalRead(blue_button)==LOW){
  color=3;
  Serial.print("BLUE");}
  if (digitalRead(yellow_button)==LOW){
  color=4;
  Serial.print("YELLOW");}
  if (digitalRead(white_button)==LOW){
  color=5;
  Serial.print("WHITE");}

   if(color==1){
    digitalWrite(red, value);
    analogWrite(green, 0);
    analogWrite(blue, 0);}
   if(color==2){
    analogWrite(red, 0);
    analogWrite(green, value);
    analogWrite(blue, 0);}
   if(color==3){
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, value);}
   if(color==4){
    analogWrite(red, value);
    analogWrite(green, value);
    analogWrite(blue, 0);}
   if(color==5){
    analogWrite(red, value);
    analogWrite(green, value);
    analogWrite(blue, value);}
  
  buttonPoll=digitalRead(dim_Button);
  if(buttonPoll==1){
    delay(50);
    buttonPoll=digitalRead(dim_Button);
    if(buttonPoll==0){
      state=old+1;}}

  if(state==1){
      value=255;
      old=state;
      Serial.print("high");}
  if(state==2){
      value=155;
      old=state;
      Serial.print("med");}
   if(state==3){
      value=55;
      old=state;
      Serial.print("low");}
   if(state>3){
      value=0;
      old=0;
      Serial.print("off");}

 
}
