#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>

uint8_t led1;
uint8_t templed1;
uint8_t led2;
uint8_t templed2;
uint8_t led4;
uint8_t templed4;
uint8_t led5;
uint8_t templed5;
uint8_t tempBpm;
uint8_t tempSpo2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  PCintPort::attachInterrupt(5, readDataLED1, FALLING);
  attachInterrupt(0, readDataLED4, FALLING);
  attachInterrupt(1, readDataLED5, FALLING);
}
  
void loop() {
  Serial.print("SPO2: ");
  uint8_t spo2 = led1*10 + led2;
  if(spo2 <= 80){
    Serial.print(tempSpo2);
    Serial.print(" %");
  }else if(spo2 == 88){
    Serial.print("undefine");
  }else{
    tempSpo2 = spo2;
    Serial.print(spo2);
    Serial.print(" %");
  }
  
  Serial.print("\tHeart rate: ");
  uint8_t bpm = led4*10 + led5;
  if(bpm < 50){
    Serial.print(tempBpm);
    Serial.println(" bpm");
  }else if(bpm == 88){
    Serial.println("undefine");
  }else{
    tempBpm = bpm;
    Serial.print(bpm);
    Serial.println(" bpm");
  }
  delay(1000);
}

void readDataLED1(){
    
    uint8_t a1 = 0;
    uint8_t b1 = 0;
    uint8_t c1 = 0;
    uint8_t d1 = 0;
    uint8_t e1 = 0;
    uint8_t f1 = 0;
    uint8_t g1 = 0;
    
      a1 = digitalRead(7);  
      b1 = digitalRead(8); 
      c1 = digitalRead(9);     
      d1 = digitalRead(10);
      e1 = digitalRead(11);
      f1 = digitalRead(12);
      g1 = digitalRead(13);
        
        led1 =  segToNumber(a1, b1, c1, d1, e1, f1, g1);
        if(led1 != 0){
          templed1 = led1;     
        }else{
          led1 = templed1;
        }      
      delayMicroseconds(300);
      PCintPort::detachInterrupt(5);    
      PCintPort::attachInterrupt(6, readDataLED2, FALLING); 
}

void readDataLED2(){
    
    uint8_t a1 = 0;
    uint8_t b1 = 0;
    uint8_t c1 = 0;
    uint8_t d1 = 0;
    uint8_t e1 = 0;
    uint8_t f1 = 0;
    uint8_t g1 = 0;
    
      a1 = digitalRead(7);  
      b1 = digitalRead(8); 
      c1 = digitalRead(9);     
      d1 = digitalRead(10);
      e1 = digitalRead(11);
      f1 = digitalRead(12);
      g1 = digitalRead(13);
        
        led2 =  segToNumber(a1, b1, c1, d1, e1, f1, g1);
        if(led2 != 0){
          templed2 = led2;     
        }else{
          led2 = templed2;
        }      
      delayMicroseconds(300);     
      PCintPort::detachInterrupt(6);   
      PCintPort::attachInterrupt(5, readDataLED1, FALLING);
}

void readDataLED4(){
    
    uint8_t a1 = 0;
    uint8_t b1 = 0;
    uint8_t c1 = 0;
    uint8_t d1 = 0;
    uint8_t e1 = 0;
    uint8_t f1 = 0;
    uint8_t g1 = 0;
    
      a1 = digitalRead(7);  
      b1 = digitalRead(8); 
      c1 = digitalRead(9);     
      d1 = digitalRead(10);
      e1 = digitalRead(11);
      f1 = digitalRead(12);
      g1 = digitalRead(13);
        
        led4 =  segToNumber(a1, b1, c1, d1, e1, f1, g1);
        if(led4 != 0){
          templed4 = led4;     
        }else{
          led4 = templed4;
        }      
      delayMicroseconds(300);     
}

void readDataLED5(){

    uint8_t a2 = 0;
    uint8_t b2 = 0;
    uint8_t c2 = 0;
    uint8_t d2 = 0;
    uint8_t e2 = 0;
    uint8_t f2 = 0;
    uint8_t g2 = 0;
    
      a2 = digitalRead(7);  
      b2 = digitalRead(8); 
      c2 = digitalRead(9);     
      d2 = digitalRead(10);
      e2 = digitalRead(11);
      f2 = digitalRead(12);
      g2 = digitalRead(13);
        
        led5 =  segToNumber(a2, b2, c2, d2, e2, f2, g2);
        if(led5 != 0){         
          templed5 = led5;     
        }else{
          led5 = templed5;
        }      

      delayMicroseconds(300);     
}

uint8_t segToNumber(uint8_t A,uint8_t B, uint8_t C, uint8_t D, uint8_t E, uint8_t F,uint8_t G){
  if((A == 1) && (B == 1) && (C == 1) && (D == 1) && (E == 1) && (F == 1) && (G == 0)){
    return 0;
  }else if((A == 0) && (B == 1) && (C == 1) && (D == 0) && (E == 0) && (F == 0) && (G == 0)){
    return 1;
  }else if((A == 1) && (B == 1) && (C == 0) && (D == 1) && (E == 1) && (F == 0) && (G == 1)){
    return 2;
  }else if((A == 1) && (B == 1) && (C == 1) && (D == 1) && (E == 0) && (F == 0) && (G == 1)){
    return 3;
  }else if((A == 0) && (B == 1) && (C == 1) && (D == 0) && (E == 0) && (F == 1) && (G == 1)){
    return 4;
  }else if((A == 1) && (B == 0) && (C == 1) && (D == 1) && (E == 0) && (F == 1) && (G == 1)){
    return 5;
  }else if((A == 1) && (B == 0) && (C == 1) && (D == 1) && (E == 1) && (F == 1) && (G == 1)){
    return 6;
  }else if((A == 1) && (B == 1) && (C == 1) && (D == 0) && (E == 0) && (F == 0) && (G == 0)){
    return 7;
  }else if((A == 1) && (B == 1) && (C == 1) && (D == 1) && (E == 1) && (F == 1) && (G == 1)){
    return 8;
  }else if((A == 1) && (B == 1) && (C == 1) && (D == 1) && (E == 0) && (F == 1) && (G == 1)){
    return 9;
  }else{
    return 0;
  }
}

