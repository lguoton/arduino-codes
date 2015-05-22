#include <Stepper.h>
# define Pasos 360 //Aqui se establece el valor de una vuelta, significa que una vuelta del stepper representa 360 pasos
# define sensor 14 // aqui se establece el pin del sensor

Stepper motor(Pasos, 8, 9, 10, 11);

int Tseg = 1; // Esta variable decidira cuantos segundos pasen del sensor al motor de empuje, en esta variable hay que calibrarlo dependiendo de la velocidad de la cinta 
int Rmin = 200 //En este variable puedes decir cuantos pasos puede dar al momento de empujar y de regresar
int Vmotor = 100; //  Esta variable es el valor en RPM(revoluciones por minuto)

void setup(){
 Serial.begin(9600); // Se abren las salidas en el serial
 
 pinMode(sensor,INPUT); // Establezco el sensor como entrada
 
 motor.setSpeed(Vmotor); //la velocidad del motor en RPM

}
void loop(){
 
 int Vsensor = digitalRead(sensor);  //Lee la entrada del variable sensor y luego el valor del sensor es puesto como Vsensor
 Serial.println(Vsensor); // Imprime los datos del variable Vsensor(sensor)

if (Vsensor == 0){    // Si el sensor se pone en 0, entonces se activaran los siguientes estamentos
  
  delay(Tseg*1000); // Este delay decidira cuanto tiempo tiene que esperar del sensor al motor de empuje para ser activado
  
  motor.step(Rmin); //Aqui se esablece cuantos pasos va a dar en el momento de empujar
  
  motor.step(-Rmin); //Aqui se esablece cuantos pasos va a dar en el momento de regresar
 
  motor.step(0); //Se detiene un momento para luego continuar con el " If "

}
}

