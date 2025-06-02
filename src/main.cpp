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
  OCR0A = 94;
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
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      MI();
    }
    PORTB &= ~0x01;
    _delay_ms(50);

    // SI (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      SI();
    }
    PORTB &= ~0x01;
    _delay_ms(25);

    // DO (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(25);

    // RE (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      RE();
    }
    PORTB &= ~0x01;
    _delay_ms(50);

    // DO (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(25);

    // LA (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(25);

    // LA (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(50);

    // LA (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(25);

    // DO (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(25);

    // MI (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      MI();
    }
    PORTB &= ~0x01;
    _delay_ms(50);

    // RE (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      RE();
    }
    PORTB &= ~0x01;
    _delay_ms(25);

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
    _delay_ms(50);

    // SI (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      SI();
    }
    PORTB &= ~0x01;
    _delay_ms(25);

    // DO (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(25);

    // RE (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      RE();
    }
    PORTB &= ~0x01;
    _delay_ms(50);

    // MI (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      MI();
    }
    PORTB &= ~0x01;
    _delay_ms(50);

    // DO (corchea)
    for (int i = 0; i < 41; i++) {
      PORTB ^= 0x01;
      DO();
    }
    PORTB &= ~0x01;
    _delay_ms(25);

    // LA (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(50);

    // LA (negra)
    for (int i = 0; i < 83; i++) {
      PORTB ^= 0x01;
      LA();
    }
    PORTB &= ~0x01;
    _delay_ms(50);

    // Silencio 1000 ms
    _delay_ms(1000);
  }

  return 0;
}
