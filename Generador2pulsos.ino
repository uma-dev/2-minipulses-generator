#include "Ucglib.h"
#define PIN_1 PA8
#define PIN_2 PA1
#define PIN_INT PB13
#define POTENTIOMETER PB1
#define encoderOutA PB7 // CLK pin of Rotary Enocoder
#define encoderOutB PB8 // DT pin of Rotary Enocoder
#define encoderOutC PB6 // DT pin of Button Rotary Enocoder
#define __NOP __asm__ __volatile__ ("nop\n\t")

 
int counter = 0; 
int presentState;
int previousState; 
volatile int increment = 1;

volatile int delay_phase = 0;
Ucglib_ST7735_18x128x160_HWSPI ucg( PA2 , PA4, PA3);// (A0, CS, RESET)

void Pulse( void ){
  //delayMicroseconds(delay_phase);  
  __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP; __NOP;
  delayMicroseconds(counter);  
  Timer2.pause();
  Timer2.setPrescaleFactor(36);     //granularidad de 0.5 us
  Timer2.setOverflow(2000);         //frecuencia = overflow*granuralidad= 1kHz
  Timer2.setCompare(TIMER_CH2, 2);
  Timer2.refresh();
  Timer2.resume();
}


void setup(void){
 /*Encoder config*/
  pinMode (encoderOutA,INPUT_PULLDOWN);
  pinMode (encoderOutB,INPUT_PULLDOWN);
  pinMode (encoderOutC,INPUT_PULLUP);
  previousState = digitalRead(encoderOutA);
  attachInterrupt(digitalPinToInterrupt(encoderOutA), encodeRead, CHANGE);    
  attachInterrupt(digitalPinToInterrupt(encoderOutC), encodeButton, RISING);    
  
  /*Timer config*/
  Serial.begin(115200);
  pinMode(POTENTIOMETER, INPUT_ANALOG);
  pinMode(PIN_1, PWM);
  pinMode(PIN_2, PWM);
  pinMode(PIN_INT, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(PIN_INT), Pulse, RISING );    
  Timer1.pause();
  Timer1.setPrescaleFactor(36);     //granularidad de 0.5 us
  Timer1.setOverflow(2000);         //frecuencia = overflow*granuralidad= 1kHz
  Timer1.setCompare(TIMER_CH1, 2);
  Timer1.refresh();
  Timer1.resume();

  /*Screen config*/
  ucg.begin(UCG_FONT_MODE_SOLID);  
  ucg.clearScreen(); 
  ucg.setRotate90(); 
  //ucg.setPrintDir(0);  // 0, 1, 2 or 3 to change orientation of text. If not specify, orientation is 0
  //ucg.setFont(ucg_font_profont11_mr);
  ucg.setFont(ucg_font_profont15_mr);
  ucg.setColor(0, 200, 255, 200);  // Set color (0,R,G,B)
  ucg.setColor(1, 0, 0, 0);  // Set color of text background (1,R,G,B)
  ucg.setPrintPos(100,123);  // Set position (x,y)
  ucg.print("[us]");   

  ucg.setFont(ucg_font_inb19_mr);
} 

void encodeRead(){  
  presentState = digitalRead(encoderOutA); 
  if (presentState != previousState){     
     if (digitalRead(encoderOutB) != presentState){ if(counter>=increment) counter -= increment; } 
     else                                         { counter += increment;  }
   } 
   previousState = presentState; 
}

void encodeButton(){
  if(increment == 1) increment = 10;
  else if(increment == 10) increment = 1;
}

void loop(void){
  char string[10];  // Create a character array of 10 characters
  dtostrf(counter+4, 4, 0, string);  // (<variable>,<amount of digits we are going to use>,<amount of decimal digits>,<string name>)
  ucg.setColor(0, 255, 255, 255);  
  ucg.setColor(1, 0, 0, 0);  
  ucg.setPrintPos(30,125);  
  ucg.print(string);  
  if(increment == 10){
    ucg.setColor(0, 255, 0, 0);  
    ucg.drawDisc(20,115,6,UCG_DRAW_ALL);
  }
  else{
    ucg.setColor(0, 0, 0, 0);  
    ucg.drawDisc(20,115,6,UCG_DRAW_ALL); 
  }
  delay(100);
}  
