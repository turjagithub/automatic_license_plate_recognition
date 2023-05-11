#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <SPI.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
#include <MFRC522.h>
#include <Servo.h> 
Servo myServo;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.


const int buttonPin1 = 2; // pushbutton connected to pin 2.
 int buttonState1 = 0;
 const int buttonPin2 = 3; // pushbutton connected to pin 2.
 int buttonState2 = 0;

void setup()
{
  lcd.begin(20, 4);

  pinMode(buttonPin1, INPUT);

  pinMode(buttonPin2, INPUT);
 
  Serial.begin(9600);
  delay(100);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("PUC CAR PARKING");
  lcd.setCursor(2, 1);
  lcd.print("SECURITY SYSTEM");
  lcd.setCursor(2, 2);
  lcd.print("System is ready");
  delay(5000);
  myServo.attach(5); //servo pin
  myServo.write(180); //servo start position
}
void loop(){
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2); 
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("PUC CAR PARKING");
  lcd.setCursor(2, 1);
  lcd.print("SECURITY SYSTEM");
  lcd.setCursor(2, 2);
  lcd.print("PLEASE VERIFYING");
  lcd.setCursor(4, 3);
  lcd.print("YOUR CARD");
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
// Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
// Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
//Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  if (buttonState1 == HIGH) 
  {
    if ((content.substring(1) == "40 94 B9 7A")  ) //1change here the UID of the card/cards that you want to give access
    {
      Serial.println("Authorized access");
      Serial.println();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Welcome Mr. Raihan");
      lcd.setCursor(0, 1);
      lcd.print("Car No.- CH-141516");
      lcd.setCursor(0, 2);
      lcd.print("Model- Bentley");
      lcd.setCursor(0, 3);
      lcd.print("Parking No.-01");
      delay(5000);
      myServo.write(120);
      delay(5000);
      myServo.write(180);
      delay(300);
     }
   }
   if (buttonState1 == HIGH) 
   {
      if ((content.substring(1) == "B2 AC 0F 30")  ) //1change here the UID of the card/cards that you want to give access
      {
    	  Serial.println("Authorized access");
        Serial.println();
    	  lcd.clear();
  	  lcd.setCursor(0, 0);
   	  lcd.print("Welcome Mr. Akramul");
        lcd.setCursor(0, 1);
        lcd.print("Car No.- BH-202122");
        lcd.setCursor(0, 2);
        lcd.print("Model- Audi ");
        lcd.setCursor(0, 3);
        lcd.print("Parking No.-02");
        delay(5000);
        myServo.write(120);
    	  delay(5000); 
   	  myServo.write(180);
  	  delay(300);
  	 }
   }
   if (buttonState1 == HIGH) 
   {
    if ((content.substring(1) == "60 3E 29 7A")  ) //1change here the UID of the card/cards that you want to give access
    {
      Serial.println("Authorized access");
      Serial.println();
      lcd.clear();
      lcd.setCursor(0, 0);
   	lcd.print("Welcome Mr. T.Mallik");
  	lcd.setCursor(0, 1);
 	lcd.print("Car NO.- GHA-125655");
 	lcd.setCursor(0, 2);
  	lcd.print("Model- Ferrari ");
  	lcd.setCursor(0, 3);
  	lcd.print("Parking No.-03");
      delay(5000);
  	myServo.write(120);
      delay(5000); 
      myServo.write(180);
      delay(300);
    } 
  }
  if (buttonState1 == HIGH) 
  {
     if ((content.substring(1) == "00 93 A3 7A")  ) //1change here the UID of the card/cards that you want to give access
     {
       Serial.println("Authorized access");
       Serial.println();
       lcd.clear();
   	 lcd.setCursor(0, 0);
   	 lcd.print("Welcome Mr. S.Munna");
  	 lcd.setCursor(0, 1);
   	 lcd.print("Car No.THA-514546 ");
  	 lcd.setCursor(0, 2);
  	 lcd.print("Model- Axio X ");
  	 lcd.setCursor(0, 3);
 	 lcd.print("Parking No.-04");
    	 delay(5000);
  	 myServo.write(120);
    	 delay(5000); 
    	 myServo.write(180);
    	 delay(300);
  	}
  }
  if (buttonState1 == HIGH) 
  {
     if ((content.substring(1) == "F0 54 77 7D")  ) //1change here the UID of the card/cards that you want to give access
     {
    	 Serial.println("Authorized access");
   	 Serial.println();
    	 lcd.clear();
 	 lcd.setCursor(0, 0);
  	 lcd.print("Welcome Mr.Sharit");
  	 lcd.setCursor(0, 1);
 	 lcd.print("Car No.- DHA-618584");
 	 lcd.setCursor(0, 2);
 	 lcd.print("Model- Premio X ");
 	 lcd.setCursor(0, 3);
 	 lcd.print("Parking No.-05");
   	 delay(5000);
	 myServo.write(120);
       delay(5000); 
   	 myServo.write(180);
       delay(300);
	}
   }
  
  if ((content.substring(1) == "F0 54 77 7D")  ) /////////
  {
    Serial.println("Authorized doesnot access");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Authorized doesnot");
    lcd.setCursor(6, 1);
    lcd.print(" Access ");
    lcd.setCursor(0, 2);
    lcd.print("Verify The Person ");
  }
  if (buttonState2 == HIGH) 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Authorized Person");
    lcd.setCursor(6, 1);
    lcd.print(" Doesnot Access ");
    lcd.setCursor(0, 2);
    lcd.print("Verify The Person ");
   }
 }

