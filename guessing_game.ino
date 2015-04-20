/*#####################
  Component's Slots
#######################*/

// Speaker Output
int speaker = 13;

// Win and loose LED's
int winLED = 10;
int looseLED = 11;

// Game LED's
int LED1 = 6;
int LED2 = 9;

// Buttons
int but1 = 8;
int but2 = 12;

/*#####################
  Initializing Varbiables
#######################*/

int level = 1;

int thisLED = 0;

int hasChosen = 1;
int chosen = 0;

/*#####################
  Constructor Function
#######################*/
void setup() {
  
  // Win and Loose LED Setup
  pinMode(winLED, OUTPUT);
  pinMode(looseLED, OUTPUT);
  
  // Game LED Setup
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  // Buttons Setup
  pinMode(but1, INPUT_PULLUP);
  pinMode(but2, INPUT_PULLUP);
   
}

/*#####################
     Device's Loop
#######################*/

void loop() {
  
  // Verify if the user needs to make a choice
  if (hasChosen == 1){
    
   // Begin Game
   for( int i = 0 ; i < 20 ; i++){
     
       // Pick a random number for an LED
       int rand = random(1,3);
 
       if (rand == 1){
         thisLED = LED1;       
       }if(rand == 2){       
         thisLED = LED2;       
       }
     
       // Turn the selected LED on
       digitalWrite(thisLED, HIGH);
     
       // Wait based on level's speed
       delay(200/level);
     
       //Turn the LED off for next the light
       digitalWrite(thisLED, LOW); 
     
      if(i == 19){ 
        // On the last iteration set chosen to break the loop
        hasChosen = 0;
      }    
    } // end of For loop
    
  }else{
    // Functionality for choosing a LED
    if(digitalRead(but1) == LOW){
      chosen = LED1;
      hasChosen = 1;
    }
    if(digitalRead(but2) == LOW){
      chosen = LED2;
      hasChosen = 1;
    }

    if (hasChosen == 1){
      // Verify if they chose correctly
      digitalWrite(chosen,HIGH);
      delay(100);
      digitalWrite(chosen,LOW);
      
      if (chosen == thisLED){
        digitalWrite(winLED,HIGH);
        tone(speaker, 2500);
        // Increment the level value for the next run 
        level++;
      }else{
        digitalWrite(looseLED,HIGH);
        tone(speaker, 600);
      }
      
      delay(1000);
      noTone(speaker);
      digitalWrite(winLED,LOW);
      digitalWrite(looseLED,LOW);
      
    }
  } 
  delay(300);
 
}
