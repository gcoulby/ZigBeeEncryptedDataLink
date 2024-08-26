const int PIN_RED   = 9;
const int PIN_GREEN = 10;
const int PIN_BLUE  = 11;

int red = 0;
int green = 0;
int blue = 0;

void setup() {
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);

  Serial.begin(9600);
}

void setColor(int R, int G, int B) {
  analogWrite(PIN_RED,   R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE,  B);
}

void loop() {
  if(Serial.available() >= 4)
  {
    if(Serial.read() == 0xDA){
      int id = Serial.read();
      
      byte msb = Serial.read();
      byte lsb = Serial.read();

      int analogVal = (msb << 8) | lsb;
      int mapped = map(analogVal, 0, 1023, 0, 255);

      switch(id){
        case 0: 
          red = mapped;
          break;
        case 1: 
          green = mapped;
          break;
        case 2:
          blue = mapped;
          break;
        default:
          break;
      }
    }
  }

  setColor(red, green, blue);
}
