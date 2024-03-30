int find_int(char *input, char search){
  char output[100];
  int o = 0;
  int len = strlen(input);
  for(int i = 0; i<len; i++){
    if (input[i] == '-'){
      if (input[i+1] == search){
        for(int n = i+1; n<len; n++){
          if ((input[n] == '\0') || (input[n] == ' ')){
              const char *outer = output;
              return(atoi(outer));
          }
          output[o] = input[n+1];
          o++;
        }
        const char *outer = output;
        return(atoi(outer));
      }  
    }
  }
  return(0);
}

void find_str(char *input, char search, char *output){
  char temp[100];
  int o = 0;
  int len = strlen(input);
  for(int i = 0; i<len; i++){
    if (input[i] == '-'){
      if (input[i+1] == search){
        for(int n = i+1; n<len; n++){
          if ((input[n] == '\0') || (input[n] == ' ')){

              Serial.println(temp);
              //return(outer);
              //*output = temp;
              //sprintf(output, temp);
          }
          temp[o] = input[n+1];
          o++;
        }
        //Serial.println(temp);
        //return(outer);
        //*output = temp;
        sprintf(output, temp);
      }  
    }
  }
}

int intlen(unsigned x) {
    if (x >= 1000000000) return 10;
    if (x >= 100000000)  return 9;
    if (x >= 10000000)   return 8;
    if (x >= 1000000)    return 7;
    if (x >= 100000)     return 6;
    if (x >= 10000)      return 5;
    if (x >= 1000)       return 4;
    if (x >= 100)        return 3;
    if (x >= 10)         return 2;
    return 1;
}

void jointnstr(char *str1, char *str2, int n){
  int j = 0;
  for(int i = strlen(str1); i<n; i++){
    if(j<strlen(str2)){
      str1[i] = str2[j];
      j++;  
    }
  }
}
