int signalPin = 14; //D5
float ldr;
float intensitas;

void setup() {
  Serial.begin(115200);
  pinMode(signalPin,OUTPUT);
  digitalWrite(signalPin,LOW);
}

void loop() {
  ldr = analogRead(A0);
  intensitas = ldr/1024.0*100;
  delay(1000);

  Serial.print("Sensor LDR : ");
  Serial.println(ldr);
  Serial.print("Intensitas Cahaya : ");
  Serial.print(intensitas);
  Serial.println(" %");

  if(intensitas<=1.55){
    digitalWrite(signalPin, HIGH);
    Serial.println("Ruangan Keadaan Gelap");
    Serial.println("==========================");
  }else if(intensitas>1.85){
    digitalWrite(signalPin, LOW);
    Serial.println("Ruangan Keadaan Terang");
    Serial.println("==========================");
  }
  
}
