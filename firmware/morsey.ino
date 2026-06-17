// libraries
#include <U8x8lib.h>

//define the pins
#define BTN PA2
#define BUZ PD6

U8X8_SSD1306_128X64_NONAME_HW_I2C oled(U8X8_PIN_NONE);

//timings
const int DOT = 250;       //short tap = dot, longer = dash
const int LGAP = 700;      //gap this long = end of letter
const int WGAP = 1600;     // word gap
const long SLEEP = 30000;  // turns screen off

// morse code lookup table
const char* M[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
const char* K="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

//variables
String sym, text;
unsigned long t, last;
bool down, awake=true, skip;

//turn dots dashes into actual letters
char decode(String s){ for(int i=0;i<36;i++) if(s==M[i]) return K[i]; return '?'; }

//display onto screen and redraw
void draw(){ oled.clear(); oled.print(text); if(sym.length()){oled.print(' ');oled.print(sym);} }

//setup runs once
void setup(){
  pinMode(BTN,INPUT_PULLUP);
  pinMode(BUZ,OUTPUT);
  oled.begin();
  oled.setFont(u8x8_font_chroma48medium8_r);
  last=millis(); draw();
}

void loop(){
  bool d=!digitalRead(BTN);   //pressed = true
  unsigned long now=millis();

  // sleep mode, wait for a press to wake
  if(!awake){ if(d){ skip=true; oled.setPowerSave(0); awake=true; last=now; draw(); } return; }

  //press logic
  if(d && !down){ down=true; t=now; tone(BUZ,1000); }   //pressed down
  if(!d && down){                                       //let go
    down=false; noTone(BUZ);
    if(skip) skip=false;                          //that press just woke it
    else if(now-t>20) sym+=(now-t<DOT)?'.':'-';   //dot or dash
    last=now; draw();
  }

  //end of letter
  if(!d && sym.length() && now-last>LGAP){ text+=decode(sym); sym=""; draw(); }

  //word space
  if(!d && sym=="" && text!="" && now-last>WGAP && text[text.length()-1]!=' '){ text+=' '; draw(); }

  //screen off when idle
  if(!d && sym=="" && now-last>SLEEP){ oled.setPowerSave(1); awake=false; }
}
