/*
Arduino Turn LED On/Off using Serial Commands
Created April 22, 2015
Hammad Tariq, Incubator (Pakistan)

It's a simple sketch which waits for a character on serial
and in case of a desirable character, it turns an LED on/off.

Possible string values:
a (to turn the LED on)
b (tor turn the LED off)
*/

char junk;
String inputString="";
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 pinMode(led5, OUTPUT);
}

void loop()
{
  if(Serial.available()){
  while(Serial.available()){
  //{ junk = Serial.read() ; }      // clear the serial buffer
    delay(10); //Delay added to make thing stable
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
      voice += c; //Shorthand for voice = voice + c
}
  if (voice.length() > 0) {
  Serial.println(voice); 
    //Serial.println(inputString);
    //while (Serial.available() > 0)  
    if(voice == "*tv on"){         //in case of 'a' turn the LED on
      digitalWrite(led1, HIGH); 
      Serial.println("first light"); 
    }if(voice == "b"){   //in case of 'b' turn the LED off
      digitalWrite(led2, HIGH);
      Serial.println("second light");
    }if(voice == "c"){         //in case of 'a' turn the LED on
      digitalWrite(led3, HIGH);
      Serial.println("third light");  
    }if(voice == "d"){   //incase of 'b' turn the LED off
      digitalWrite(led4, HIGH);
      Serial.println("forth light");
    }if(voice == "e"){         //in case of 'a' turn the LED on
      digitalWrite(led5, HIGH);
      Serial.println("fifth light");}  
    }if(voice == "6"){   //incase of 'b' turn the LED off
      digitalWrite(led1, LOW);
      Serial.println("first light off");
    }if(voice == "7"){         //in case of 'a' turn the LED on
      digitalWrite(led2, LOW);
      Serial.println("second light off");  
    }if(voice == "8"){   //incase of 'b' turn the LED off
      digitalWrite(led3, LOW);
      Serial.println("third light off");
    }if(voice == "9"){         //in case of 'a' turn the LED on
      digitalWrite(led4, LOW); 
      Serial.println("forth light off"); 
    }if(voice == "1"){   //incase of 'b' turn the LED off
      digitalWrite(led5, LOW);
      Serial.println("fifth light off");}
voice = "";
  }
}
