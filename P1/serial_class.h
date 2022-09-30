class serial_class {

 //Funciones que podrán ser llamadas fuera de la clase
public:

  void get_data(int number, int counter){ 
    if (Serial.available() > 0){ //Revisa si hay algún dato guardado que pueda utilizar 
      String command = Serial.readStringUntil('\n'); //Revisa el string ingresado e ignora el salto de línea
      number = command.toInt(); //Convierte el string en un int
        for(int i = 0; i <= 3; i++){ //Se ejecutan todas las funciones con un numero diferente del contador en cada iteración
         post_data(number, counter);
         counter++;
        }
    } else {
      Serial.println("INGRESA UN NÚMERO"); //Si no recibe nada entonces pedirá el ingreso de un número
      delay(3000);
    }

}

//Funciones que no podrán ser llamadas fuera de las clases
private:

//Entero negativo sin signo
void post_maxNeg (int n, int counter) {
  uint8_t utOcMn = pow(2, n)-1; //Se ejecuta las funciones y se guardan en un tipo de variable específico
  uint16_t utSeMn = pow(2, n)-1;
  uint32_t utDoMn = pow(2, n)-1;
  uint64_t utCuMn = pow(2, n)-1;

  uint64_t maxNeg[4]{ //Se guardan las variables creadas dentro de un array 
    utOcMn, 
    utSeMn, 
    utDoMn, 
    utCuMn,
  };

  Serial.print("Rango máximo: ");
  Serial.println(maxNeg[counter]); //Se imprime la variable que se encuentra en la posición especificada por el counter
}

//Entero positivo con signo
void post_maxPos (int n, int counter) {
  
  int8_t tOcMp = 0;//Se ejecuta las funciones y se guardan en un tipo de variable específico
  //Como su contenido rebasa su limite entonces se coloca una condición para que solo entregue su limite 
    if (n >= 9){
      tOcMp = pow(2, 8 - 1)-1;
    } else {
      tOcMp = pow(2, n - 1)-1;
    }
  int16_t tSeMp = 0;
    if (n >= 17){
      tSeMp = pow(2, 16 - 1)-1;
    } else {
      tSeMp = pow(2, n - 1)-1;
    }
  int32_t tDoMp = pow(2, n - 1)-1;
  int64_t tCuMp = pow(2, n - 1)-1;

  uint64_t maxPos[8]{ //Se guardan las variables creadas dentro de un array 
  tOcMp,
  tSeMp, 
  tDoMp,
  tCuMp  
  };

  Serial.print("Rango máximo: ");
  Serial.println(maxPos[counter]); //Se imprime la variable que se encuentra en la posición especificada por el counter
}

void get_min (int n, int counter) {
  int8_t tOcM = 0; //Se ejecuta las funciones y se guardan en un tipo de variable específico
  //Como su contenido rebasa su limite entonces se coloca una condición para que solo entregue su limite 
    if (n >= 8){
      tOcM = -(pow(2, 8-1));
    } else {
      tOcM = -(pow(2, n-1));
    }
  int16_t tSeM = 0;
    if (n >= 8){
      tSeM = -(pow(2, 16-1));
    } else {
      tSeM = -(pow(2, n-1));
    }
  int32_t tDoM = -(pow(2, n-1));
  int64_t tCuM = -(pow(2, n-1));

  int64_t Min[4]{ //Se guardan las variables creadas dentro de un array 
    tOcM,
    tSeM, 
    tDoM,
    tCuM  
  };
 
  Serial.print("Rango mínimo: ");
  Serial.println(Min[counter]); //Se imprime la variable que se encuentra en la posición especificada por el counter
}

//bits utilizados por variable
void get_infoVar (int counter){
   String infoVar[4]{
    "8 bits", 
    "16 bits", 
    "32 bits", 
    "64 bits"  
  };

  Serial.print("-----Utilizando variables de tipo ");
  Serial.print(infoVar[counter]);
  Serial.println("-----");
}

void get_max (int s, int n, int counter) { //Permite ver que función ejecutar dependiendo de la variable s
    if(s == 1){
      post_maxPos(n, counter);
    } else {
      post_maxNeg(n, counter);
    }
}
/*
void get_min (int n, int counter) {
      post_min(n, counter);
}*/

void post_data(int num, int counter){ //Organización de los resultados de todas las funciones 
        get_infoVar(counter);
      Serial.print("");
      Serial.print("Entero sin signo de ");
      Serial.print(num);
      Serial.println(" bits");
      Serial.println("");
        get_max(0, num, counter);
      Serial.println("Rango mínimo: 0");
      Serial.println("");
      Serial.println("");
      Serial.print("Entero con signo de ");
      Serial.print(num);
      Serial.println(" bits");
      Serial.println("");
        get_max(1, num, counter);
        get_min(num, counter);
      Serial.println("");
}

};
