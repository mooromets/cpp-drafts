#define one 13
#define two 12

void setup() {
  // put your setup code here, to run once:
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
}

void loop() {
  digitalWrite(one, HIGH);   
  digitalWrite(two, LOW);   
  delay(10000);                       

  digitalWrite(one, LOW);  
  digitalWrite(two, HIGH);   
  delay(10000);             
}
