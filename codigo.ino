int BUTTON_PIN = 7;
int BUZZER_PIN = 9;

int TEMP_SENSOR = A0;
int PH_SENSOR = A1;
int WATER_QUALITY_SENSOR = A2;

void setup() {

  pinMode(PH_SENSOR, INPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Leitura da temperatura (simulada)
  int tempValue = analogRead(TEMP_SENSOR);
  float temperature = (tempValue * (5.0 / 1023.0)) * 100;


  // Leitura do sensor de pH (simulado com potenciômetro)
  int val  = analogRead(PH_SENSOR); 
  float ph = map(val, 0, 1023, 0, 14);

  // Leitura do sensor de qualidade da água (simulado com potenciômetro)
  int waterQualityValue = analogRead(WATER_QUALITY_SENSOR);
  float waterQuality = map(waterQualityValue, 0, 1023, 0, 100);

  // Exibir dados no Serial Monitor
  Serial.print("Temperatura:");
  Serial.print(temperature);
  Serial.print(" °C, pH: ");
  Serial.print(ph);
  Serial.print(", Qualidade Água:");
  Serial.print(waterQuality);
  Serial.println(" %");

  // Verificar o botão
  if (digitalRead(BUTTON_PIN) == HIGH) {
    tone(BUZZER_PIN, 1000, 500);
  } else {
  }

  delay(2000);
}
