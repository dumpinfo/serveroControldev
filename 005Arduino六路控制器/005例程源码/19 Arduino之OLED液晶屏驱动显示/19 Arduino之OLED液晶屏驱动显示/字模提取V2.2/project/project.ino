/**********************************************************
*程序课题：OLED液晶显示 
*程序功能：显示汉字和英文及符号
*编写：HEMLIN
*时间：2017年6月24日
**********************************************************/
#include <Wire.h>      //I2C头文件
//OLED液晶头文件
#include <Adafruit_GFX.h>   
#include <Adafruit_SSD1306.h>  
#define OLED_RESET 4  
Adafruit_SSD1306 display(OLED_RESET);  
void display_println(); //显示函数
/**********************************************************
                        中文字符
**********************************************************/

/*--  文字:  你  --*/
static const unsigned char PROGMEM str_1[] =  { 
0x08,0x80,0x08,0x80,0x08,0x80,0x11,0xFE,0x11,0x02,0x32,0x04,0x34,0x20,0x50,0x20,
0x91,0x28,0x11,0x24,0x12,0x24,0x12,0x22,0x14,0x22,0x10,0x20,0x10,0xA0,0x10,0x40
}; 
/*--  文字:  好  --*/
static const unsigned char PROGMEM str_2[] =  { 
0x10,0x00,0x10,0xFC,0x10,0x04,0x10,0x08,0xFC,0x10,0x24,0x20,0x24,0x20,0x25,0xFE,
0x24,0x20,0x48,0x20,0x28,0x20,0x10,0x20,0x28,0x20,0x44,0x20,0x84,0xA0,0x00,0x40
}; 

/*--  文字:  大  --*/
static const unsigned char PROGMEM str_3[] =  {
0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFE,0x01,0x00,0x01,0x00,
0x02,0x80,0x02,0x80,0x04,0x40,0x04,0x40,0x08,0x20,0x10,0x10,0x20,0x08,0xC0,0x06
}; 
/*--  文字:  家  --*/
static const unsigned char PROGMEM str_4[] =  {
0x02,0x00,0x01,0x00,0x7F,0xFE,0x40,0x02,0x80,0x04,0x7F,0xFC,0x02,0x00,0x0D,0x08,
0x71,0x90,0x02,0xA0,0x0C,0xC0,0x71,0xA0,0x06,0x98,0x18,0x86,0xE2,0x80,0x01,0x00
}; 
/*--  文字:  好  --*/
static const unsigned char PROGMEM str_5[] =  {
0x10,0x00,0x10,0xFC,0x10,0x04,0x10,0x08,0xFC,0x10,0x24,0x20,0x24,0x20,0x25,0xFE,
0x24,0x20,0x48,0x20,0x28,0x20,0x10,0x20,0x28,0x20,0x44,0x20,0x84,0xA0,0x00,0x40
}; 
/**********************************************************
                       液晶初始化
**********************************************************/
void OLED_init(void){
    //液晶128*64 I2C初始化地址0X3C  
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
    display.clearDisplay(); //清屏
}
/*********************************************************
                      初始化setup()函数
*********************************************************/
void setup() {                  
    OLED_init();       //液晶初始化
    display_println(); //显示固定字符
}  
/**********************************************************
                      主循环loop()函数
**********************************************************/  
void loop() {  
    
}  
/**********************************************************
                       显示函数
**********************************************************/
void display_println(){ 
    //中文字符显示 ：杭州众灵科技  
    //在坐标X:18 Y:0的位置显示中文字符杭 
    //第一个16为软件取模的高度
    //第二个16为软件取模的宽度
    display.drawBitmap(18, 0, str_1, 16, 16, 1); 
    display.drawBitmap(34, 0, str_2, 16, 16, 1); 

    //中文字符显示 ：液晶显示程序测试  
    display.drawBitmap(0, 24, str_3, 16, 16, 1); 
    display.drawBitmap(16, 24, str_4, 16, 16, 1); 
    display.drawBitmap(32, 24, str_5, 16, 16, 1); 
    //英文字符显示 Length: 
    display.setTextSize(2);             //设置字体大小  
    display.setTextColor(WHITE);        //设置字体颜色白色  
    display.setCursor(25,20);            //设置字体的起始位置  
   // display.println("???!!!!");//输出字符并换行  
    display.display(); //显示所有缓存的  
  }
