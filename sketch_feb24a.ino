/*
 * Code d'exemple pour une photorésistance.
 */

#include <Stepper.h>
int step_number = 0;

double stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  // Pin inversion to make the library work


// Fonction setup(), appelée au démarrage de la carte Arduino
void setup() {
   myStepper.setSpeed(10); 
  // Initialise la communication avec le PC
  Serial.begin(9600);
}

// Fonction loop(), appelée continuellement en boucle tant que la carte Arduino est alimentée
void loop() {
  
  // Mesure la tension sur la broche A0
  int valeur = analogRead(A0);
  // Envoi la mesure au PC pour affichage et attends 250ms
  Serial.println(valeur);
   if(valeur < 500){
    if(step_number > 0 ){
     // 1 rotation counterclockwise:  
   Serial.println("counterclockwise");    
   myStepper.step(stepsPerRevolution); 
   step_number --; 
       Serial.println(step_number);  

    }
    }else{
if(step_number <= 2){
         

  // 1 rotation clockwise: 
  Serial.println("clockwise");  
  myStepper.step(-stepsPerRevolution);
  step_number ++;
    Serial.println(step_number);  

}
  }
  

  delay(10);
}
