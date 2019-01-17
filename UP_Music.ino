
#include <Arduboy2.h>
#include <ArduboyTones.h>
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);


#define BUTTON_DELAY 200
#define NDUR 100

const uint16_t theme[] PROGMEM ={
  NOTE_E3, 300, NOTE_FS3, 300,NOTE_G3,1000, NOTE_B3,1000, NOTE_A3,2000,NOTE_A3,300, NOTE_G3,300,NOTE_B3,2000,NOTE_C4,1700,NOTE_C4,500,NOTE_B3,500,NOTE_A3,500,NOTE_G3,500,NOTE_B3,500,NOTE_A3,2000,
  TONES_END};

const uint16_t uncharted[] PROGMEM={
  NOTE_E3, 300,NOTE_G3,300,NOTE_B3,2000,NOTE_B3,400,NOTE_C4,400,NOTE_G3,400,NOTE_G3,400,NOTE_A3,400,NOTE_B3,2000,
  TONES_END
};

void setup() {
  arduboy.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
  
  sound.tones(uncharted);
  while(sound.playing()){
    if(arduboy.pressed(B_BUTTON)){
      sound.noTone();
      delay(BUTTON_DELAY);
      break;
    }
  }
}
