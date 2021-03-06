//bitmap for title screen
#include <Arduboy.h>

Arduboy arduboy;

#define WIDTH 128
#define HEIGHT 64

const unsigned char image[] PROGMEM = {
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

void setup()
{
	arduboy.beginNoLogo();
	
	arduboy.clear();
	arduboy.drawBitmap(0, 0, image, WIDTH, HEIGHT, 1);
	arduboy.display();
}

void loop()
{

}
