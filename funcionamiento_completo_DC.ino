#define sensor  6  // defino los pines que voy a usar despues
#define Menfrente  4  // Menfrente y Matras son los valores que decidiran el sentido al que ira, estos valores dependiendo de la carga que le den, se ira a las UNITS en el L293D
#define Matras  7
#define Pmotor  5 // Pmotor es el pin PWM que decidira la carga enviada al ENABLE del L293D(que decidira la velocidad)

int Vmotor = 255; //  Esta variable es el valor del PWM de Pmotor
int Tseg = 1; // Esta variable decidira cuantos segundos pasen del sensor al motor de empuje, en esta variable hay que calibrarlo dependiendo de la velocidad de la cinta 


void setup(){
 Serial.begin(9600); // Se abren las salidas en el serial
 
pinMode(sensor, INPUT);             // Aqui se deciden que pines son de SALIDA y cuales de ENTRADA
pinMode(Menfrente, OUTPUT);
pinMode(Matras,OUTPUT);
pinMode(Pmotor, OUTPUT);

}
void loop(){
 
 int Vsensor = digitalRead(sensor);  //Lee la entrada del variable sensor y luego el valor del sensor es puesto como Vsensor
 Serial.println(Vsensor); // Imprime los datos del variable Vsensor(sensor)

if (Vsensor == 0){    // Si el sensor se pone en 0, entonces se activaran los siguientes estamentos
  
  delay(Tseg*1000); // Este delay decidira cuanto tiempo tiene que esperar del sensor al motor de empuje para ser activado
  
  digitalWrite(Menfrente, HIGH); // Estos dos digitalWrite se usaran para decidir el sentido al que ira el motor
  digitalWrite(Matras, LOW);
  analogWrite(Pmotor,Vmotor); // Establezco el Pmotor como salida PWM, y luego le doy un valor al PWM
  delay(500); //Dejo el motor encendido por 500 milisegundos(.5 segundos)
  
  digitalWrite(Menfrente,LOW); //Establezco lo mismo que lo anterior solo que los datos del digitalWrite fueron cambiados para cambiar el sentido del motor
  digitalWrite(Matras,HIGH);
  analogWrite(Pmotor,Vmotor);
  delay(500);
 
  digitalWrite(Menfrente,LOW); //Establezco lo mismo que lo anterior solo que los datos del digitalWrite fueron cambiados para detener el motor 
  digitalWrite(Matras,LOW);

}
}

