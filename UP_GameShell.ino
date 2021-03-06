//structure for gameplay--see gameplayex.mov for demo
#include <Arduboy2.h>
Arduboy2 arduboy;
# define HEIGHT 64
# define WIDTH 128

//general program variables
int gamestate = 0;

//Title screen things
const unsigned char title[] PROGMEM = {
  0x40, 0x80, 0x20, 0x0a, 0xc0, 0x84, 0x00, 0x0b, 
  0x18, 0x19, 0x07, 0x06, 0x7d, 0x62, 0x3f, 0x3b, 
  0x3f, 0x0c, 0x10, 0x7a, 0x7c, 0x49, 0xec, 0xe2, 
  0xe0, 0x68, 0x61, 0xf5, 0xfb, 0xfa, 0x9a, 0x02, 
  0x66, 0x74, 0x4c, 0x40, 0x40, 0x40, 0x40, 0xc0, 
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0c, 0x07, 0x01, 0x71, 
  0x3f, 0x0f, 0x01, 0x01, 0x00, 0xc0, 0x00, 0x00, 
  0x08, 0x8c, 0x8c, 0xcc, 0xcc, 0xf0, 0xda, 0x7a, 
  0x1a, 0x8a, 0x00, 0xf8, 0x70, 0x20, 0x3c, 0xe0, 
  0xe8, 0xc0, 0x08, 0xb0, 0x38, 0x00, 0xc0, 0xc0, 
  0x15, 0x41, 0x07, 0xc1, 0x00, 0x21, 0x81, 0x8f, 
  0x8f, 0x07, 0x05, 0x03, 0x21, 0x83, 0x47, 0x0f, 
  0x8f, 0x0e, 0x00, 0x02, 0x06, 0x9e, 0x9e, 0x0e, 
  0xc2, 0x40, 0x60, 0x20, 0x6f, 0x5f, 0xdd, 0x8f, 
  0xf7, 0x17, 0x16, 0x16, 0x12, 0x1a, 0x19, 0x18, 
  0x0b, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 
  0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xe0, 0x40, 0x40, 0x00, 
  0x60, 0x00, 0xe0, 0x00, 0x03, 0x00, 0x80, 0xb3, 
  0x31, 0x31, 0xb9, 0x7c, 0xff, 0xe3, 0x31, 0x7e, 
  0x3f, 0x01, 0x10, 0x01, 0x0f, 0x0f, 0xa0, 0x20, 
  0x00, 0x19, 0x40, 0x01, 0x40, 0xf0, 0x13, 0x48, 
  0x00, 0x20, 0x04, 0x83, 0x4d, 0x1f, 0xdb, 0x3a, 
  0x01, 0x01, 0x03, 0x02, 0xfe, 0x0f, 0x08, 0xf2, 
  0x03, 0xa2, 0xc2, 0x02, 0xfe, 0x13, 0x4b, 0xeb, 
  0x22, 0x02, 0x46, 0x0c, 0x38, 0xfe, 0x02, 0x02, 
  0x02, 0x02, 0xfe, 0x0c, 0x04, 0x02, 0x82, 0xc2, 
  0x62, 0x62, 0x62, 0x62, 0xc6, 0x84, 0xde, 0x02, 
  0xd2, 0xe2, 0x02, 0x7e, 0x40, 0x40, 0x7e, 0x82, 
  0x02, 0x0a, 0x02, 0xfe, 0xe0, 0x37, 0x06, 0x03, 
  0x02, 0xc3, 0x02, 0x06, 0x1c, 0x70, 0xc0, 0xfe, 
  0x02, 0x06, 0x02, 0x02, 0xf2, 0xf2, 0xf2, 0xf2, 
  0xf2, 0x62, 0x06, 0x06, 0x02, 0xe2, 0xe2, 0xe2, 
  0x03, 0x03, 0x03, 0x33, 0x23, 0xe2, 0xc2, 0x05, 
  0x00, 0x00, 0x03, 0x62, 0x62, 0x66, 0x63, 0x64, 
  0x6e, 0xff, 0x01, 0x03, 0x01, 0x00, 0xe2, 0x63, 
  0xe2, 0xc2, 0xc2, 0x86, 0x06, 0x04, 0x0d, 0x30, 
  0x10, 0x61, 0x32, 0x3a, 0xfd, 0x3e, 0x02, 0x00, 
  0x20, 0x81, 0xf2, 0x80, 0x01, 0xe0, 0x59, 0x67, 
  0xca, 0x82, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x0f, 
  0x00, 0x00, 0x80, 0xc0, 0xff, 0x00, 0x00, 0x28, 
  0x60, 0xfe, 0x0c, 0x18, 0x30, 0xe2, 0x02, 0x07, 
  0x00, 0x00, 0xff, 0xc0, 0x80, 0x00, 0x07, 0x1e, 
  0x10, 0x30, 0x10, 0x18, 0x08, 0x08, 0x9f, 0x00, 
  0x48, 0x0b, 0x00, 0xf8, 0x0a, 0x0b, 0xf9, 0x01, 
  0x04, 0x40, 0x00, 0x1f, 0x03, 0x00, 0x00, 0xc0, 
  0x46, 0x47, 0xc6, 0xc0, 0x80, 0x00, 0x07, 0x1f, 
  0x00, 0x20, 0x60, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 
  0xf0, 0xe0, 0x80, 0x04, 0x0e, 0x1f, 0x3f, 0xff, 
  0x18, 0x08, 0x08, 0x00, 0x00, 0xff, 0xff, 0x08, 
  0x00, 0x40, 0x80, 0x1c, 0x1c, 0x1c, 0x0c, 0x5c, 
  0x1c, 0xff, 0x00, 0x40, 0xe2, 0xc0, 0x1f, 0x30, 
  0x30, 0xb0, 0x10, 0x1f, 0x07, 0x00, 0x80, 0xc8, 
  0x02, 0x58, 0xfe, 0xff, 0xe1, 0x58, 0xf8, 0x2c, 
  0x00, 0x1e, 0x42, 0xa2, 0x98, 0xf0, 0x8c, 0xb4, 
  0xf3, 0xb9, 0x8f, 0xff, 0x76, 0xd6, 0x06, 0x02, 
  0x03, 0x01, 0x01, 0x07, 0x05, 0x05, 0x06, 0x02, 
  0x06, 0x05, 0x06, 0x00, 0x00, 0x03, 0x02, 0x02, 
  0x02, 0x02, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 
  0x02, 0x02, 0x02, 0x02, 0x03, 0x01, 0x03, 0x02, 
  0x82, 0x02, 0x02, 0x03, 0x00, 0x00, 0x03, 0x02, 
  0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x83, 0x01, 
  0x00, 0x80, 0x81, 0x81, 0x02, 0x1e, 0x12, 0x18, 
  0x0c, 0x30, 0x30, 0xa2, 0xae, 0xbb, 0x83, 0x83, 
  0x83, 0x83, 0x83, 0x82, 0x82, 0x82, 0x02, 0x03, 
  0x02, 0x82, 0x82, 0x80, 0x82, 0x83, 0x03, 0x03, 
  0x72, 0x5e, 0x7c, 0x12, 0x58, 0xbe, 0x73, 0x4a, 
  0x22, 0x2a, 0x12, 0x02, 0x03, 0x02, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0xff, 0x83, 
  0xbc, 0x8f, 0xe7, 0x80, 0x64, 0x38, 0xc6, 0x40, 
  0x00, 0x7c, 0x80, 0x7f, 0xbf, 0x4f, 0x23, 0x78, 
  0x81, 0x3f, 0x7f, 0x7f, 0x0e, 0x92, 0x69, 0x07, 
  0x78, 0x4c, 0x4c, 0x44, 0x4c, 0x48, 0x48, 0x48, 
  0x48, 0x58, 0xd8, 0x88, 0xc8, 0x48, 0x48, 0x58, 
  0x20, 0xff, 0x01, 0x00, 0x08, 0x9c, 0x9c, 0x88, 
  0xc1, 0x63, 0x1c, 0xe0, 0x18, 0x04, 0x02, 0x91, 
  0xb8, 0x91, 0x02, 0x04, 0x18, 0x60, 0x80, 0xff, 
  0x01, 0x00, 0x08, 0x9c, 0x9c, 0x88, 0x00, 0x21, 
  0x63, 0xde, 0x98, 0x30, 0xe1, 0x86, 0x08, 0x10, 
  0x20, 0x1c, 0x03, 0xe0, 0x58, 0x04, 0x02, 0xfc, 
  0x00, 0x00, 0x00, 0x7c, 0x80, 0x00, 0x03, 0x8e, 
  0x59, 0x50, 0x94, 0xa6, 0x46, 0x0c, 0x13, 0xf0, 
  0x20, 0x50, 0x50, 0x48, 0x48, 0x4c, 0x42, 0x4a, 
  0x44, 0x44, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 
  0x48, 0x48, 0x48, 0x44, 0x44, 0x48, 0x30, 0x20, 
  0xf8, 0x88, 0xa8, 0x29, 0x6b, 0xce, 0xa0, 0x3e, 
  0x10, 0x08, 0x0c, 0x67, 0x12, 0x42, 0x66, 0x3e, 
  0x9c, 0xd1, 0x49, 0x29, 0x09, 0xf8, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 
  0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 
  0x80, 0x83, 0x84, 0x04, 0x84, 0x83, 0x80, 0x00, 
  0x00, 0x00, 0x03, 0x04, 0x84, 0xc4, 0x45, 0xc3, 
  0x80, 0x00, 0x01, 0x03, 0x04, 0x04, 0x05, 0x83, 
  0x84, 0x84, 0x04, 0x03, 0x80, 0x81, 0x02, 0x04, 
  0x04, 0x04, 0x05, 0x82, 0x80, 0x01, 0x03, 0x04, 
  0x84, 0x84, 0x07, 0x00, 0x80, 0x07, 0x05, 0x85, 
  0x04, 0x84, 0x84, 0x84, 0x04, 0x85, 0x83, 0x82, 
  0x04, 0x84, 0x04, 0x04, 0x84, 0x04, 0x82, 0x03, 
  0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 
  0xa0, 0x38, 0x0c, 0xf4, 0xe4, 0x84, 0x04, 0x34, 
  0x64, 0xec, 0xc9, 0x3b, 0xe2, 0x6e, 0x3b, 0x20, 
  0x00, 0x0e, 0x13, 0x0a, 0x03, 0x03, 0x97, 0xee, 
  0x20, 0x70, 0x34, 0x96, 0xc7, 0x6d, 0x18, 0x00, 
  0x00, 0x00, 0x0f, 0x02, 0x02, 0x03, 0x00, 0x0f, 
  0x02, 0x06, 0x0b, 0x00, 0x0f, 0x0a, 0x0a, 0x00, 
  0x09, 0x0a, 0x0c, 0x00, 0x09, 0x0a, 0x0c, 0x00, 
  0x00, 0x00, 0x00, 0x07, 0x0f, 0x10, 0x1d, 0x10, 
  0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0x00, 0x00, 0x07, 0x08, 0x08, 0x07, 0x00, 
  0x00, 0x00, 0x07, 0x08, 0x08, 0x05, 0x00, 0x07, 
  0x08, 0x08, 0x07, 0x00, 0x0f, 0x03, 0x06, 0x0f, 
  0x00, 0x00, 0x0f, 0x00, 0x00, 0x08, 0x0f, 0x08, 
  0x00, 0x0f, 0x03, 0x06, 0x0f, 0x00, 0x0f, 0x08, 
  0x0f, 0x00, 0x0f, 0x0a, 0x0a, 0x00, 0x00, 0x00, 
  0x00, 0x78, 0x7c, 0xc4, 0x94, 0xba, 0x3b, 0x70, 
  0x6f, 0x6c, 0xec, 0x4c, 0x4d, 0x8f, 0x4f, 0x1c, 
  0x1a, 0x0f, 0x17, 0x2e, 0x28, 0x0c, 0x02, 0x00, 
  
};

