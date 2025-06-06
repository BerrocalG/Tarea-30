#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void config_timer(void){
  TCCR0A |= (1 << WGM01);
  TCCR0B |= (1 << CS02);
}
void FA(void){
   OCR0A = 50;  
   TCNT0 = 0;
   while (!(TIFR0 & (1 << OCF0A)));
   TIFR0 |= (1 << OCF0A);
}
void SOL(void){
   OCR0A = 45;  
   TCNT0 = 0;
   while (!(TIFR0 & (1 << OCF0A)));
   TIFR0 |= (1 << OCF0A);
}
  void MI(void){
   OCR0A = 47;
   TCNT0 = 0;
    while (!(TIFR0 & (1 << OCF0A)));
    TIFR0 |= (1 << OCF0A); }  
  void SI(void){
   OCR0A = 63;
  TCNT0 = 0;
     while (!(TIFR0 & (1 << OCF0A)));
     TIFR0 |= (1 << OCF0A); }  
  void DO(void){
   OCR0A = 60;
   TCNT0 = 0;
   while (!(TIFR0 & (1 << OCF0A)));
    TIFR0 |= (1 << OCF0A); } 
  void RE(void){
   OCR0A = 54;
   TCNT0 = 0;
  while (!(TIFR0 & (1 << OCF0A)));
   TIFR0 |= (1 << OCF0A); }  
    void LA(void){ 
    OCR0A = 71; 
    TCNT0 = 0;
   while (!(TIFR0 & (1 << OCF0A)));
    TIFR0 |= (1 << OCF0A); }  

int main(void){
  config_timer();
  DDRB |= (1 << PB0);

  while(1){
    // MI
    
    for(int i = 0; i < 250; i++){
      PORTB ^= 0x01;
      MI();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // SI
    for(int i = 0; i < 125; i++){
      PORTB ^= 0x01;
      SI();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // DO
    for(int i = 0; i < 125; i++){
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // RE
    for(int i = 0; i < 250; i++){
      PORTB ^= 0x01;
      RE();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  MI();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  RE();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

    // D0
    for(int i = 0; i < 125; i++){
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // SI
    for(int i = 0; i < 125; i++){
      PORTB ^= 0x01;
      SI();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // LA
    for(int i = 0; i < 250; i++){
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // LA
    for(int i = 0; i < 125; i++){
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // DO
    for(int i = 0; i < 125; i++){
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // MI
    for(int i = 0; i < 250; i++){
      PORTB ^= 0x01;
      MI();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // RE
    for(int i = 0; i < 125; i++){
      PORTB ^= 0x01;
      RE();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // DO
    for(int i = 0; i < 125; i++){
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // SI
    for(int i = 0; i < 250; i++){
      PORTB ^= 0x01;
      SI();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // DO
    for(int i = 0; i < 125; i++){
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // RE
    for(int i = 0; i < 250; i++){
      PORTB ^= 0x01;
      RE();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // MI
    for(int i = 0; i < 250; i++){
      PORTB ^= 0x01;
      MI();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // DO
    for(int i = 0; i < 250; i++){
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // LA
    for(int i = 0; i < 250; i++){
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(60);

    // LA
    for(int i = 0; i < 375; i++){
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(60);
//
    _delay_ms(500);

    //segunda aprte
    //Si

    
  for (int i = 0; i < 250; i++) {
    PORTB ^= 0x01;
    RE();
  } 
  PORTB &= ~0x01;
    _delay_ms(120);

  for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  FA();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 250; i++) {
    PORTB ^= 0x01;
    LA();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  SOL();
  }
  PORTB &= ~0x01;
  _delay_ms(60);
//bien de aca para abajo
  for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  FA();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 375; i++) {
  PORTB ^= 0x01;
  MI();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  DO();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  MI();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  RE();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

 for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  MI();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  RE();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  DO();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 250; i++) {
  PORTB ^= 0x01;
  SI();
  }
  PORTB &= ~0x01; 

  _delay_ms(60);

  for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  SI();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 125; i++) {
  PORTB ^= 0x01;
  DO();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 250; i++) {
  PORTB ^= 0x01;
  RE();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 250; i++) {
  PORTB ^= 0x01;
  MI();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 250; i++) {
  PORTB ^= 0x01;
  DO();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 250; i++) {
  PORTB ^= 0x01;
  LA();
  }
  PORTB &= ~0x01;
  _delay_ms(60);

  for (int i = 0; i < 250; i++) {
  PORTB ^= 0x01;
  LA();
  }
  PORTB &= ~0x01;
  _delay_ms(60);


_delay_ms(500);

//ultimaparte
for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  MI();
}
PORTB &= ~0x01;
_delay_ms(120);

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  DO();
}
PORTB &= ~0x01;
_delay_ms(120);

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  RE();
}
PORTB &= ~0x01;
_delay_ms(120);

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  SI();
}
PORTB &= ~0x01;
_delay_ms(120);

//

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  DO();
}
PORTB &= ~0x01;
_delay_ms(120);

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  LA();
}
PORTB &= ~0x01;
_delay_ms(120);

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  SOL();
}
PORTB &= ~0x01;
_delay_ms(120);

_delay_ms(1000);

//ulitma

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  MI();
}
PORTB &= ~0x01;
_delay_ms(120);

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  DO();
}
PORTB &= ~0x01;
_delay_ms(120);

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  RE();
}
PORTB &= ~0x01;
_delay_ms(60);

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  SI();
}
PORTB &= ~0x01;
_delay_ms(120);
//
for (int i = 0; i < 250; i++) {
  PORTB ^= 0x01;
  DO();
}
PORTB &= ~0x01;
_delay_ms(120);

for (int i = 0; i < 250; i++) {
  PORTB ^= 0x01;
  MI();
}
PORTB &= ~0x01;
_delay_ms(120);

for (int i = 0; i < 250; i++) {
  PORTB ^= 0x01;
  LA();
}
PORTB &= ~0x01;
_delay_ms(60);

for (int i = 0; i < 500; i++) {
  PORTB ^= 0x01;
  SOL();
}
PORTB &= ~0x01;
_delay_ms(60);
}
}
