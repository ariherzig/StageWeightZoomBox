#include <Keyboard.h>
#include <OneButton.h>
 
OneButton button1(0, true);
OneButton button2(2, true);
#define LED_1 3
#define LED_2 4

int LED_1_Value = LOW;
int LED_2_Value = LOW;

void setup()
{
  // Set functions for buttons
  button1.attachClick(keypress1);
  button2.attachClick(keypress2);
  button1.attachLongPressStart(button1flipLED);
  button2.attachLongPressStart(button2flipLED);
  
  // Set button pins as inputs with pull-up resistors (when pressed, the buttons will drive the pins low)
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
 
  // start USB keyboard
  Keyboard.begin();
}

void loop() {
  button1.tick();
  button2.tick();
  delay(10);
}

void keypress1() {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('-'); 
      Keyboard.releaseAll();
      if (LED_1_Value == LOW) {
        LED_1_Value = HIGH;
      } else {
        LED_1_Value = LOW;
      }
      digitalWrite(LED_1, LED_1_Value);
}

void keypress2() {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('=');
      Keyboard.releaseAll();
      if (LED_2_Value == LOW) {
        LED_2_Value = HIGH;
      } else {
        LED_2_Value = LOW;
      }
      digitalWrite(LED_2, LED_2_Value);
}

void button1flipLED() {
  if (LED_1_Value == LOW) {
        LED_1_Value = HIGH;
      } else {
        LED_1_Value = LOW;
      }
  digitalWrite(LED_1, LED_1_Value); 
}

void button2flipLED() {
  if (LED_2_Value == LOW) {
        LED_2_Value = HIGH;
      } else {
        LED_2_Value = LOW;
      }
  digitalWrite(LED_2, LED_2_Value);
}