void displayTitle() {
  arduboy.drawBitmap(0,0,title,WIDTH,HEIGHT,1);
  if (arduboy.justPressed(A_BUTTON)) {
    gamestate = 1;
  }
}
//GENERAL MENU THINGS
  //menu variables
  int menuCursorY = 23;
# define GAMEMODE 23
# define SETTINGS 38
# define CONTROLS 53
  int menustate = 0;


//menu image bitmap 
const unsigned char menu[] PROGMEM = {
  0x80, 0x80, 0x80, 0x90, 0x94, 0x18, 0x18, 0x58, 
  0xe0, 0xa0, 0x30, 0x00, 0x20, 0xa1, 0xe1, 0xc4, 
  0x86, 0x0f, 0x08, 0x18, 0x1c, 0x7c, 0xf4, 0xe6, 
  0xc3, 0x9b, 0x98, 0x8e, 0x0b, 0xf8, 0x80, 0x00, 
  0xe0, 0xa0, 0xb0, 0x90, 0x90, 0x90, 0x90, 0x90, 
  0x90, 0x90, 0x90, 0x90, 0x90, 0x30, 0x20, 0xa0, 
  0x40, 0xf8, 0x04, 0x04, 0xc8, 0x10, 0x10, 0xc8, 
  0x04, 0x04, 0xf8, 0xf8, 0x04, 0x04, 0xb4, 0xb4, 
  0xb4, 0xb4, 0xf8, 0xf8, 0x04, 0x04, 0x88, 0x10, 
  0x7c, 0x04, 0x04, 0xf8, 0xf8, 0x04, 0x04, 0xf8, 
  0x80, 0xf8, 0x04, 0x04, 0xf8, 0xa0, 0x90, 0xd0, 
  0x90, 0x90, 0x90, 0x90, 0x90, 0x10, 0x10, 0x90, 
  0x90, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xc0, 0x60, 0xb8, 0xee, 0x33, 0x18, 
  0x0f, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x18, 
  0x8c, 0xc7, 0x70, 0x1e, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x01, 0x01, 0x00, 0x03, 0x0d, 0x3c, 0xf8, 
  0x03, 0x39, 0x9f, 0xe1, 0x19, 0xe7, 0x7f, 0x2f, 
  0xcf, 0xe3, 0x03, 0x1e, 0x3e, 0xfe, 0xcc, 0x1f, 
  0x3f, 0x7f, 0xe7, 0xcf, 0x0e, 0xe0, 0xbf, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 
  0x00, 0x03, 0x04, 0x04, 0x03, 0x01, 0x01, 0x03, 
  0x04, 0x04, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 
  0x05, 0x05, 0x03, 0x03, 0x04, 0x04, 0x03, 0x01, 
  0x02, 0x04, 0x04, 0x03, 0x01, 0x02, 0x04, 0x04, 
  0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xfe, 0x03, 0xfd, 0x06, 0x03, 0x00, 0x00, 0x00, 
  0x78, 0xfe, 0x03, 0x79, 0xcc, 0x06, 0x03, 0x01, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
  0x01, 0x01, 0x01, 0x07, 0x0c, 0x0f, 0x0c, 0x07, 
  0x01, 0x03, 0x06, 0x1c, 0x30, 0x27, 0x33, 0x1c, 
  0x07, 0x1e, 0x38, 0x47, 0x9f, 0x40, 0x3f, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 
  0x2f, 0x98, 0x93, 0xce, 0xe8, 0xe4, 0xf4, 0xf4, 
  0xf4, 0xf5, 0xf7, 0x00, 0xe7, 0xe8, 0xd0, 0xa0, 
  0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xc0, 0x30, 0x8c, 0xe2, 0xf9, 0xfc, 0xfe, 
  0x7f, 0x0f, 0xcf, 0x67, 0x73, 0x19, 0x0a, 0x04, 
  0x04, 0x82, 0xc0, 0x66, 0xbd, 0x81, 0xf1, 0xc7, 
  0x8f, 0x3c, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0xe0, 0x1f, 0x7f, 0xff, 0xff, 0x02, 
  0x30, 0x9f, 0x11, 0xd0, 0x58, 0xc8, 0xec, 0xe6, 
  0xd3, 0xf9, 0xfc, 0x3e, 0x6f, 0x17, 0xcf, 0x23, 
  0x11, 0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x03, 0x04, 0x05, 0x05, 0x05, 
  0x08, 0x08, 0x08, 0x09, 0x0b, 0x01, 0x0b, 0x09, 
  0x08, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  
};

