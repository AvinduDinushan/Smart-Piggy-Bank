#include <LiquidCrystal.h>
#include <EEPROM.h>

int analog_in_0 = A0;
int analog_in_1 = A1;
int analog_in_2 = A2;
int analog_in_3 = A3;
int analog_in_4 = A4;

int coinIn;
int twoIn;
int tenIn;
int fiveIn;
int oneIn;

float total = 0;
float temptotal = 0;

const int buttonPin1 =  1; // master reset
const int buttonPin2 =  6; //1
const int buttonPin3 =  7; //2
const int buttonPin4 =  8; //5
const int buttonPin5 =  9; //10
const int buttonPin6 =  10; //reset the current value
const int buttonPin7 =  13; //game mode

int buttonState1;
int buttonState2;
int buttonState3;
int buttonState4;
int buttonState5;
int buttonState6;
int buttonState7;

int twos = 0;
int tens = 0;
int fives = 0;
int ones = 0;

int tempcoin;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
  total = EEPROM.read(0);
  Serial.println(total);
  twos = EEPROM.read(1);
  Serial.println(twos);
  tens = EEPROM.read(2);
  Serial.println(tens);
  ones = EEPROM.read(4);
  Serial.println(ones);
  fives = EEPROM.read(3);
  Serial.println(fives);
  lcd.clear();
   lcd.print("Total IN:");
   lcd.setCursor(0,1);
   lcd.print("Rs.");
   lcd.setCursor(4,1);
   lcd.print(total);
   lcd.noDisplay();
   Serial.println(total);
   lcd.display();
   delay(100);
  
 }
