const int ADDRESS = 0xDA02; // Change this for each device
 
void setup()
{
    Serial.begin(9600);
    pinMode(A0, INPUT);
} 

void sendBytes(uint16_t value)
{
    Serial.write(highByte(value));
    Serial.write(lowByte(value));
}
 
void loop() 
{ 
    sendBytes(ADDRESS);
    sendBytes(analogRead(A0));
    delay(50);
}
 
