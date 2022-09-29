void get_data (){
  int number = Serial.read();
  Serial.print(number);

   /*    
  if(Serial.available() > 0){

  }
    Serial.println("Ingrese un valor");
    delay(2000);
    */
}

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
  uint64_t utCuMp = pow(2, n - 1)-1;
  int64_t tCuMp = pow(2, n - 1)-1;

  int64_t maxPos[8]{
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

void post_maxNeg (int n, int counter) {
  uint8_t utOcMn = pow(2, n)-1;
  int8_t tOcMn = 0;
    if (n >= 9){
      tOcMn = pow(2, 8)-1;
    } else {
      tOcMn = pow(2, n)-1;
    }
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


void post_min (int n, int counter) {
  uint8_t utOcM = -(pow(2, n-1));
  int8_t tOcM = -(pow(2, n-1));
  uint16_t utSeM = -(pow(2, n-1));
  int16_t tSeM = -(pow(2, n-1));
  uint32_t utDoM = -(pow(2, n-1));
  int32_t tDoM = -(pow(2, n-1));
  uint64_t utCuM = -(pow(2, n-1));
  int64_t tCuM = -(pow(2, n-1));

  int64_t Min[8]{
    utOcM, 
    tOcM,
    utSeM, 
    tSeM, 
    utDoM, 
    tDoM,
    utCuM,
    tCuM  
  };
 /* 
Serial.println("--------- uint8_t");
Serial.println(Min[0]);
Serial.println(Min[1]);
Serial.println(Min[2]);
Serial.println(Min[3]);
Serial.println(Min[4]);
Serial.println(Min[5]);
Serial.println(Min[6]);
Serial.println(Min[7]);
  */
  Serial.print("Rango mínimo: ");
  Serial.println(Min[counter]);
}

void get_infoVar (int counter){
   String infoVar[8]{
    "uint8_t", 
    "int8_t",
    "uint16_t", 
    "int16_t", 
    "uint32_t", 
    "int32_t",
    "uint64_t",
    "int64_t"  
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