int iiiiiii = 1;
void loop() {
  buttonState6 = digitalRead(buttonPin6);
  while(buttonState6){
    Serial.println("Cleared");
      iiiiiii++;
      total = 0;
      twos = 0;
      tens = 0;
      fives = 0;
      ones = 0;
      lcd.clear();
      lcd.print("Total IN:");
      lcd.setCursor(0,1);
      lcd.print("Rs.");
      lcd.setCursor(4,1);
      lcd.print(total);
      lcd.noDisplay();
      lcd.display();
      EEPROM.put(0,total);
      EEPROM.put(1,twos);
      EEPROM.put(2,tens);
      EEPROM.put(3,fives);
      EEPROM.put(4,ones);
      delay(1000);
      break;
  }
  
  buttonState7 = digitalRead(buttonPin7);
  //Serial.println(buttonState7);
  
  
  if(buttonState7 != 1){
    
    temptotal = total;
    // put your main code here, to run repeatedly:
    coinIn = analogRead(analog_in_0);
    //delay(20);
    if (coinIn > 900)
    { 
      Serial.println("In");
      while(1){
        //delay(4);
        twoIn = analogRead(analog_in_1);
        if(twoIn > 850){
          total += 2;
          twos++;
          EEPROM.write(1,twos);
          Serial.println("2");
          delay(500);
          break;
        }
        //delay(70);
        tenIn = analogRead(analog_in_2);  
        if(tenIn > 830){
          total += 10;
          tens++;
          EEPROM.write(2,tens);
          Serial.println("10");
          delay(500);
          break;
        }
        //delay(20);
        fiveIn = analogRead(analog_in_3);
        if(fiveIn > 900){
          total += 5;
          fives++;
          EEPROM.write(3,fives);
          Serial.println("5");
          delay(500);
          break;
        }
        //delay(30);
        oneIn = analogRead(analog_in_4);
        if(oneIn > 900){
          total += 1;
          ones++;
          EEPROM.write(4,ones);
          Serial.println("1");
          delay(500);
          break;
        }
      }
    }
    if(temptotal != total){
       lcd.clear();
       lcd.print("Total IN:");
       lcd.setCursor(0,1);
       lcd.print("Rs.");
       lcd.setCursor(4,1);
       lcd.print(total);
       lcd.noDisplay();
       Serial.println(total);
       lcd.display();
       delay(100);
       EEPROM.write(0, total);
    }
  }else{
    //buttonState7 = LOW;
    //buttonState7 = digitalRead(buttonPin7);
    //delay(1000);
    //Serial.println(buttonState7);
    //if(buttonState7 == HIGH){
      //Play sound
      int var = 0;
      // buttonState1 = digitalRead(buttonPin1);
      // 1st button pushed
      lcd.clear();
      lcd.print("Game Mode");
      delay(1000);
      //lcd.noDisplay();
      //lcd.display();
      
      Serial.println("Game Mode");
      //delay(1000);

      
      lcd.clear();
      lcd.print("Select the coin");
      lcd.setCursor(0,1);
      lcd.print("to guess!");
      delay(1000);
      //lcd.display();
      //lcd.scrollDisplayLeft();
      //lcd.noDisplay();
      Serial.println("Which kind of Coin you preffer?");

      
      while(true){
        buttonState2 = digitalRead(buttonPin2);
        buttonState3 = digitalRead(buttonPin3);
        buttonState4 = digitalRead(buttonPin4);
        buttonState5 = digitalRead(buttonPin5);
  
        if(buttonState2){
          
          //lcd.display();
          lcd.clear();
          lcd.setCursor(0,0);
          //lcd.display();
          lcd.print("How many Rs 1");
          lcd.setCursor(0,1);
          lcd.print("Coins are there?");
          Serial.println("How many Rs 1 Coins are there?");
          Serial.println(ones);
          //lcd.scrollDisplayLeft();
          //lcd.noDisplay();
          delay(500);
          buttonState2 = LOW;
          tempcoin = ones;
          break;
        }
        if(buttonState3){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("How many Rs 2");
          lcd.setCursor(0,1);
          lcd.print("Coins are there?");
          Serial.println("How many Rs 2 Coins are there?");
          Serial.println(twos);
          //lcd.scrollDisplayLeft();
          //lcd.noDisplay();
          delay(500);
          buttonState3 = LOW;
          tempcoin = twos;
          break;
        }
        if(buttonState4){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("How many Rs 5");
          lcd.setCursor(0,1);
          lcd.print("Coins are there?");
          Serial.println("How many Rs 5 Coins are there?");
          Serial.println(fives);
          //lcd.scrollDisplayLeft();
          //lcd.noDisplay();
          delay(500);
          buttonState4 = LOW;
          tempcoin = fives;
          break;
        }
        if(buttonState5){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("How many Rs 10");
          lcd.setCursor(0,1);
          lcd.print("Coins are there?");
          Serial.println("How many Rs 10 Coins are there?");
          Serial.println(tens);
          //lcd.scrollDisplayLeft();
          //lcd.noDisplay();
          delay(500);
          buttonState5 = LOW;
          tempcoin = tens;
          break;
        }
      }   
      buttonState7 = LOW; 
      while(buttonState7 != HIGH){
        buttonState2 = digitalRead(buttonPin2);
        buttonState3 = digitalRead(buttonPin3);
        buttonState4 = digitalRead(buttonPin4);
        buttonState5 = digitalRead(buttonPin5);
        buttonState6 = digitalRead(buttonPin6);
        
        if(buttonState2 == HIGH){
          
          var += 1;
          Serial.println(var);
          lcd.clear();
          lcd.print("Your Answer:");
          lcd.setCursor(0,1);
          lcd.print(var);
          lcd.noDisplay();
          lcd.display();
          buttonState2 = LOW;
          delay(1000);
        }
        if(buttonState3 == HIGH){
          //Serial.println("2");
          var += 2;
          Serial.println(var);
          lcd.clear();
          lcd.print("Your Answer:");
          lcd.setCursor(0,1);
          lcd.print(var);
          lcd.noDisplay();
          lcd.display();
          buttonState3 = LOW;
          delay(1000);
        }
        if(buttonState4 == HIGH){
          //Serial.println("5");
          var += 5;
          Serial.println(var);
          lcd.clear();
          lcd.print("Your Answer:");
          lcd.setCursor(0,1);
          lcd.print(var);
          lcd.noDisplay();
          lcd.display();
          buttonState4 = LOW;
          delay(1000);
        }
        if(buttonState5 == HIGH){
          //Serial.println("10");
          var += 10;
          Serial.println(var);
          lcd.clear();
          lcd.print("Your Answer:");
          lcd.setCursor(0,1);
          lcd.print(var);
          lcd.noDisplay();
          lcd.display();
          buttonState5 = LOW;
          delay(1000);
        }
        if(buttonState6 == HIGH){
          //Serial.println("Reset");
          var = 0;
          Serial.println(var);
          lcd.clear();
          lcd.print("Your Answer:");
          lcd.setCursor(0,1);
          lcd.print(var);
          lcd.noDisplay();
          lcd.display();
          buttonState6 = LOW;
          delay(1000);
        }
        buttonState7 = digitalRead(buttonPin7);
      }
      if(var == tempcoin){
         Serial.println("Answer is correct Congrulation");
         lcd.clear();
         lcd.print("Answer is correct");
         lcd.setCursor(0,1);
         lcd.print("Congratz!! :D");
         lcd.noDisplay();
         lcd.display();
         delay(1000);
         lcd.clear();
         lcd.print("Total IN:");
         lcd.setCursor(0,1);
         lcd.print("Rs.");
         lcd.setCursor(4,1);
         lcd.print(total);
         lcd.noDisplay();
         lcd.display();                                                                                                                        
      }else{
        Serial.println("Wrong answer Try again later");
         lcd.clear();
         lcd.print("Wrong answer Try");
         lcd.setCursor(0,1);
         lcd.print("again later ;(");
         lcd.noDisplay();
         lcd.display();
         delay(1000);
         lcd.clear();
         lcd.print("Total IN:");
         lcd.setCursor(0,1);
         lcd.print("Rs.");
         lcd.setCursor(4,1);
         lcd.print(total);
         lcd.noDisplay();
         lcd.display();
      }
      delay(1500);
      buttonState7 = LOW;
    }
  //}
}
