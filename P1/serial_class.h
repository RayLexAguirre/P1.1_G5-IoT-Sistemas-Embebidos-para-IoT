class serial_class {

 // Function can be called
public:

  void get_data(int number, int counter){
    if (Serial.available() > 0){
      String command = Serial.readStringUntil('\n');                // read string until newline character
      number = command.toInt();
      counter++;
      Serial.println(number);
      Serial.println(counter);
      Serial.println("ciclo");
      for(int i = 1; i <= 8; i++)
      {
       counter++;
       Serial.println(counter);
      }
    } else {
      Serial.println("INGRESA UN NÚMERO");
      delay(3000);
    }

}

// Functions that only can be called inside the class
private:

//Entero negativo sin signo
void post_maxNeg (int n, int counter) {
  uint8_t utOcMn = pow(2, n)-1;
  uint16_t utSeMn = pow(2, n)-1;
  int16_t tSeMn = 0;
    if (n >= 17){
      tSeMn = pow(2, 16)-1;
    } else {
      tSeMn = pow(2, n)-1;
    }
  uint32_t utDoMn = pow(2, n)-1;
  int32_t tDoMn = pow(2, n)-1;
  uint64_t utCuMn = pow(2, n)-1;
  int64_t tCuMn = pow(2, n)-1;

  uint64_t maxNeg[8]{
    utOcMn, 
    tOcMn,
    utSeMn, 
    tSeMn, 
    utDoMn, 
    tDoMn,
    utCuMn,
    tCuMn  
  };

  Serial.print("Rango máximo: ");
  Serial.println(maxNeg[counter]);
}

//Entero positivo con signo
void post_maxPos (int n, int counter) {
  
  uint8_t utOcMp = pow(2, n - 1)-1;
  int8_t tOcMp = 0;
    if (n >= 9){
      tOcMp = pow(2, 8 - 1)-1;
    } else {
      tOcMp = pow(2, n - 1)-1;
    }
  uint16_t utSeMp = pow(2, n - 1)-1;
  int16_t tSeMp = 0;
    if (n >= 17){
      tSeMp = pow(2, 16 - 1)-1;
    } else {
      tSeMp = pow(2, n - 1)-1;
    }
  uint32_t utDoMp = pow(2, n - 1)-1;
  int32_t tDoMp = pow(2, n - 1)-1;
  uint64_t utCuMp = pow(2, 64 - 1)-1;
  int64_t tCuMp = pow(2, n - 1)-1;

  uint64_t maxPos[8]{
  utOcMp, 
  tOcMp,
  utSeMp, 
  tSeMp, 
  utDoMp, 
  tDoMp,
  utCuMp,
  tCuMp  
  };

  Serial.print("Rango máximo: ");
  Serial.println(maxPos[counter]);
}

void post_min (int n, int counter) {
  int8_t tOcM = 0;
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

  int64_t Min[4]{
    tOcM,
    tSeM, 
    tDoM,
    tCuM  
  };
 
  Serial.print("Rango mínimo: ");
  Serial.println(Min[counter]);
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

void get_max (int s, int n, int counter) {
    if(s == 1){
      post_maxPos(n, counter);
    } else {
      post_maxNeg(n, counter);
    }
}

void get_min (int n, int counter) {
      post_min(n, counter);
}

void post_data(int num, int counter){
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
