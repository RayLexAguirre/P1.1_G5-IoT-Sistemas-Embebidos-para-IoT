#include "serial_class.h"

int n = 64;
int counter = 0; //Contador para los arrays

void setup( void ) {

  Serial.begin ( 115200 ); // Configuración BaudRate, un sistema puede tener varios puertos seriales físicos.

}

void loop ( void ) {
    if(counter == 0){
          delay(5000);
          post_data(n, counter);
          counter++;
          delay(10000);
    }
    post_data(n, counter);
    counter++;
    delay(10000);
  /*if(Serial.available() > 0){

  }
    Serial.println("Ingrese un valor");
    delay(2000);
    */
}
