#include "serial_class.h"

int n = 0; //Receptor del read
int counter = 0; //Contador para los arrays

serial_class calculadora;

void setup( void ) {

  Serial.begin ( 115200 ); // Configuración BaudRate, un sistema puede tener varios puertos seriales físicos.
  
}

void loop ( void ) {
 calculadora.get_data(n, counter); //Se manda llamar el get_data que será el encargado de ejecutar todas las funciones
}
