#include <Servo.h>
Servo myservo;
#include <LiquidCrystal.h>
#include <Keypad.h>
#define led 13
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(10, 11, A0, A1, A2, A3);
const byte ROWS = 4; // four rows
const byte COLS = 4; // three columns
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {2, 3, 4, 5}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; // connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
char stored[] = "159258357";
int i = 0, count = 0, number = 9;
char pass[9];
int pos = 0;
void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Enter the Pass");
    lcd.setCursor(0, 1);
    myservo.attach(13);
}
void loop()
{
    char key = keypad.getKey();
    if (key > '0' && key != 'D')
    {
        lcd.print('*');
        pass[i] = key;
        i++;
    }
    else if (key == 'D')
    {
        if (i == number)
        {
            for (int k = 0; k < number; k++)
            {
                if (pass[k] == stored[k])
                    count++;
            }
            if (count == number)
            {
                lcd.clear();
                digitalWrite(led, HIGH);
                lcd.setCursor(0, 0);
                lcd.print("Correct Pass");
                delay(1000);
                for (pos = 0; pos <= 180; pos += 1)
                {
                    myservo.write(pos);
                    delay(15);
                }
                i = 0;
                count = 0;
                lcd.setCursor(0, 0);
                lcd.print("Enter the Pass");
                lcd.setCursor(0, 1);
            }
        }
    }
}