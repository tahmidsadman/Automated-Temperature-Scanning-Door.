int R_LED = 13;
int Y_LED = 12;
int G_LED = 11;

int ledPin = 8;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirVal;             // we start, assuming no motion detected
int val = A0;                    // variable for reading the pin status


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//Display in monitor
  pinMode(R_LED, OUTPUT);
  pinMode(Y_LED, OUTPUT);
  pinMode(G_LED, OUTPUT); //defines all the LED pins to output
  
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
}

void loop() {
  // put your main code here, to run repeatedly:
  pirVal = LOW;
   int vol = analogRead(val)*0.48685492;
   vol=round(vol);//analog read the temperature sensor voltage
//Serial.print(" The temperature is:");

if (vol<=31)                                    //if the temperature is low
{
  digitalWrite(G_LED, HIGH);                   // GREEN led on
  digitalWrite(Y_LED, LOW);
  digitalWrite(R_LED, LOW);
}
if (vol>=32 && vol<=40)                // if the temperature is middle            
 {
   digitalWrite(R_LED, LOW);
  digitalWrite(Y_LED, HIGH);              //YELLOW led on
  digitalWrite(G_LED, LOW);
}
if (vol>=41)                            //If the temperature is HIGH
{
   digitalWrite(G_LED, LOW);
  digitalWrite(Y_LED, LOW);
  digitalWrite(R_LED, HIGH);
}
delay(100);
  digitalWrite(G_LED, LOW);
  digitalWrite(Y_LED, LOW);
  digitalWrite(R_LED, LOW);

Serial.println(vol);

pirVal = digitalRead(inputPin);  // read input value
  if (pirVal == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected!");
    Serial.println("1");
    }
  else {
    digitalWrite(ledPin, LOW); // turn LED OFF
      Serial.println("Motion ended!");
       Serial.println("0");
    }
  }
