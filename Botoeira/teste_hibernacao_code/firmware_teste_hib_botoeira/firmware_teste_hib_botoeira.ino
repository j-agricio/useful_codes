#define SWITCH_PIN 17
#define LDR_PIN 19
#define GREEN_LED 13
#define RED_LED 12

#define HIGH_DELAY_DIVISIONS  10
#define HIGH_DELAY_PERIOD_SEC 1500
#define HIGH_DELAY_FRACTION   HIGH_DELAY_PERIOD_SEC/HIGH_DELAY_DIVISIONS

#define MIN_SLEEP_TIME_SEC    1000
#define MAX_SLEEP_TIME_SEC    6000000

long randNumber;
bool ldr_status;
int i;

long n_falhas = 0;
long n_acertos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);  
  pinMode(LDR_PIN, INPUT);  
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  randomSeed(analogRead(0));
}

void loop() {
  // print a random number from first to second
  randNumber = random(MIN_SLEEP_TIME_SEC, MAX_SLEEP_TIME_SEC);
  
  Serial.print("Sleep time (seconds) = ");
  Serial.println(randNumber);
  Serial.print("Numero de Falhas = ");
  Serial.print(n_falhas);
  Serial.print(" – Numero de Acertos = ");
  Serial.print(n_acertos);
  Serial.println("");  
  
  digitalWrite(SWITCH_PIN, HIGH);  
  
  for( i = 0; i<HIGH_DELAY_DIVISIONS; i++)
  {    
    ldr_status = digitalRead(LDR_PIN);

    if(!ldr_status)
    {
      digitalWrite(GREEN_LED, HIGH);
      n_acertos++;
      break;
    }     
    delay(HIGH_DELAY_FRACTION);
  }
  
  if(ldr_status)
  {
    n_acertos++;
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }
  
  delay((HIGH_DELAY_DIVISIONS - i)*HIGH_DELAY_FRACTION);
  
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(SWITCH_PIN, LOW);
  delay(randNumber);
  
}
