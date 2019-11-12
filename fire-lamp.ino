#include <Adafruit_NeoPixel.h>
#define NEO_PIN 9
#define NUM_LEDS 8

Adafruit_NeoPixel neo = Adafruit_NeoPixel(NUM_LEDS, NEO_PIN, NEO_GRB + NEO_KHZ800);

int ledBright = 255;

// 불꽃 감지 센서와 피에조를 이용하여 화재경보기를 만들어 봅시다.
 // 13번 핀을 LED로 지정합니다.
int ledPin = 13;
// 디지털 2번핀을 불꽃감지센서로 지정합니다.
int inputPin = 8;
// 불꽃 감지 센서의 상태를 저장합니다.(처음 상태를 LOW로 설정)
int pirState = LOW;
// 센서 값을 읽기 위해 변수를 선언합니다. 
int val = 0;           
// PWM 핀에 스피커 혹은 피에조 센서를 연결합니다.(digital 9, 10, or 11)
int pinSpeaker = 10;
int gasPin = 9;

void setup() {
	// LED 를 출력으로 설정합니다.
	pinMode(ledPin, OUTPUT);      
	// 센서를 입력으로 설정합니다.
	pinMode(inputPin, INPUT);     
	// 스피커를 출력으로 설정합니다.
	pinMode(pinSpeaker, OUTPUT); 
	// 시리얼 통신(9600)를 준비합니다.
	Serial.begin(9600);

    neo.setBrightness(ledBright);
    neo.begin();
    neo.show();
}

void loop() {
	// 센서값을 읽어들입니다.
	val = digitalRead(inputPin);  
	// 만약 값이 HIGH 일때,
    int gas = analogRead(gasPin);
	if (!val) {            
		buzzer();

	} else {

	}

    int i;    
    uint32_t colorValue;
    colorValue = neo.Color(255, 0, 0, 0); //color : red
    for(i = 0; i < NUM_LEDS; i++) {
        neo.setPixelColor(i, colorValue);
        neo.show();
        delay(50);
    }
}

// 경보음을 만들어 냅니다.
void buzzer() {
    tone(pinSpeaker, 500, 1000);
    delay(2000);
}

void red() {
    int i;    
    uint32_t colorValue;
    colorValue = neo.Color(255, 0, 0); //color : red
    for(i = 0; i < NUM_LEDS; i++) {
        neo.setPixelColor(i, colorValue);
        neo.show();
        delay(50);
    }
}

void green() {
    int i;    
    uint32_t colorValue;
    colorValue = neo.Color(0, 255, 0);
    for(i = 0; i < NUM_LEDS; i++) {
        neo.setPixelColor(i, colorValue);
        neo.show();
        delay(50);
    }
}

void blue() {
    int i;    
    uint32_t colorValue;
    colorValue = neo.Color(0, 0, 255);
    for(i = 0; i < NUM_LEDS; i++) {
        neo.setPixelColor(i, colorValue);
        neo.show();
        delay(50);
    }
}

void white() {
    int i;    
    uint32_t colorValue;
    colorValue = neo.Color(255, 255, 255);
    for(i = 0; i < NUM_LEDS; i++) {
        neo.setPixelColor(i, colorValue);
        neo.show();
        delay(50);
    }
}