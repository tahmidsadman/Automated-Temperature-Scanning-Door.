int R_LED = 13;
int Y_LED = 12;
int G_LED = 11;

int ledPin = 8;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status


void setup() {
  // put your setup code here, to run once:
  pinMode(R_LED, OUTPUT);
  pinMode(Y_LED, OUTPUT);
  pinMode(G_LED, OUTPUT); //defines all the LED pins to output
  Serial.begin(9600);//Display in monitor

  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

   int vol = analogRead(A0) * (5.0 / 1023.0*100);   //analog read the temperature sensor voltage
Serial.print(" The temperature is:");
Serial.println(vol);
if (vol<=31)                                    //if the temperature is low
{
  digitalWrite(G_LED, HIGH);                   // GREEN led on
  digitalWrite(Y_LED, LOW);
  digitalWrite(R_LED, LOW);
}
else if (vol>=32 && vol<=40)                // if the temperature is middle            
 {
   digitalWrite(R_LED, LOW);
  digitalWrite(Y_LED, HIGH);              //YELLOW led on
  digitalWrite(G_LED, LOW);
}
else if (vol>=41)                            //If the temperature is HIGH
{
   digitalWrite(G_LED, LOW);
  digitalWrite(Y_LED, LOW);
  digitalWrite(R_LED, HIGH);                // REDled on
}
delay(100);


val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      Serial.println("1");
      
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
       Serial.println("0");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }

}
