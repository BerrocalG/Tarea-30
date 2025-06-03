#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// Configuración del temporizador en modo CTC
void config_timer(void){
  TCCR0A |= (1 << WGM01);
  TCCR0B |= (1 << CS02); // prescaler 256
}

// Funciones por nota (frecuencias con OCR0A)
void DO(void){
  OCR0A = 118;
  TCNT0 = 0;
  while (!(TIFR0 & (1 << OCF0A)));
  TIFR0 |= (1 << OCF0A);
}

void RE(void){
  OCR0A = 105;
  TCNT0 = 0;
  while (!(TIFR0 & (1 << OCF0A)));
  TIFR0 |= (1 << OCF0A);
}

void MI(void){
  OCR0A = 83;
  TCNT0 = 0;
  while (!(TIFR0 & (1 << OCF0A)));
  TIFR0 |= (1 << OCF0A);
}

void FA(void){
  OCR0A = 89;
  TCNT0 = 0;
  while (!(TIFR0 & (1 << OCF0A)));
  TIFR0 |= (1 << OCF0A);
}

void SOL(void){
  OCR0A = 79;
  TCNT0 = 0;
  while (!(TIFR0 & (1 << OCF0A)));
  TIFR0 |= (1 << OCF0A);
}

void LA(void){
  OCR0A = 70;
  TCNT0 = 0;
  while (!(TIFR0 & (1 << OCF0A)));
  TIFR0 |= (1 << OCF0A);
}

void SI(void){
  OCR0A = 62;
  TCNT0 = 0;
  while (!(TIFR0 & (1 << OCF0A)));
  TIFR0 |= (1 << OCF0A);
}

int main(void){
  config_timer();
  DDRB |= (1 << PB0);
  PORTB &= ~(1 << PB0);

  while (1){
    // MI (negra)
    for (int i = 0; i < 165; i++) {
      PORTB ^= 0x01;
      MI();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // SI (corchea)
    for (int i = 0; i < 100; i++) {
      PORTB ^= 0x01;
      SI();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // DO (corchea)
    for (int i = 0; i < 60; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // RE (negra)
    for (int i = 0; i < 105; i++) {
      PORTB ^= 0x01;
      RE();
    }
    PORTB &= ~0x01;
    _delay_ms(500);

    // DO (corchea)
    for (int i = 0; i < 119; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // LA (corchea)
    for (int i = 0; i < 140; i++) {
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // LA (negra)
    for (int i = 0; i < 70; i++) {
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(500);

    // LA (corchea)
    for (int i = 0; i < 70; i++) {
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // DO (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // MI (negra)
    for (int i = 0; i < 165; i++) {
      PORTB ^= 0x01;
      MI();
    }
    PORTB &= ~0x01;
    _delay_ms(500);

    // RE (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      RE();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // DO (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      DO();
    }
   // DO (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(500);

    // SI (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      SI();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // DO (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // RE (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      RE();
    }
    PORTB &= ~0x01;
    _delay_ms(500);

    // MI (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      MI();
    }
    PORTB &= ~0x01;
    _delay_ms(500);

    // DO (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(250);

    // LA (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(500);

    // LA (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(500);

    // Silencio 1000 ms
    _delay_ms(1000);
  }

  return 0;
}