void drawMenu(){
  arduboy.drawBitmap(0,0,menu,WIDTH, HEIGHT,1);
  //arduboy.setCursor(45, 5);
  //arduboy.print("MENU");
  arduboy.setCursor(40, 20);
  arduboy.print("Game Mode");
  arduboy.setCursor(40, 35);
  arduboy.print("Settings");
  arduboy.setCursor(40, 50);
  arduboy.print("Controls");
  }
//moves and draws menu cursor
void menuCursor(){
    arduboy.drawCircle(5, menuCursorY, 3, WHITE);
    arduboy.drawCircle(5, menuCursorY, 1, BLACK);
    if (arduboy.justPressed(DOWN_BUTTON) and menuCursorY < 53) {
      menuCursorY += 15;
    }
    if (arduboy.justPressed(UP_BUTTON) and menuCursorY > 23) {
      menuCursorY -= 15;
    }
  }
//back button for menu
void menuBack(){
  if(arduboy.justPressed(B_BUTTON) and menustate>0){
    menustate=0;
    }
}

void menuSelection(){
  //for menu button selection
  if (arduboy.justPressed(A_BUTTON) and menuCursorY == GAMEMODE) {
      menustate = 1;
   }
   if (arduboy.justPressed(A_BUTTON) and menuCursorY == SETTINGS) {
      menustate = 2;
   }
   if(arduboy.justPressed(A_BUTTON) and menuCursorY == CONTROLS){
      menustate= 3;
   }
}

