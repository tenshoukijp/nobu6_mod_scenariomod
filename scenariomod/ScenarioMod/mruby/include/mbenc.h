/* 
** mbenc.h : MS-Windows�p�}�N�� 
** 
** mruby �� cp932 encoding�p 
** by ��.jp 
*/
  
#ifndef mbenc_h 
#define mbenc_h 
  
  
#define MRUBY_USE_ENC_CP932   1 
  
  
/* -- japanese cp932 -- */
#if MRUBY_USE_ENC_CP932 
#define is_lead_byte(c) ((0x81 <= ((unsigned char) (c)) && ((unsigned char) (c)) <= 0x9f) || (0xe0 <= ((unsigned char) (c)) && ((unsigned char) (c)) <=0xfc)) 
#else 
#define is_lead_byte(c) (0) 
#endif 
  
  
#endif 
