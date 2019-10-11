#include "serial.h"
//SoftwareSerial mySerial(22, 23); 
#define RXD2 26//22
#define TXD2 25//23
void setup() {
  //Khi mach vừa nap sẽ gửi tin nhắn nhấn RESET sẽ nạp lại tin nhắn
  pinMode(19, OUTPUT); 
   pinMode(27, OUTPUT);
   digitalWrite(27, HIGH);
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  Serial.println("Initializing...");
 // Serial.println("Initializing..."); 
  delay(1000);
  Serial2.println("AT"); //Kiểm tra sim 800l , kết quả trả vầ là OK
  updateSerial();

  Serial2.println("AT+CMGF=1"); // Kiểm tra sim 800l , kết quả trả vầ là OK
  updateSerial();
   Serial2.println("AT+CMGS=\"0869270717\"");//Thay đổi số điện thoại cần gửi tin nhắn
  updateSerial();
  Serial2.print("hello esp322"); //Thay đổi văn bản cần gửi
  updateSerial();
  Serial2.write(26);
}
 
void loop() {
  delay(10);
}