//controls bitmap 
const unsigned char controls[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x08, 
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xf0, 0xf0, 
  0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
  0x60, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xff, 0x00, 
  0x00, 0x00, 0x1f, 0x20, 0x20, 0x1f, 0x00, 0x00, 
  0x3f, 0x09, 0x09, 0x07, 0x00, 0x00, 0xff, 0xff, 
  0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
  0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 
  0x18, 0x04, 0x02, 0x01, 0x00, 0x80, 0x80, 0x00, 
  0x00, 0x80, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x81, 0x03, 0x07, 0x1c, 0x38, 0xe0, 
  0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xfe, 0x01, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 
  0x1e, 0x3c, 0x70, 0xe0, 0xc0, 0x80, 0x80, 0x80, 
  0xc0, 0xe0, 0x70, 0x38, 0x18, 0x0e, 0x07, 0x03, 
  0x01, 0x00, 0xf8, 0x88, 0x88, 0x88, 0x48, 0x70, 
  0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 
  0x40, 0x40, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x40, 
  0x80, 0x00, 0x00, 0x00, 0x1f, 0x04, 0x04, 0x1f, 
  0x00, 0x10, 0x1f, 0x10, 0x00, 0x1f, 0x01, 0x06, 
  0x06, 0x01, 0x1f, 0x00, 0x00, 0x00, 0xc0, 0xff, 
  0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1f, 0x20, 0x40, 0x40, 0x40, 0x47, 0x44, 0x44, 
  0x44, 0x44, 0x44, 0x40, 0x40, 0x40, 0xe0, 0x70, 
  0x38, 0x1c, 0x0e, 0x07, 0x03, 0x01, 0x01, 0x01, 
  0x03, 0x07, 0x0e, 0x1c, 0x38, 0x70, 0xc0, 0x80, 
  0x80, 0x80, 0x87, 0x80, 0x81, 0x81, 0x83, 0x82, 
  0x84, 0x80, 0x80, 0xc0, 0x3f, 0x1f, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x60, 0x30, 0x08, 0x84, 0x82, 0x01, 
  0x80, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 
  0x00, 0x80, 0x00, 0x00, 0x81, 0x83, 0x87, 0x0e, 
  0x9c, 0x38, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x01, 0x02, 0x04, 0x08, 0x18, 0x10, 0x30, 
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
  0x30, 0x30, 0x18, 0x1c, 0x0e, 0x07, 0x03, 0x01, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 
  0x7c, 0x44, 0x38, 0x00, 0x7c, 0x40, 0x7c, 0x00, 
  0x7c, 0x44, 0x00, 0x7c, 0x18, 0x64, 0x00, 0xff, 
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xff, 0x80, 0x00, 0x13, 0x16, 0x0c, 0x00, 
  0x1f, 0x02, 0x1f, 0x00, 0x0f, 0x10, 0x0f, 0x00, 
  0x0f, 0x10, 0x0f, 0x00, 0x00, 0x1f, 0x00, 0x00, 
  0x17, 0x00, 0x80, 0xff, 0x7f, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 
  0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
  0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x01, 0x01, 0x06, 0x04, 0x04, 0x08, 0x10, 
  0x20, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 
  0x40, 0x40, 0x40, 0x40, 0x60, 0x30, 0x30, 0x18, 
  0x0c, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  
};

  //nate
  int hits = 0;
  int luck = 0; //each level of luck uses different layer of black pixels frame to show damage, needs to do on botton of display list bc its the last overlay, then score
  int bullets = 100; //each press of A subtracts 1

  //gun sight
  int sightx = 0;
  int sighty = 0;

  //bullet coords + speed
  int bulletx = 0;
  int bullety = 0;
  int bulletspeed = 0;

  void setup() {
    arduboy.begin();
    srand(7 / 8);
    arduboy.setFrameRate(60);
    arduboy.clear();
  }
  /* #I'm kinda feeling two separate games bc the graphics might take up a lot of room, so maybe just gameplay + journal as an extra?
      A press>gamestate+=1, A=B press >> gamestate -=1 if gamestate !=0,or < the gameplay
      >>Main Screen: UNCHARTED: Magna Edition
        >>A to Begin
        >>play theme music
      >>Menu
        >>play theme music
        >>Controls
          >> Print button controls
            >>A to shoot, B to reload
            >>L/R for left/right movement
            >>Down to Duck behind wall
            >>Up to pause
        >>Sound Settings
          >>On
          >>Off
        >>Extras
          >>Nate's Journal
          >>play different song
      >> Gameplay
        >>play fighting song + sound effects
        >>If Mode ==Default:
          >>If nate takes 4 consecutive hits, display 'luck frame' (hits>=4,display
          >>Jungle Background
          >>Enemies randomly spawn
        >>If Mode==Journal
          >>Display journal
          >>LR to flip through pages
  */
  void loop() {
    if (!arduboy.nextFrame()) {
      return;
    }
    arduboy.clear();
    arduboy.pollButtons();
    switch (gamestate) {
      case 0:
        //add titlescreen graphics
        displayTitle();
      break;
      case 1: //MENU SCREEN----------------------------------------------------------------------
        switch (menustate) {
          case 0:
            drawMenu();
            //add some menu graphics, probably drake's ring
            menuCursor();
            //returns to title screen
            if (arduboy.justPressed(B_BUTTON) and menustate==0) {
              gamestate = 0;
            }
            menuSelection();
            break;
          case 1:
            //game mode
            arduboy.print("game mode: Classic Shootout/Nate's Journal");
            //later when u have the coordinates and fonts picked out, add another menu for selecting nate's journal or combat
            //replace the below code with menu selection later
            if (arduboy.justPressed(A_BUTTON)){
              gamestate = 2;
            }
            menuBack();
            break;
          case 2:
            //settings
            arduboy.print("settings");
            //write in sound settings once/if u add in any sound effects
            menuBack();
            break;
          case 3:
            //controls
            arduboy.drawBitmap(0,0,controls,WIDTH,HEIGHT,1);
            menuBack();
            break;
    }
      break;
      case 2://--GAME MODE----------------------------------------------------------------------
        //this is for game 
        arduboy.print("gameplay");
      break;
      case 3://-JOURNAL MODE-------------------------------------------------------------------
        //this is for journal if memory space
        arduboy.print("Nate's journal");
      break;
      case 4:
        //this is for losing
        arduboy.print("Play Again?");
        //A for yes, B to return to Menu
        if(arduboy.justPressed(A_BUTTON)){
          gamestate = 2;
        }
        if(arduboy.justPressed(B_BUTTON)){
          gamestate = 1;
        }
      
  }
  arduboy.display();
}
