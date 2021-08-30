// Raymond Roussel (Second) Reading Machine
// Roni Bandini, Buenos Aires, Aug 2021 
// @RoniBandini

// Connections
// HDD Continuous servo pin 1 GND, Servo pin 2 Vcc, Servo pin 3, D12
// Push Button: GND and D11

#include <Servo.h>

Servo myservoBase; 
int pinBase=12;
int pinButton=11;
int randNumber=0;

int stopValue=78;

void setup() {
  Serial.begin(9600);
  Serial.print("Raymond Roussel (Second) Reading Machine started");  

  randomSeed(analogRead(0));

  pinMode(pinButton, INPUT_PULLUP);

  myservoBase.attach(pinBase);

  myservoBase.write(stopValue);
  
  delay(1000);

}

void loop() {

  int buttonState = digitalRead(pinButton);

  if (buttonState==0){
    
    Serial.print("Button pressed");

    randNumber = random(1,6);
    
    Serial.print("Forward");
    myservoBase.write(120);

    if (randNumber==1){      
      Serial.print("Died in 1933");
      delay(1933);      
    }

    if (randNumber==2){      
      Serial.print("Published Impressions of Africa in 1910");
      delay(1910);      
    }

    if (randNumber==3){      
      Serial.print("Published Locus Solus in 1914");
      delay(1914);      
    }

    if (randNumber==4){      
      Serial.print("1274 line poem in New Impressions of Africa");
      delay(1274);      
    }

    if (randNumber==5){      
      Serial.print("Born 01 1877");
      delay(11877);      
    }
        
    Serial.print("Turn the other side");
    myservoBase.write(40);
    delay(660);

    Serial.print("Stop");
    myservoBase.write(stopValue);
    
  }

  delay(250);
  
  
}
