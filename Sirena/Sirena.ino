
#define WAIT_LED  100

unsigned long int previousMillis = 0;
unsigned long int previousMillisLed = 0;
unsigned int interval = 0;
unsigned int tone1 = 392;
unsigned int tone2 = 660;
unsigned int duration[8];
unsigned int toneVal = 0;
int index = 0;

bool state = true;

void setup() {
  // put your setup code here, to run once:
  
  duration[0] = 1000;
  duration[1] = 167;
  duration[2] = 167;
  duration[3] = 167;
  duration[4] = 1000;
  duration[5] = 167;
  duration[6] = 167;
  duration[7] = 167;

  interval = duration[0];
  toneVal = tone1;

  pinMode(13,OUTPUT);

  
}

void loop()
{
  
  if (millis() - previousMillis > interval)    // Attemping to make this keep the buzzer running for 500ms
      {
        previousMillis = millis();
        if (toneVal == tone1) {
             toneVal = tone2;
        }
        else {
            toneVal = tone1;
        }
        if(index < 7)
          index++;
        else
          index = 0;  
        interval = duration[index];
        
      }
      tone(8, toneVal);

      digitalWrite(13,state);
      if(millis() - previousMillisLed > WAIT_LED)
      {
          previousMillisLed = millis();
          state = !state;
      }

}


